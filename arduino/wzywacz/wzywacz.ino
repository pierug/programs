#include <Arduino.h>
#include <ESP8266_TCP.h>
#include "HAL.h"



ESP8266_TCP wifi;

// Target Access Point
String ssid        = "pracaMagisterska";
String pass        = "polonez1";

// Connect this pin to CH_PD pin on ESP8266
#define PIN_RESET    6

const String STATIC_ID= "192.168.42.9";
const String HOST = "192.168.0.3";
const String GET = "GET /easy_hospital/udpCall.php?";
const String GetPatientID  = "pi=";
const String GetStatus = "&st=";

char bufor [100];

Timers t;
String message;

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

void sendRequest(String patientID, String patientStatus){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += HOST;
  cmd += "\",80";
  
  wyslij(cmd,"OK");
  String url = GET;
  url += GetPatientID + patientID;
  url += GetStatus + patientStatus;
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

  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), int0, LOW);
  pinMode(interruptPin3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), int1, LOW);

  Serial.begin(115200);
  wifi.begin(&Serial, PIN_RESET); 
  if(wifi.test()) 
  {
    initSendToServer();
    //initGetFromTablet();
  }
  t.init();
}

volatile bool sendReq = false;

String getPatientID(){
 /* String pID = "ERROR";
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
  return pID;*/
}
volatile uint8_t patStatus=0;

void loop() {
  if(sendReq){
    //initSendToServer();
    String pS;
    if(patStatus==1){
      pS = "RED";
      sendRequest("2",pS);
    } else if(patStatus==2){
      pS = "GREEN";
      sendRequest("2",pS);
    }
    
    sendReq = false;  
    //initGetFromTablet();
    patStatus = 0;
  }
  if(getMessage()){
    //patientID = getPatientID();
    wyslij("AT+CIPCLOSE","OK");
  }
}

void int0() {
  patStatus = 1;
  sendReq = true;
}

void int1() {
  patStatus = 2;
  sendReq = true;
}

String connectAP(){
  String ip = "0.0.0.0";
  while(ip.equals("0.0.0.0")){
    ip = wifi.connectAccessPoint(ssid, pass);
    if(!ip.equals("0.0.0.0")){
      break;
    } 
  }
  return ip;
}

ISR(TIMER0_COMPA_vect){
  if(t0>0)
    t0--;
}

