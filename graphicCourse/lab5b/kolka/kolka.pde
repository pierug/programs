
void rysujKolo(float x, float y, float promien, int min) {
  ellipse(x, y, promien, promien);
  if(promien > min) {
    rysujKolo(x + promien/2, y, promien/2, min);
    rysujKolo(x - promien/2, y, promien/2, min);
    rysujKolo(x, y + promien/2, promien/2, min);
    rysujKolo(x, y - promien/2, promien/2, min);
  }
}

void rysujFraktal(float x, float y, float promien, int min, int wersja) {
  ellipse(x, y, promien, promien);
  switch (wersja){
     case 2:{
      if(promien > min) {
          rysujFraktal(x + promien/2, y, promien/2, min,wersja);
          rysujFraktal(x - promien/2, y, promien/2, min,wersja);

        }
        break;
     }
     case 4:{
      if(promien > min) {
          rysujFraktal(x + promien/2, y, promien/2, min,wersja);
          rysujFraktal(x - promien/2, y, promien/2, min,wersja);
          rysujFraktal(x, y + promien/2, promien/2, min,wersja);
          rysujFraktal(x, y - promien/2, promien/2, min,wersja);
        }
        break;
     }
     case 8:{
      if(promien > min) {
          rysujFraktal(x + promien/2, y, promien/2, min,wersja);
          rysujFraktal(x - promien/2, y, promien/2, min,wersja);
          rysujFraktal(x, y + promien/2, promien/2, min,wersja);
          rysujFraktal(x, y - promien/2, promien/2, min,wersja);
          
          rysujFraktal(x + cos(radians(45)) * promien/2, y + sin(radians(45)) * promien/2, promien/2, min,wersja);
          rysujFraktal(x - cos(radians(45)) * promien/2, y - sin(radians(45)) * promien/2, promien/2, min,wersja);
          rysujFraktal(x - cos(radians(45)) * promien/2, y + sin(radians(45)) * promien/2, promien/2, min,wersja);
          rysujFraktal(x + cos(radians(45)) * promien/2, y - sin(radians(45)) * promien/2, promien/2, min,wersja);
        }
        break;
     }
  }
}

void setup() {
  size(600, 600);
  background(255);
  fill(255);
  stroke(0);
}

void draw()
{

  rysujFraktal(300, 300, 300,10,8);
}