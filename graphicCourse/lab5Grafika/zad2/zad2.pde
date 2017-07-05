size(700,700);

/*
fill(random(255), random(255), random(255));
stroke(255,0,0);

beginShape();

vertex(10,10);
vertex(40,10);
vertex(58,28);
vertex(58,68);
vertex(40,86);
vertex(10,86);
vertex(-8,68);
vertex(-8,28);

translate(200,200);

endShape(CLOSE);
*/


stroke(255,0,0);

for(int i=0;i<4;i++){
  for(int j=0;j<4;j++){
    fill(random(255), random(255), random(255));
    
    beginShape();
    vertex(50+random(5),50+random(5));
    vertex(100+random(5),50+random(5));
    vertex(100+random(5),100+random(5));
    vertex(50+random(5),100+random(5));
    translate(80,0);
    endShape(CLOSE);
  }
  translate(-80*4,80);
}