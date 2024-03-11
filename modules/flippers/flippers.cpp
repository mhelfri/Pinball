//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "flippers.h"
#include "servo_motor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn rightButton(D10);
DigitalIn leftButton(D11);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void flippersInit()
{
    servoInit();
    rightButton.mode(PullDown);
    leftButton.mode(PullDown);
    rightFlipperWrite(DUTY_RIGHT_MAX);
    leftFlipperWrite(DUTY_LEFT_MIN);
}

void flippersUpdate()
{
    if(rightButton){
        rightFlipperWrite(DUTY_RIGHT_FLIP);
    }
    else{
        rightFlipperWrite(DUTY_RIGHT_MAX);
    }
    if(leftButton){
        leftFlipperWrite(DUTY_LEFT_FLIP);
    }
    else{
        leftFlipperWrite(DUTY_LEFT_MIN);
    }
}

//=====[Implementations of private functions]==================================
