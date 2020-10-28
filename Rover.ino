#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 
int flag = 4; 
int prevFlag = flag;
int power = 4;
const int leftForward = 8; 
const int leftBackward = 9; 
const int rightForward = 10; 
const int rightBackward = 11;
void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(leftForward, OUTPUT); 
 pinMode(leftBackward, OUTPUT); 
 pinMode(leftForward, OUTPUT); 
 pinMode(rightBackward, OUTPUT); 
 pinMode(power, OUTPUT); 
 digitalWrite(power, HIGH);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
 if (MyBlue.available()) 
{
   Serial.println(flag);
   flag = MyBlue.read(); 
   Serial.println(flag);
}

 if (flag == '0') 
 { 
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
   delay(1000);
 } 
 else if (flag == '1') 
 { 
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , LOW);
  digitalWrite(rightBackward , HIGH);
   delay(1000);
   Serial.println("2");
 } 
 else if (flag == '2') 
 { 
  digitalWrite(leftForward , LOW);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
   delay(1000);
 } 
 else if (flag == '3') 
 { 
  digitalWrite(leftForward , LOW);
  digitalWrite(leftBackward , HIGH);
  digitalWrite(rightForward , LOW);
  digitalWrite(rightBackward , HIGH);
   delay(1000);
 } 
 else{
  
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
   delay(1000);
 }
}  
