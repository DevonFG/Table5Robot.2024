#include <PRIZM.h>  //Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE = 360; // Forward and Backward speed
const int SPIN = 180; // Spin speed
const int OPENSERVO1 = 50;
const int OPENSERVO2 = 70; //both servos have a start point of 0, so they need different const int's
const int TURN90 = 3000; //this needs to be a time, miliseconds

// CURRENTLY: OPENSERVO1, OPENSERVO2, and TURN90 are guestimations of the number needed


void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin(); // Tells robot to start
  robot.setMotorInvert(2,1); // (which motor, 1=yes/0=no)
}


void loop() {

// TEST for distance moved in 5 seconds
  if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2)) {
    robot.setMotorTarget(1, DRIVE, 5000);
    robot.setMotorTarget(2, DRIVE, 5000);
  } else if (robot.readEncoderCount(1) == 5000 && robot.readEncoderCount(2) == 5000) {
    delay(50000000);
  }

// TEST for angle turned in TURN90 miliseconds
  if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2)) {
    robot.setMotorTarget(1, SPIN, TURN90);
    robot.setMotorTarget(2, -SPIN, TURN90);
  } else if (robot.readEncoderCount(1) == TURN90 && robot.readEncoderCount(2) == -TURN90) {
    delay(500000000);
  }

// TEST for servo position in 1 when at OPENSERVO1 degrees
  if (robot.readServoPosition(1) < OPENSERVO1) {
    robot.setServoPosition(1, OPENSERVO1);
  } else if (robot.readServoPosition(1) == OPENSERVO1) {
    delay(5000000000);
  }

// TEST for servo position in 2 when at OPENSERVO2 degrees
  if (robot.readServoPosition(2) < OPENSERVO2) {
    robot.setServoPosition(2, OPENSERVO2);
  } else if (robot.readServoPosition(2) == OPENSERVO2) {
    delay(50000000000);
  }

}