#include <time.h>
#include <Servo.h>
//add header for keyboard input and on WIP code
//Note: Once code has been finished tested here, move finished drive code over to WIP code

//-----------------------------------------------------
//Need to define turn L&R values here, and on WIP code
#define SERVO_FWD_R 0 //FWD_R
#define SERVO_REV_R 180 //REV_R
#define SERVO_TurnR_L 135 //adjust values
#define SERVO_TurnR_R 45 //adjust values

#define SERVO_FWD_L 180 //FWD_L
#define SERVO_REV_L 0 //REV_L
#define SERVO_TurnL_R 45 //adjust values
#define SERVO_TurnL_L 135 //adjust values

#define SERVO_STOP 90 //STOP
//--------------------------------
//Pin numbers to motors
const int GrabberL=8;
const int GrabberR=9;
const int leftFront_MotorPin=11;
const int leftBack_MotorPin=10;
const int rightFront_MotorPin=12;
const int rightBack_MotorPin=13;

//--------------------------------
// Servos for motors
Servo leftFront_Motor;
Servo leftBack_Motor;
Servo rightBack_Motor;
Servo rightFront_Motor;

//--------------------------------

void setup(){
//check orientation, adjust default values when needed
  leftFront_Motor.attach(leftFront_MotorPin);
  leftBack_Motor.attach(leftBack_MotorPin);
  rightFront_Motor.attach(rightFront_MotorPin);
  rightBack_Motor.attach(rightBack_MotorPin);
  test_setup();
}

void loop(){
  // input=ds.readInputIfAvailable();
  // inputReponse(command);
}

void test_setup(){
  /* forwardDrive();
  stopDrive();
  backwardDrive();
  stopDrive();*/
  rightDrive();
  /*stopDrive();
  leftDrive();
  stopDrive();
  */
}

/*void test_inputResponse(char command){
//elif? I have no idea what language I'm supposed to be using anymore
//else if= arduino/weird c++/c thing, elif=python, and that switch(input): then case this???
char list={'w','s','a','d'};//input keyboard
  if(command=list[0]){//forward
    forwardDrive();
  }
  else if(command=list[1]){//backward
    backwardDrive();
  }
  else if(command=list[2]){//left
    leftDrive();
  }
  else if(command=list[3]){//right
    rightDrive();
  }
  else{//stop
    stopDrive();
  }
}*/

void forwardDrive(){
  //test forward
  leftFront_Motor.write(SERVO_FWD_L);
  leftBack_Motor.write(SERVO_FWD_L);
  rightFront_Motor.write(SERVO_FWD_R);
  rightBack_Motor.write(SERVO_FWD_R);
}

void backwardDrive(){
  //test backward
  leftFront_Motor.write(SERVO_REV_L);
  leftBack_Motor.write(SERVO_REV_L);
  rightFront_Motor.write(SERVO_REV_R);
  rightBack_Motor.write(SERVO_REV_R);
}

void rightDrive(){
  //test right turn (turn 2 or all 4 wheels?)
  leftFront_Motor.write(SERVO_TurnR_L);
  leftBack_Motor.write(SERVO_TurnR_L);
  rightFront_Motor.write(SERVO_TurnR_R);
  rightBack_Motor.write(SERVO_TurnR_R);
}

void leftDrive(){
  //test left turn (turn 2 or all 4 wheels?)
  leftFront_Motor.write(SERVO_TurnL_L);
  leftBack_Motor.write(SERVO_TurnL_L);
  rightFront_Motor.write(SERVO_TurnL_R);
  rightBack_Motor.write(SERVO_TurnL_R);
}

void stopDrive(){
  leftFront_Motor.write(SERVO_STOP);
  leftBack_Motor.write(SERVO_STOP);
  rightFront_Motor.write(SERVO_STOP);
  rightBack_Motor.write(SERVO_STOP);
}
