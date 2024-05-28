#include <PRIZM.h>  //Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE = 50; // Forward and Backward speed
const int SPIN = 25; // Spin speed
const int STOP = 0; // STOP!!!


void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin(); // Tells robot to start
  robot.setMotorInvert(2,1); // (which motor, 1=yes/0=no)
}


void loop() {
  
  robot.setMotorTarget(1,DRIVE, 5000);
  robot.setMotorTarget(2,DRIVE, 5000);
  delay(500);
  robot.setMotorPowers(STOP,STOP);
  
  if (robot.readSonicSensorCM(A3) < 14){
  

  robot.setMotorPowers(STOP,STOP);

  // Servo 1 is 180º, Servo 2 is like 270º or something
  robot.resetEncoder(1);
  robot.resetEncoder(2);
  //Still need to code Servo 2 (full movement) as well as need to fix the servo 1 after testing it.
  } else {
  
  }
}