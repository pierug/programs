final float katOdniesienia = radians(45);
float pr=0.5;
float kat = radians(45);
int strokeW = 5;
void setup() {
  size(800, 700);
 
}
void draw() {
  background(255);
  stroke(0);
  translate(width/2,height);
  strokeWeight(5);
  line(0,0,0,-120);
  translate(0,-120);
  konar(120,4,4);
  delay(100);
}
void konar(float h,int w, int ww) {
  h *= 0.66;
  
  if(h>=5){
    stroke(0,158,0);
  }else{
    stroke(100,50,0);
  }
  if (h > 1) {
    if(w==0){
      w=1;
    }
    if(ww==0){
      ww=1;
    }
    strokeWeight(w);

    pushMatrix();
    rotate(katOdniesienia+random(katOdniesienia*pr)*(random(1)-2));
    line(0, 0, 0, -h);
    translate(0, -h);
    konar(h,w-1,ww);
    popMatrix();
    pushMatrix();
    rotate(-(katOdniesienia+random(katOdniesienia*pr)*(random(1)-2)));
    strokeWeight(ww);
    
    line(0, 0, 0, -h);
    translate(0, -h);
    konar(h,w-1,ww-1);
    popMatrix();
  }
}