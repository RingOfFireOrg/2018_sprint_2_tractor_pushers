/*
# 2018_sprint_2_tractor_pushers
Sprint 2 code

Notes:
-Motor wheel pins: 10,11,12,13
-Grabber pins: 8,9

To-Do List:
-Check L&R values
-consider reverse turn vs forward turn?
-check if all headers are in file
-make code for start up (activation? default emergencyStop on?)
-autonomous?
-check code, test upload
*/

#include "DriveHeader.h"

//check?
#define SERVO_FWD_R 0 //FWD_R
#define SERVO_REV_R 180 //REV_R

#define SERVO_FWD_L 180 //FWD_L
#define SERVO_REV_L 0 //REV_L

#define SERVO_TurnR_L 135 //check and adjust
#define SERVO_TurnR_R 45 

#define SERVO_TurnL_R 45 //check and adjust
#define SERVO_TurnL_L 135 

#define SERVO_STOP 90 //STOP
//-------------------------------------------
/*
-Align grabber motion with L/R motor settings (forward=outward for grabbers)
*/

DriveHeader::DriveHeader(){
  input = ds.readInputIfAvailable();
}

DriveHeader::~DriveHeader(){

}

void DriveHeader::commandDirectory(char input){
  char temp=drive+grabber;//0, 1-7, 8-9 for emergencyStop, drive, and grabber
  for(int i=0; i<10; i++){
    if(input==temp[i]){
      if(i==0){//emergencystop
        emergencySwitch=!emergencySwitch;
        driveCommand('s');
      }
      else if((i>0)&&(i<8)&&(emergencySwitch)){//drive
        driveCommand(input);
      }
      else if(((i==8)||(i==9))&&(emergencySwitch)){//grabber
        grabberCommand(input);
      }
      else{//?
      
      }
    }
  }
  
}

void DriveHeader::grabberCommand(char input){//check grabber spin orientation?
  if(input==grabber[0]){//grab
    leftGrab_Motor.write(SERVO_FWD_L);
    rightGrab_Motor.write(SERVO_FWD_R);
  }
  else if(input==grabber[1]){//release
    leftGrab_Motor.write(SERVO_REV_L);
    rightGrab_Motor.write(SERVO_REV_R);
  }
}

void DriveHeader::driveCommand(char input){
     if(input==drive[0]){//stop
          leftFront_Motor.write(SERVO_STOP);
          leftBack_Motor.write(SERVO_STOP);
          rightFront_Motor.write(SERVO_STOP);
          rightBack_Motor.write(SERVO_STOP);
        }
     else if(input==drive[1]){//front
          leftFront_Motor.write(SERVO_FWD_L);
          leftBack_Motor.write(SERVO_FWD_L);
          rightFront_Motor.write(SERVO_FWD_R);
          rightBack_Motor.write(SERVO_FWD_R);
        }
      else if(input==drive[2]){//back
          leftFront_Motor.write(SERVO_REV_L);
          leftBack_Motor.write(SERVO_REV_L);
          rightFront_Motor.write(SERVO_REV_R);
          rightBack_Motor.write(SERVO_REV_R);
        }
      else if(input==drive[3]){//straight left
          leftFront_Motor.write(SERVO_FWD_L);
          leftBack_Motor.write(SERVO_REV_L);
          rightFront_Motor.write(SERVO_REV_R);
          rightBack_Motor.write(SERVO_FWD_R);
        }
      else if(input==drive[4]){//straight right
          leftFront_Motor.write(SERVO_REV_L);
          leftBack_Motor.write(SERVO_FWD_L);
          rightFront_Motor.write(SERVO_FWD_R);
          rightBack_Motor.write(SERVO_REV_R);
        }
      else if(input==drive[5]){//turn left
          leftFront_Motor.write(SERVO_TurnL_L);//edit?
          leftBack_Motor.write(SERVO_TurnL_L);//edit?
          rightFront_Motor.write(SERVO_TurnL_R);
          rightBack_Motor.write(SERVO_TurnL_R);
        }
        else if(input==drive[6]){//turn right
          leftFront_Motor.write(SERVO_TurnR_L);
          leftBack_Motor.write(SERVO_TurnR_L);
          rightFront_Motor.write(SERVO_TurnR_R);//edit?
          rightBack_Motor.write(SERVO_TurnR_R);//edit?
        }
    }
  }

//-------------------------------------------
void DriveHeader::setup(){
  leftGrab_Motor.attach(leftGrab_MotorPin);
  rightGrab_Motor.attach(rightGrab_MotorPin);
  leftFront_Motor.attach(leftFront_MotorPin);
  leftBack_Motor.attach(leftBack_MotorPin);
  rightFront_Motor.attach(rightFront_MotorPin);
  rightBack_Motor.attach(rightBack_MotorPin);
}

void DriveHeader::loop(){
  input= ds.readInputIfAvailable();
  commandDirectory(input);
}
