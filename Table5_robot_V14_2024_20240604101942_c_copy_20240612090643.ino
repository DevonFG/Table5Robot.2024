#include <PRIZM.h>  //Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE = 360; // Forward and Backward speed
const int SPIN = 180; // Spin speed
const int OPENSERVO1 = 90; //change this to be the degrees needed to open the servo
const int OPENSERVO2 = 180; //change this to be the degrees needed to open the servo
const int CLOSESERVO1 = 170; //change this to be the degrees needed to close the servo
const int CLOSESERVO2 = 90; //change this to be the degrees needed to close the servo
const int TURN90 = 1150; //change this to be the time is takes to turn 90º and comment direction (left or right)
const int SERVODELAY = 3000; //change this to the appropriate delay needed when moving the servos
int run = 0;

//Drive speed stays the same
//Spin speed stays the same
//Open servo 1 is __
//Open servo 2 is __
//Close servo 1 is __
//Close servo 2 is __
//Turn90 stays the same
//Servo delay can change, prefered as short as possible though
//run doesn't change up here, it's just a count so the program doesn't go back and do the same step again

//Action is a string, either open or close
void servos(String Action) {
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
void turn(String Direction, int Degrees) {
    if (Degrees == 90) {
      if (Direction == "right") {
        robot.setMotorTarget(1, SPIN, -TURN90);
        robot.setMotorTarget(2, SPIN, TURN90);
    } else if (Direction == "left" ) {
        robot.setMotorTarget(1, SPIN, TURN90);
        robot.setMotorTarget(2, SPIN, -TURN90);
    }
  }
    if (Degrees == 180) {
      if (Direction == "right") {
        robot.setMotorTarget(1, SPIN, -TURN90*2);
        robot.setMotorTarget(2, SPIN, TURN90*2);
    } else if (Direction == "left" ) {
        robot.setMotorTarget(1, SPIN, TURN90*2);
        robot.setMotorTarget(2, SPIN, -TURN90*2);
      }
    }
    while (robot.readMotorBusy(1)) {
    }
    resetEncoder();
  
}

//Time is a number, put the miliseconds to move
//Direction is a string, either forward or backward
void move(int Time, String Direction) {
    if (Direction == "forward") {
      robot.setMotorTarget(1, DRIVE, Time);
      robot.setMotorTarget(2, DRIVE, Time);
    } else if (Direction == "backward") {
      robot.setMotorTarget(1, DRIVE, -Time);
      robot.setMotorTarget(2, DRIVE, -Time);
    }
    while (robot.readMotorBusy(1)) {
    }
  resetEncoder();
}

//This is just to reset the encoders, no specific things
void resetEncoder() {
  robot.resetEncoder(1);
  robot.resetEncoder(2);
}

void end() {
  robot.setRedLED(HIGH); 
  delay(250);
  robot.setRedLED(LOW);
  delay(250);
}

void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin(); // Tells robot to start
  robot.setMotorInvert(2,1); // (which motor, 1=yes/0=no)
}

void loop() {
  servos("open");
  move(7394.957983, "forward"); //66in
  turn("right", 90);
  move(4033.613445, "forward"); //3ft
  servos("close");
  turn("right", 180);
  move(4761.9047615, "forward"); //3ft + 6.5in
  turn("right", 90);
  move(8683.4733884968, "forward"); //6.458333333333...ft
  servos("open");
  move(4705.8823525, "backward"); //3ft 6in
  turn("right", 90);
  move(4761.9047615, "forward"); //3ft + 6.5in
  servos("close");
  move(5602.2408958782, "backward"); //4ft 2in
  turn("left", 90);
  move(4761.9047615, "forward"); //3ft 6.5in
  servos("open");
  move(5000, "backward"); //blah
  end();

}