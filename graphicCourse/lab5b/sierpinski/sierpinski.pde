void TrojkatS(int poziom, int maxPoziom, PVector lewy,PVector gora, PVector prawy)
{
  poziom++;
  
  if(poziom >= maxPoziom) {
    
    triangle(lewy.x, lewy.y, gora.x, gora.y, prawy.x,prawy.y);
    
  }
  else {
    fill(random(255),random(255),random(255));
    //fill(255/poziom);
    PVector a = PVector.add(lewy,PVector.div(PVector.sub(gora, lewy), 2));
    PVector b = PVector.add(prawy,PVector.div(PVector.sub(gora, prawy), 2));
    PVector c = PVector.add(lewy,PVector.div(PVector.sub(prawy, lewy), 2));
    TrojkatS(poziom, maxPoziom, a, gora, b);
    TrojkatS(poziom, maxPoziom, lewy, a, c);
    TrojkatS(poziom, maxPoziom, c, b, prawy);
  }
}


void setup() {
  size(600, 600);
  background(255);
  fill(random(255),random(255),random(255));
  stroke(0);
  
  PVector lewy = new PVector(400,400);
  PVector prawy = new PVector(200,400);
  PVector gora = new PVector(300,200);
  TrojkatS( 0,  5, lewy,gora, prawy);
}

void draw()
{
  
}