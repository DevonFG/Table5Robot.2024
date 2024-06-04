#include <PRIZM.h>  //Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE = 360; // Forward and Backward speed
const int SPIN = 180; // Spin speed
const int OPENSERVO1 = 50; //change this to be the degrees needed to open the servo
const int OPENSERVO2 = 70; //change this to be the degrees needed to open the servo
const int CLOSESERVO1 = 10; //change this to be the degrees needed to close the servo
const int CLOSESERVO2 = 0; //change this to be the degrees needed to close the servo
const int TURN90 = 3000; //change this to be the time is takes to turn 90º and comment direction (left or right)
const int SERVODELAY = 2000; //change this to the appropriate delay needed when moving the servos
int run = 0;
// CURRENTLY: OPENSERVO1, OPENSERVO2, and TURN90 are guestimations of the number needed

//Action is a string, either open or close
void servos(int Action) {
  if (Action == "open") {
    robot.setServoPosition(1, OPENSERVO1);
    robot.setServoPosition(2, OPENSERVO2);
  } else if (Action == "close") {
    robot.setServoPosition(1, CLOSESERVO1);
    robot.setServoPosition(2, CLOSESERVO2);
  }
  delay(SERVODELAY);
}

//Direction is a string, either right or left
//Degrees is a string, either 90 or 180
void turn(int Direction, int Degrees) {
  if (Degrees == "90") {
    if (Direction == "right") {
      robot.setMotorTarget(1, SPIN, TURN90);
      robot.setMotorTarget(2, SPIN, TURN90);
    } else if (Direction == "left" ) {
      robot.setMotorTarget(1, SPIN, TURN90);
      robot.setMotorTarget(2, SPIN, TURN90);
    }
  }
  if (Degrees == "180") {
    if (Direction == "right") {
      robot.setMotorTarget(1, SPIN, TURN90*2);
      robot.setMotorTarget(2, SPIN, TURN90*2);
    } else if (Direction == "left" ) {
      robot.setMotorTarget(1, SPIN, TURN90*2);
      robot.setMotorTarget(2, SPIN, TURN90*2);
    }
  }
  
}

//Time is a number, put the miliseconds to move
//Direction is a string, either forward or backward
void move(int Time, int Direction) {
  if (Direction == "forward") {
    robot.setMotorTarget(1, DRIVE, Time);
    robot.setMotorTarget(2, DRIVE, Time);
  } else if (Direction == "backward") {
    robot.setMotorTarget(1, -DRIVE, Time);
    robot.setMotorTarget(2, -DRIVE, Time);
  }

}

//This is just to reset the encoders, no specific things
void resetEncoder() {
  robot.resetEncoder(1);
  robot.resetEncoder(1);
}

void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin(); // Tells robot to start
  robot.setMotorInvert(2,1); // (which motor, 1=yes/0=no)
}

void loop() {
//MOST numbers will need to change, most numbers are 0 so we know to substitue them.

if (robot.readServoPosition(1) != OPENSERVO1 && robot.readServoPosition(2) != OPENSERVO2 && run == 0) {
  servos("open");
  run = 1;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 1) {
  move(0, "forward"); //change the 0
  resetEncoder();
  run = 2;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 2) {
  turn("right", 90);
  run = 3;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 3) {
  move(0, "forward"); //change the 0
  run = 4;
} else if (robot.readServoPosition(1) != OPENSERVO1 && robot.readServoPosition(2) != OPENSERVO2 && run == 4) {
  servos("close");
  run = 5;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 5) {
  turn("right", 180);
  run = 6;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 6) {
  move(0, "forward"); //change the 0
  run = 7;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 7) {
  turn("right", 90);
  run = 8;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 8) {
  move(0, "forward"); //change the 0
  run = 9;
} else if (robot.readServoPosition(1) != OPENSERVO1 && robot.readServoPosition(2) != OPENSERVO2 && run == 9) {
  servos("open");
  run = 10;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 10) {
  move(0, "backward"); //change the 0
  run = 11;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 11) {
  turn("right", 90);
  run = 12;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 12) {
  move(0, "forward"); //change the 0
  run = 13;
} else if (robot.readServoPosition(1) != OPENSERVO1 && robot.readServoPosition(13) != OPENSERVO2 && run == 0) {
  servos("close");
  run = 14;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 14) {
  move(0, "backward"); //change the 0
  run = 15;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 15) {
  turn("left", 90);
  run = 16;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 16) {
  move(0, "forward"); //change the 0
  run = 17;
} else if (robot.readServoPosition(1) != OPENSERVO1 && robot.readServoPosition(2) != OPENSERVO2 && run == 17) {
  servos("open");
  run = 18;
} else if (!robot.readMotorBusy(1) && !robot.readMotorBusy(2) && run == 18) {
  move(0, "backward"); //change the 0
  run = 19;
} else {
  robot.setRedLED(HIGH); 
  delay(250);
  robot.setRedLED(LOW);
  delay(250);
}
}