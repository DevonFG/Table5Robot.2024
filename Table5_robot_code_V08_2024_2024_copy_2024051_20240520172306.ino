#include <PRIZM.h>  //Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE = 50; // Forward and Backward speed
const int SPIN = 100; // Spin speed
const int STOP = 0; // STOP!!!


void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin(); // Tells robot to start
  robot.setMotorInvert(2,1); // (which motor, 1=yes/0=no)
}


void loop() {
  // put your main code here, to run repeatedly:
  while(robot.readSonicSensorCM(A3) >= 2.5){
    robot.setMotorPowers(DRIVE,DRIVE); // (motor1, motor2) in percents
  }

  if (robot.readSonicSensorCM(A3) < 2.5){

  robot.setMotorTarget(1,SPIN,3600);
  robot.setMotorTarget(2,-SPIN,3600);

  robot.setMotorPowers(STOP,STOP);

  // Servo 1 is 180º, Servo 2 is full movement
  robot.setServoPosition(1, 120); // (Servo#, Degrees)
  delay(1000);
  robot.setServoPosition(1, 60);
  delay(500);
  robot.setServoPosition(1, 120); 
  delay(500);
  robot.setServoPosition(1, 60);
  delay(500);
  robot.resetEncoder(1);
  robot.resetEncoder(2);
  //Still need to code Servo 2 (full movement) as well as need to fix the servo 1 after testing it.
  } else {
  robot.setMotorTarget(1,DRIVE, 3600);
  robot.setMotorTarget(2,DRIVE, 3600);
  }
}
