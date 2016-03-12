//Libraries
#include <math.h>
#include <Wire.h>
#include <rgb_lcd.h>

//Alias for LCD Device
rgb_lcd lcd;

//Led port
int led = 2;   

int sensorData;     //Senseor value
float temperature;  //Result
int B=3975;         //B value of the thermistor
float resistance;   //Resistance of the sensor value

//Setup rotine
void setup() {
  //Init lcd
  lcd.begin(16, 2);
  //No lcd cursor blink 
  lcd.noBlink();
  //Set color
  lcd.setRGB(0,128,64);    
  //First message
  lcd.print("Monitor");
  //Led port to output mode
  pinMode(led, OUTPUT);   
  //Wait
  delay(100);
}

//Loop rotine
void loop() {
  //Sensor value
  sensorData=analogRead(0);
  //Resistence calc
  resistance=(float)(1023-sensorData)*10000/sensorData;
  //Temperature calc by datasheet
  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
  //Set lcd cursor
  lcd.setCursor(0, 1);
  //Set temperature message
  lcd.print(temperature);
  //Define led state to high
  digitalWrite(led, HIGH);
  //Wait for 100 miliseconds
  delay(100);  
  //Define led state to low
  digitalWrite(led, LOW);
  //Wait for 900 seconds
  delay(900);  
}
