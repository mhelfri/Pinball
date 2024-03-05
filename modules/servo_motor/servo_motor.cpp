v//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "servo_motor.h"

//=====[Declaration of private defines]========================================

#define PERIOD          .02

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut right_flipper(PF_7);
PwmOut left_flipper(PF_9);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void servoInit()
{
    right_flipper.period(PERIOD);
    left_flipper.period(PERIOD);
}

void rightFlipperWrite( float cycle )
{
    right_flipper.write(cycle);
}

void leftFlipperWrite( float cycle )
{
    left_flipper.write(cycle);
}
//=====[Implementations of private functions]==================================
