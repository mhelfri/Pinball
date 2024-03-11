//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "point_accumulation.h"

//=====[Declaration of private defines]========================================

#define POINT_INCREMENT     20

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

int currentPoints = 0;
int previousPoints = 0;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void pointInit()
{
    currentPoints = 0;
    previousPoints = -20;
}

void pointIncrement()
{   
    currentPoints = previousPoints + POINT_INCREMENT;
}

void setEqual()
{
    previousPoints = currentPoints;
}

int currentPointRead()
{
    return currentPoints;
}

int previousPointRead()
{
    return previousPoints;
}

//=====[Implementations of private functions]==================================
