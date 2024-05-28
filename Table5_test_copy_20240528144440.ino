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
  
  robot.setMotorPowers(DRIVE,DRIVE);
  delay(5000);
  robot.setMotorPowers(STOP,STOP);
  delay(20000);
}
