/*||\\    //||      //\\      ||\\      ||--------    ||\\    \\    //
 *|| \\  // ||     //  \\     ||  \\    ||            || \\    \\  //
 *||  \\//  ||    //----\\    ||    \\  ||            || //     \\//
 *||        ||   //------\\   ||    //  ||----        || \\      ||      ------- SOUMENDRA DEY
 *||        ||  //        \\  ||   //   ||            ||  \\     ||
 *||        || //          \\ || //     ||--------    ||  //     ||
 */
//*** 1- Documentation
//This program is used to control a robot car using a app that communicates with Arduino trough a bluetooth module
#include <AFMotor.h>
//creates two objects to control the terminal 3 and 4 of motor shield 
AF_DCMotor motor1(2); 
AF_DCMotor motor2(1);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4); 
char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
      case 'S':
Stop();
break;        
    }
  } 
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); //rotate the motor counterclockwise
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); //rotate the motor counterclockwise
}

void left()
{
  motor1.setSpeed(0); //Define maximum velocity
  motor1.run(RELEASE); //rotate the motor clockwise
  motor2.setSpeed(255);
  motor2.run(FORWARD); //turn motor2 off
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);
  motor4.run(FORWARD); //turn motor2 off
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); //turn motor1 off
  motor2.setSpeed(0); //Define maximum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(255);
  motor3.run(FORWARD); //turn motor1 off
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
  motor3.setSpeed(0);
  motor3.run(RELEASE); //turn motor1 off
  motor4.setSpeed(0);
  motor4.run(RELEASE); //turn motor2 off
}

