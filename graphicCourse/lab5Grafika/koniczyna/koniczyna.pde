size(300, 300);
fill(0, 230, 0);
smooth();
stroke(0);
translate(150,150);
for(int i=0;i<3;i++){
  beginShape();
  rotate(radians(30));
  scale(0.8);
  curveVertex(10, 10); // pierwszy liść
  curveVertex(10, 10);
  curveVertex(100, 15);
  curveVertex(100, 50);
  curveVertex(60, 60);
  curveVertex(50, 100);
  curveVertex(15, 100);
  curveVertex(10, 10);
  curveVertex(10, 10);
  endShape(CLOSE);
  pushMatrix();
  rotate(radians(90));
  beginShape();
  curveVertex(10, 10); // drugi liść
  curveVertex(10, 10); // obrócony o 90 stopni
  curveVertex(100, 15);
  curveVertex(100, 50);
  curveVertex(60, 60);
  curveVertex(50, 100);
  curveVertex(15, 100);
  curveVertex(10, 10);
  curveVertex(10, 10);
  endShape(CLOSE);
  popMatrix();
  pushMatrix();
  rotate(radians(180));
  beginShape();
  curveVertex(10, 10); // trzeci liść
  curveVertex(10, 10); // obrócony o 180 stopni
  curveVertex(100, 15);
  curveVertex(100, 50);
  curveVertex(60, 60);
  curveVertex(50, 100);
  curveVertex(15, 100);
  curveVertex(10, 10);
  curveVertex(10, 10);
  endShape(CLOSE);
  popMatrix();
  pushMatrix();
  rotate(radians(270));
  beginShape();
  curveVertex(10, 10); // czwarty liść
  curveVertex(10, 10); // obrócony o 270 stopni
  curveVertex(100, 15);
  curveVertex(100, 50);
  curveVertex(60, 60);
  curveVertex(50, 100);
  curveVertex(15, 100);
  curveVertex(10, 10);
  curveVertex(10, 10);
  endShape(CLOSE);
  popMatrix();
}