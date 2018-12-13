#ifndef DRIVE_HEADER_H_INCLUDED
#define DRIVE_HEADER_H_INCLUDED

#include "ServoDriveTrain.h"
#include <time.h>
#include <Servo.h>
#include "ds_interface.h"

/*
# 2018_sprint_2_tractor_pushers
Sprint 2 code Header
*/

class DriveHeader{
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
  
 public:
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
