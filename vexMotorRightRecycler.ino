

#include <Servo.h>

int leftRearMotorPin = 4; //left motor pin
int rightRearMotorPin = 6; //left motor pin
int leftFrontMotorPin = 8; //left motor pin
int rightFrontMotorPin = 10; //left motor pin

Servo leftRearMotor; //Define variables for each motor
Servo rightRearMotor;
Servo leftFrontMotor;
Servo rightFrontMotor;


void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);  //Both motor pins are sending a signal out to the VEX motor controller
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);

  leftRearMotor.attach(leftRearMotorPin); //These lines tell the Arduino to send signals to the pins identified above to control the motor variables 
  rightRearMotor.attach(rightRearMotorPin);
  leftFrontMotor.attach(leftFrontMotorPin); 
  rightFrontMotor.attach(rightFrontMotorPin);

  delay(1000);
  
  //leftRearMotorControl(-25);
  rightRearMotorControl(25);
  //leftFrontMotorControl(-25);
  rightFrontMotorControl(25);
  digitalWrite(13,HIGH); //Turn the LED on pin 13 on
  delay(250); //Wait 250 ms, or one second

  leftRearMotorControl(0);
  rightRearMotorControl(0);
  leftFrontMotorControl(0);
  rightFrontMotorControl(0);
  digitalWrite(13,HIGH); //Turn the LED on pin 13 on
  delay(1000); //Wait 250 ms, or one second
}
void loop() {
  // put your main code here, to run repeatedly:

  //Send full forward to both motors
  leftRearMotorControl(25);
  //rightRearMotorControl(-25);
  leftFrontMotorControl(25);
  //rightFrontMotorControl(-25);
  digitalWrite(13,HIGH); //Turn the LED on pin 13 on
  delay(4000); //Wait 250 ms, or one second

  //Send full backward to both motors
  leftRearMotorControl(-25);
  //rightRearMotorControl(25);
  leftFrontMotorControl(-25);
  //rightFrontMotorControl(25);
  digitalWrite(13,LOW); //T urn the LED on pin 13 off
  delay(4000);
  
}

//The functions below let you send a power value between -25 and 25 to the motors. 
//The servo library uses numbers between 250 and 2000 to control servos. 

int leftRearMotorControl(int value){

leftRearMotor.write(map(value,-25,25,250,2000));

}

int rightRearMotorControl(int value){

rightRearMotor.write(map(value,-25,25,250,2000));

}

int leftFrontMotorControl(int value){

leftFrontMotor.write(map(value,-25,25,250,2000));

}

int rightFrontMotorControl(int value){

rightFrontMotor.write(map(value,-25,25,250,2000));

}
