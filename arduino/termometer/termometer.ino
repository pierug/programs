#include <dht.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SparkFunMLX90614.h>
#include <ESP8266_TCP.h>
#include "HAL.h"



ESP8266_TCP wifi;
#define DHTPIN 4 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Target Access Point
String ssid        = "pracaMagisterska";
String pass        = "polonez1";

// Connect this pin to CH_PD pin on ESP8266
#define PIN_RESET    6

const String STATIC_ID= "192.168.42.8";
const String HOST = "192.168.0.3";
const String closeCommunication = " HTTP/1.0\r\nHost: " + HOST +"\r\n" + "Connection: close\r\n\r\n";
const String GET = "GET /easy_hospital/upTemp.php?";
const String GetPatientID  = "pi=";
const String GetPatientTemperature  = "&pt=";
const String GetAmbientTemperature  = "&at=";
const String GetHumidity  = "&h=";
const String msgPatID = ":MSG:PATID:";
char bufor [100];

#define LCD_RS     10
#define LCD_RW     9
#define LCD_EN     11
#define LCD_D4     12
#define LCD_D5     13
#define LCD_D6     7
#define LCD_D7     8
#define LCD_CHARS  16
#define LCD_LINES  2

LiquidCrystal lcd(LCD_RS,
#if LCD_RW >= 0 // RW is not necessary if lcd is on dedicated pins
LCD_RW,
#endif
LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7
);
Timers t;
String message;

void printfLcd(String s){
  static int i=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(s);
}

void printfLcd(String s1,String s2){
  static int i=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(s1);
  lcd.setCursor(0,1);
  lcd.print(s2);
}

volatile unsigned long t0 = 0;
#define TIMEOUT 5000

boolean wyslij(String Komenda_AT, char *Odpowiedz_AT){
  Serial.println(Komenda_AT);
  t0=TIMEOUT;
  while(t0){
   if(Serial.available()>0){
        if(Serial.find(Odpowiedz_AT)) 
          return 1;    
    }  
  } 
  return 0;
}
void sendRequest(String patientID, String patient_temperature, String ambient_temperature, String humidity){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += HOST;
  cmd += "\",80";
  
  wyslij(cmd,"OK");
  String url = GET;
  url += GetPatientID + patientID;
  url += GetPatientTemperature + patient_temperature;
  url += GetAmbientTemperature + ambient_temperature;
  url += GetHumidity + humidity;
  url += "\r\n" ;

  sprintf(bufor,"AT+CIPSEND=%d",url.length());
  delay(10);
  wyslij(bufor,">");
  delay(10);
  wyslij(url,"OK");
  wyslij("AT+CIPCLOSE","OK");
  delay(10);
}

boolean getMessage(){
  int dataState = wifi.isNewDataComing(WIFI_SERVER);
  if(dataState != WIFI_NEW_NONE) {  
    String newData = wifi.getMessage();   
    for (uint8_t i=0;i<newData.length();i++)
    {
      if (newData[i] == ':')
      {
        message = newData.substring(i);
        return true;
      }
    }
  }
  return false;
}

IRTherm therm;
const byte interruptPin2 = 2;
const byte interruptPin3 = 3;
volatile double lastTemperature = 0;
void int0();
void int1();

String connectAP();

void initGetFromTablet(){
    wifi.write("AT+RST");
    wifi.clearBuffer();
    String str = "AT+CIPSTA=\"" + STATIC_ID +  "\"";  
    wifi.write(str);
    delay(500);
    String ip = connectAP();
    wifi.openTCPServer(2000, 30); 
    wyslij("AT+CIPCLOSE","OK");
}

void initSendToServer(){
    wifi.write("AT+RST");
    wifi.clearBuffer();
    String str = "AT+CIPSTA=\"" + STATIC_ID +  "\"";  
    wifi.write(str);
    delay(500);
    wyslij("AT+CWJAP=\"pracaMagisterska\",\"polonez1\"","OK");
    wifi.openTCPServer(2000, 30); 
    wyslij("AT+CIPCLOSE","OK");
}

void setup() {
  dht.begin();
  therm.begin();
  therm.setUnit(TEMP_C); 
  therm.setEmissivity(0.98);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), int0, LOW);
  pinMode(interruptPin3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), int1, LOW);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor (0,0);  
  
  lcd.print("Setup Done");
  Serial.begin(115200);
  wifi.begin(&Serial, PIN_RESET); 
  if(wifi.test()) 
  {
    initGetFromTablet();
  }
  t.init();
}



float ambientTemp=0;
float humidity=0;
String patientID="";
void makeMeasure(){
  if (therm.read()){ 
    lastTemperature=therm.object();
  }
  ambientTemp = dht.readTemperature();
  humidity = dht.readHumidity();
}

volatile bool readyToMeasure=false;
volatile bool sendReq = false;
volatile bool measure = false;

String getPatientID(){
  String pID = "ERROR";
  for(int i=0;i<message.length();i++){
    if(message[i] == msgPatID[i]){
      if(i==10){
        for(int j=i+1;j<message.length();j++){
          if(message[j]==':'){
            pID = message.substring(i+1,j);
          }
        }
      }
    }
  }
  return pID;
}

void loop() {
  makeMeasure();
  if(measure){
    //makeMeasure();
    measure = false;
    printfLcd(String(lastTemperature,1)+"LT",String(ambientTemp,1)+"aT "+String(humidity,2)+"H");
  }
  
  if(sendReq&&readyToMeasure){
    initSendToServer();
    sendRequest(patientID,
      String(lastTemperature,1),
      String(ambientTemp,1),
      String(humidity,1));
    sendReq = false;  
    readyToMeasure = false;
    initGetFromTablet();
  }

  if(getMessage()){
    patientID = getPatientID();
    printfLcd("Patient ID: "+ patientID);
    readyToMeasure=true;
    wyslij("AT+CIPCLOSE","OK");
  }
}

void int0() {
  sendReq = true;
}

void int1() {
  measure = true;
}

String connectAP() 
{
  String ip = "0.0.0.0";
  while(ip.equals("0.0.0.0")) 
  {
    ip = wifi.connectAccessPoint(ssid, pass);
    if(!ip.equals("0.0.0.0")) 
    {
      break;
    } 
  }
  
  return ip;
}

ISR(TIMER0_COMPA_vect)
{
  if(t0>0)
    t0--;
}






