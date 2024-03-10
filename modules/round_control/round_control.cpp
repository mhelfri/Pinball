//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "round_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

bool roundState = false;
bool previousRoundState = true;

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void roundStateWrite( bool state )
{
    previousRoundState = roundState;
    roundState = state;
}

void previousRoundEqual()
{
    previousRoundState = roundState;
}

bool roundStateRead()
{
    return roundState;
}

bool previousRoundStateRead()
{
    return previousRoundState;
}
//=====[Implementations of private functions]==================================
