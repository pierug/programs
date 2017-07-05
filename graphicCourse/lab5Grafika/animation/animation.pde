

void setup() {
  size(600, 600);
  background(255);
  fill(150);
  stroke(0);
}
void koniczynka(int x, int y, int R, float s){
  pushMatrix();
  translate(x,y);
  rotate(radians(R));
  scale(s);
  lisc(0);
  lisc(90);
  lisc(180);
  lisc(270);
  popMatrix();
}
void lisc(int r){
  pushMatrix();
  rotate(radians(r));
  beginShape();
  curveVertex(10, 10); // pierwszy punkt kontrolny
  curveVertex(10, 10); // pierwszy punkt krzywej
  curveVertex(100, 15);
  curveVertex(100, 50);
  curveVertex(60, 60);
  curveVertex(50, 100);
  curveVertex(15, 100);
  curveVertex(10, 10); // ostatni punkt krzywej
  curveVertex(10, 10); // ostatni punkt kontrolny
  endShape(CLOSE);
  popMatrix();
}
int lastTime = 0;
int radiansFirst = 360;
int radiansSec = 0;
void draw()
{
  int currentTime = millis();

  if (currentTime > lastTime+200) {
    fill(random(255),random(255),random(255));
    
    
    koniczynka(200, 200, radiansFirst--, 1);
    
    koniczynka(200, 200, radiansSec++, 0.5);
    if(radiansSec>=360){
       radiansSec=0; 
    }
    lastTime = currentTime;
  }
}