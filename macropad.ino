#include <Wire.h>
#include <Adafruit_NeoPixel.h>

//Board pin numbers and other variables
char col1 = 1;
char col2 = 1;
char col3 = 1;
char col4 = 1;
char col5 = 1;

char row1 = 1;
char row2 = 1;
char row3 = 1;
char row4 = 1;
char row5 = 1;

int roy = 0;
int gee = 0;
int bee = 0;

int fadeSpeed = 5;
int fadeInterval = 1;
char button = 2;
int key = 0;

char pixel_pin = 3;
char btm_pixel_pin = 4;
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, pixel_pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel btm_pixel = Adafruit_NeoPixel(1, btm_pixel_pin, NEO_GRB + NEO_KHZ800);

//Some premade colors UwU (in RGB)
int purple[3] = {255,0,255};
int yellow[3] = {255,255,0};
int teal[3] = {0,255,255};
int red[3] = {255,0,0};
int green[3] = {0,255,0};
int blue[3] = {0,0,255};

void setup() {
  pinMode(button, INPUT);
  pixel.begin();
  pixel.clear();
  pixel.setPixelColor(0,pixel.Color(255,0,255));
  pixel.show();
}

void loop() {
  //this is bad, ineffecient, stupid code. but hey its a keyboard scanner so i have licence to not care in the slightest
  digitalWrite(col1, HIGH);
  if(digitalRead(row1) == true) {key=1;}
  else if(digitalRead(row2) == true) {key=2;}
  else if(digitalRead(row3) == true) {key=3;}
  else if(digitalRead(row4) == true) {key=4;}
  else if(digitalRead(row5) == true) {key=5;}
  digitalWrite(col1, LOW);

  digitalWrite(col2, HIGH);
  if(digitalRead(row1) == true) {key=6;}
  else if(digitalRead(row2) == true) {key=7;}
  else if(digitalRead(row3) == true) {key=8;}
  else if(digitalRead(row4) == true) {key=9;}
  else if(digitalRead(row5) == true) {key=10;}
  digitalWrite(col2, LOW);

  digitalWrite(col3, HIGH);
  if(digitalRead(row1) == true) {key=11;}
  else if(digitalRead(row2) == true) {key=12;}
  else if(digitalRead(row3) == true) {key=13;}
  else if(digitalRead(row4) == true) {key=14;}
  else if(digitalRead(row5) == true) {key=15;}
  digitalWrite(col3, LOW);

  digitalWrite(col4, HIGH);
  if(digitalRead(row1) == true) {key=16;}
  else if(digitalRead(row2) == true) {key=17;}
  else if(digitalRead(row3) == true) {key=18;}
  else if(digitalRead(row4) == true) {key=19;}
  else if(digitalRead(row5) == true) {key=20;}
  digitalWrite(col4, LOW);

  digitalWrite(col5, HIGH);
  if(digitalRead(row1) == true) {key=21;}
  else if(digitalRead(row2) == true) {key=22;}
  else if(digitalRead(row3) == true) {key=23;}
  else if(digitalRead(row4) == true) {key=24;}
  else if(digitalRead(row5) == true) {key=25;}
  digitalWrite(col5, LOW);


  
  //fade in and out mech key led
  if(digitalRead(button) == true) {
    pixel.setPixelColor(0,pixel.Color(purple[0],purple[1],purple[2]));
    pixel.show();
    roy = random(0,255);
    gee = random(0,255);
    bee = random(0,255);
  } else {
    while(digitalRead(button) == false) {
      roy = roy+fadeInterval;
      gee = gee+fadeInterval;
      bee = bee+fadeInterval;
      pixel.setPixelColor(0,pixel.Color(roy,gee,bee));
      pixel.show();
      btm_pixel.setPixelColor(0,pixel.Color(roy,gee,bee));
      btm_pixel.show();
      if (roy <=0 || roy>=255) {
        fadeInterval = -fadeInterval;
      }
      if (gee <=0 || gee>=255) {
        fadeInterval = -fadeInterval;
      }
      if (bee <=0 || bee>=255) {
        fadeInterval = -fadeInterval;
      }
      delay(fadeSpeed);
    }
  }
  if(key != 0) {
    pixel.setPixelColor(key-1,pixel.Color(purple[0],purple[1],purple[2]));
  } else {
    pixel.setPixelColor(key-1,pixel.Color(255,255,255));
  }
  //reset key to avoid double exec
  key=0;
}
