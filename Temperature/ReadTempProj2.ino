//Libraries
#include <math.h>
#include <Wire.h>
#include <rgb_lcd.h>

//Alias for LCD Device
rgb_lcd lcd;

//Led port
int ledGreen = 2;   
int ledRed = 6;

//Buzzer port
int buzzer = 4;

int sensorData;             //Senseor value
float temperature;          //Result
float temperatureMin  = 0;  //Result
float temperatureMax  = 0;  //Result
int B=3975;                 //B value of the thermistor
float resistance;           //Resistance of the sensor value

//Setup rotine
void setup() {
  //Init lcd
  lcd.begin(16, 2);
  //No lcd cursor blink 
  lcd.noBlink();
  //Set color
  lcd.setRGB(157,70,164);    
  //First message
  lcd.print("Monitor: 00.00C");
  //Define cursor position
  lcd.setCursor(0, 1);
  //Message
  lcd.print("LV: 00.00 00.00");
  //Led port to output mode
  pinMode(ledGreen, OUTPUT);   
  //Led port to output mode
  pinMode(ledRed, OUTPUT);   
  //Buzzer port to output mode
  pinMode(buzzer, OUTPUT);   
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
  //Verify
  if((temperatureMin == 0) || (temperature< temperatureMin)){
    //Set value
    temperatureMin = temperature;
  }
  //Verify
  if((temperatureMin == 0) || (temperature > temperatureMax)){
    //Set value
    temperatureMax = temperature;
  }
  
  //Set lcd cursor
  lcd.setCursor(9, 0);
  //Set temperature message
  lcd.print(temperature);
  //Set lcd cursor
  lcd.setCursor(4, 1);
  //Set temperature message
  lcd.print(temperatureMin);
  //Set lcd cursor
  lcd.setCursor(10, 1);
  //Set temperature message
  lcd.print(temperatureMax);
  //Define led state to high
  digitalWrite(ledGreen, HIGH);
  //Verify if need start buzzer
  if(temperature >= 30){
    //Define buzzer state to high
    digitalWrite(buzzer, HIGH);
    //Define led red state to high
    digitalWrite(ledRed, HIGH);
    //Wait for 100 miliseconds
    delay(25);  
    //Define buzzer state to high
    digitalWrite(buzzer, LOW);    
    //Wait for 100 miliseconds
    delay(25);  
    //Define buzzer state to high
    digitalWrite(buzzer, HIGH);
    //Wait for 100 miliseconds
    delay(50);  
    //Define buzzer state to high
    digitalWrite(buzzer, LOW);    
    //Wait for 100 miliseconds
    delay(50);  
    //Define buzzer state to high
    digitalWrite(buzzer, HIGH);
    //Wait for 100 miliseconds
    delay(120);  
    //Define buzzer state to high
    digitalWrite(buzzer, LOW);    
    //Define led red state to low
    digitalWrite(ledRed, LOW);
  }else{
    //Define buzzer state to high
    digitalWrite(buzzer, LOW);
    //Define led red state to low
    digitalWrite(ledRed, LOW);    
  }
  //Wait for 100 miliseconds
  delay(100);  
  //Define led state to low
  digitalWrite(ledGreen, LOW);
  //Wait for 900 seconds
  delay(900);  
}
