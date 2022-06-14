

#include <Servo.h>

int motor1 = 4; 
int motor2 = 6;
int motor3 = 8;
int motor4 = 10;


Servo m1; //Define variables for each motor
Servo m2;
Servo m3;
Servo m4;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor1,OUTPUT);  //Both motor pins are sending a signal out to the VEX motor controller
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(13,OUTPUT);
  
  m1.attach(motor1); //These lines tell the Arduino to send signals to the pins identified above to control the motor variables 
  m2.attach(motor2);
  m3.attach(motor3);
  m4.attach(motor4);

  motorControl(-25, m1);
  motorControl(25, m2);
  motorControl(25, m3);
  motorControl(-25, m4);
  digitalWrite(13,HIGH); //Turn the LED on pin 13 on
  delay(4400); //Wait 1000 ms, or one second

  motorControl(0, m1);
  motorControl(0, m2);
  motorControl(0, m3);
  motorControl(0, m4);

}
void loop() {
  // put your main code here, to run repeatedly:

  //Send full forward to both motors
  //leftMotorControl(100);
  //rightMotorControl(100);
  motorControl(25, m1);
  motorControl(-25, m2);
  motorControl(-25, m3);
  motorControl(25, m4);
  
  digitalWrite(13,HIGH); //Turn the LED on pin 13 on
  delay(4200); //Wait 1000 ms, or one second

  //Send full backward to both motors
  motorControl(-25, m1);
  motorControl(25, m2);
  motorControl(25, m3);
  motorControl(-25, m4);
  digitalWrite(13,LOW); //Turn the LED on pin 13 off
  delay(4200);
  
}

//The functions below let you send a power value between -100 and 100 to the motors. 
//The servo library uses numbers between 1000 and 2000 to control servos. 

int leftMotorControl(int value){

m1.write(map(value,-100,100,1000,2000));

}

int rightMotorControl(int value){

m2.write(map(value,-100,100,1000,2000));

}

int motorControl(int value, Servo m){

m.write(map(value,-100,100,1000,2000));

}
