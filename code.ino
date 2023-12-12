#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int sensorPin = A0; // choose the input pin (for GAS sensor)  
int buzzer = 10; // choose the pin for the Buzzer
int G_led = 8; // choose the pin for the Green LED
int R_led = 9; // choose the pin for the Red Led


int read_value; // variable for reading the gaspin status
int set = 300;  // we start, assuming Smoke detected

void setup(){ 
pinMode(sensorPin, INPUT); // declare sensor as input

lcd.init();
lcd.backlight();
pinMode(buzzer,OUTPUT); // declare Buzzer as output 
pinMode(R_led,OUTPUT); // declare Red LED as output
pinMode(G_led,OUTPUT); // declare Green LED as output
pinMode(A1,INPUT);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("   WELCOME To   ");
lcd.setCursor(0,1);
lcd.print("  GAS Detector  ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("       BY       ");
lcd.setCursor(0,1);
lcd.print("   ASHNA AZAD   ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("       BY       ");
lcd.setCursor(0,1);
lcd.print("   ASHLY JOSHY   ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("       BY       ");
lcd.setCursor(0,1);
lcd.print("  BIYANKA MANI  ");
delay(2000);
lcd.clear();
Serial.begin(9600);
}

void loop(){
read_value = (analogRead(sensorPin)); // read input value
Serial.println(read_value);
//read_value = read_value - 650;
//if(read_value<0){read_value=0;}

if(read_value<set){ // check if the Smoke variable is High
lcd.setCursor(0, 1);
lcd.print("Alert....!!!    "); 
lcd.setCursor(0, 0);
lcd.print("Gas Level:");
lcd.print(read_value);
lcd.print("  ");   
digitalWrite(buzzer, HIGH); // Turn LED on.  
digitalWrite(R_led, HIGH); // Turn LED on.
digitalWrite(G_led, LOW); // Turn LED off.
delay(1000);
}

if(read_value>set){ // check if the Smoke variable is Low
lcd.setCursor(0, 0);
lcd.print("Gas Level:0     ");
lcd.setCursor(0, 1);
lcd.print(".....Normal.....");  
digitalWrite(buzzer, LOW); // Turn LED on.  
digitalWrite(R_led, LOW); // Turn LED on.
digitalWrite(G_led, HIGH); // Turn LED on.
}
delay(100);
}
