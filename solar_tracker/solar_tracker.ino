// include the library code:
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
// initialize the library with the numbers of the interface pins
Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Solar setup
int solarPin = 4;
int voltage;
#include <Servo.h> // include Servo library 
// 180 horizontal MAX
Servo horizontal; // horizontal servo
int servoh = 30; // 90; // stand horizontal servo
int servohLimitHigh = 170;
int servohLimitLow = 30;
// 65 degrees MAX
Servo vertical; // vertical servo 
int servov = 100; // 90; // stand vertical servo
int servovLimitHigh = 130;
int servovLimitLow = 90;
// LDR pin connections
// name = analogpin;
int ldrlt = 0; //LDR top left - BOTTOM LEFT <--- BDG
int ldrrt = 1; //LDR top rigt - BOTTOM RIGHT 
int ldrld = 2; //LDR down left - TOP LEFT
int ldrrd = 3; //ldr down rigt - TOP RIGHT
void setup()
{
 // set up the LCD's number of rows and columns: 
 lcd.begin(16, 2);
 Serial.begin(9600);
 // servo connections
// name.attacht(pin);
12
 horizontal.attach(9); 
 vertical.attach(10);
 horizontal.write(30);
 vertical.write(100);
 delay(3000);
}
void loop() 
{
 int lt = analogRead(ldrlt); // top left
 int rt = analogRead(ldrrt); // top right
 int ld = analogRead(ldrld); // down left
 int rd = analogRead(ldrrd); // down rigt
 // int dtime = analogRead(4)/20; // read potentiometers 
 // int tol = analogRead(5)/4;
int dtime = 10;
 int tol = 50;
 int avt = (lt + rt) / 2; // average value top
 int avd = (ld + rd) / 2; // average value down
 int avl = (lt + ld) / 2; // average value left
 int avr = (rt + rd) / 2; // average value right
 int dvert = avt - avd; // check the diffirence of up and down
 int dhoriz = avl - avr;// check the diffirence og left and rigt
 Serial.print(avt);
 Serial.print(" ");
 Serial.print(avd);
 Serial.print(" ");
 Serial.print(avl);
 Serial.print(" ");
 Serial.print(avr);
 Serial.print(" ");
 Serial.print(dtime);
 Serial.print(" ");
 Serial.print(tol);
 Serial.println(" ");
13
 if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical 
angle
 {
if (avt > avd)
 {
 servov = ++servov;
 if (servov > servovLimitHigh) 
{ 
servov = servovLimitHigh;
 }
 }
 else if (avt < avd)
 {
 servov= --servov;
 if (servov < servovLimitLow)
 {
 servov = servovLimitLow;
 }
 }
 vertical.write(servov);
 }
if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change 
horizontal angle
 {
 if (avl > avr)
 {
 servoh = --servoh;
 if (servoh < servohLimitLow)
 {
 servoh = servohLimitLow;
 }
 }
 else if (avl < avr)
14
 {
 servoh = ++servoh;
 if (servoh > servohLimitHigh)
 {
 servoh = servohLimitHigh;
 }
 }
 else if (avl = avr)
 {
 // nothing
 }
 horizontal.write(servoh);
 }
 
delay(dtime);
voltage = map(analogRead(solarPin), 0, 1023, 0, 5000);
 lcd.setCursor(0, 0);
 lcd.print("VOLTAGE (mV):");
 lcd.setCursor(0, 1);
 lcd.print(voltage);
 delay(50);
 lcd.clear();
}
