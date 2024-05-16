#include <PRIZM.h>  //Include all of the instructions for Tetrix stuff
PRIZM robot;
const int DRIVE = 50; // Forward and Backward speed
const int SPIN = 50; // Spin speed
const int STOP = 0; // STOP!!!


void setup() {
  // put your setup code here, to run once:
  robot.PrizmBegin(); // Tells robot to start
  robot.setMotorInvert(2,1); // (which motor, 1=yes/0=no)
  // robot.setServoPositions(int servoposition1, int servoposition2, int servoposition3, int servoposition4, int servoposition5, int servoposition6)
}


void loop() {
  // put your main code here, to run repeatedly:
    while(robot.readSonicSensorCM(3) > 2.5){
    robot.setMotorPowers(DRIVE,DRIVE); // (motor1, motor2) in percents
  }

  robot.setMotorPowers(STOP, STOP);

  while(robot.readSonicSensorCM(3) < 2.5){
    robot.setMotorPowers(DRIVE,DRIVE);
    delay(500);
    robot.setMotorPowers(SPIN, -SPIN); //Spin direction IDK
    delay(5000); // pause for 5sec [1sec = 1000milisec]
  }

  robot.setMotorPowers(STOP,STOP);

}
