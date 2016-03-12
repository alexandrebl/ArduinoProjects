//Libraries
#include <Wire.h>
#include <rgb_lcd.h>

//Alias for LCD Device
rgb_lcd lcd;
//Led port
int led = 2;    

//Global variables
byte r = 0;
byte g = 0;
byte b = 0;

//Setup rotine
void setup() {
  //Init LCS
  lcd.begin(16, 2);
  //No lcd cursor blink 
  lcd.noBlink();
  //Set color
  lcd.setRGB(0,128,64);    
  //First message
  lcd.print("LCD 3 - Init App");
  //Led port to output mode
  pinMode(led, OUTPUT);   
  //Wait for one second
  delay(1000);
}

//Loop rotine
void loop() {
  //Led state
  int ledState = LOW;
  
  //Set values
  r += 3 + g;
  g += r * 3 - b;
  b += g * 2 + g;

  //Set color
  lcd.setRGB(r,g,b);

  //Define led state
  if(((r+g+b) % 2) == 0){
    ledState = LOW;
  }else{
    ledState = HIGH;
  }
  
  //Define led state
  digitalWrite(led, ledState);

  //Delay 800 miliseconds
  delay(800);
}
