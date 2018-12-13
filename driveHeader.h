#include "ServoDriveTrain.h"
#include <time.h>
#include <Servo.h>
#include "ds_interface.h"

class driveHeader{
# 2018_sprint_2_tractor_pushers
Sprint 2 code Header

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
//Pin numbers to motors
const int leftGrab_MotorPin=8;
const int rightGrab_MotorPin=9;
const int leftFront_MotorPin=11;//check?
const int leftBack_MotorPin=10;//check?
const int rightFront_MotorPin=12;
const int rightBack_MotorPin=13;

Servo leftGrab_Motor;
Servo rightGrab_Motor;
Servo leftFront_Motor;
Servo leftBack_Motor;
Servo rightBack_Motor;
Servo rightFront_Motor;
//-------------------------------------------
char drive[]={'s','w','x','a','d','q','e'}; //stop, front, back, straight left, straight right, turn left, turn right
char grabber[]={'r','f'}; //grab, release; switch later?
char emergencyStop=' ';//editing here
bool emergencySwitch=false;
//-------------------------------------------
char input;
char command='';

void commandDirectory(char input);

void grabberCommand(char input);

void driveCommand(char input);

//-------------------------------------------
void setup();
void loop();
}
