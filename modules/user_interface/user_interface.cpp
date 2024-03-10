//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"

#include "round_control.h"
#include "point_accumulation.h"
#include "display.h"

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    userInterfaceDisplayUpdate();
}

//=====[Implementations of private functions]==================================

static void userInterfaceDisplayInit()
{
    displayInit();
    displayCharPositionWrite( 0,0 );
    displayStringWrite("Round Ongoing")
    displayCharPositionWrite(0,1);
    displayStringWrite("Points:");
}

static void userInterfaceDisplayUpdate()
{   
    static int accumulatedDisplayTime = 0;
    int nDigits = floor(log10(abs( currentPointRead() ))) + 1;
    char pointString[nDigits] = "";

    if( accumulatedDisplayTime >= DISPLAY_REFRESH_TIME_MS ){
        accumulatedDisplayTime = 0;

        sprintf(pointString, "%.0f" , currentPointRead() )
        

        if( roundStateRead() ) {
            if(currentPoints != previousPoints){
                displayCharPositionWrite(8,1);
                displayStringWrite( pointString )
            }
    }
    else {
        accumulatedDisplayTime = accumulatedDisplayTime + 10;
    }

}

static void engineIndicatorUpdate()
{
    engineLed = engineState;
}