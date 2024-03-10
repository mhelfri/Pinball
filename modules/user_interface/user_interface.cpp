//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "pinball.h"

#include "user_interface.h"

#include "round_control.h"
#include "point_accumulation.h"
#include "display.h"

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_MS 1000

#define DEBOUNCE_BUTTON_TIME_MS 40

//=====[Declaration of private data types]=====================================

typedef enum {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_FALLING,
    BUTTON_RISING
} buttonState_t;

//=====[Declaration and initialization of public global objects]===============

DigitalIn roundButton(D12);
DigitalIn testPointButton(D13);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static int accumulatedDebounceButtonTime     = 0;
static int numberOfEnterButtonReleasedEvents = 0;
buttonState_t roundButtonState;

//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfaceRoundUpdate();
static void userInterfacePointUpdate();

static void roundButtonInit();
static bool roundButtonUpdate();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{   
    roundButton.mode(PullUp);
    testPointButton.mode(PullUp);
    pointInit();
    roundInit();
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    userInterfaceDisplayUpdate();
    userInterfaceRoundUpdate();
    userInterfacePointUpdate();
}

//=====[Implementations of private functions]==================================

static void userInterfaceDisplayInit()
{
    displayInit();
    displayCharPositionWrite( 0,0 );
    displayStringWrite("Its Pinball Time");
    displayCharPositionWrite(0,1);
    displayStringWrite("Points:");
}

static void userInterfaceDisplayUpdate()
{   
    static int accumulatedDisplayTime = 0;
    static int nDigits = floor(log10(abs( currentPointRead() ))) + 1;
    static char pointString[nDigits] = "";

    if( accumulatedDisplayTime >= DISPLAY_REFRESH_TIME_MS ){
        accumulatedDisplayTime = 0;
        sprintf(pointString, "%.0f" , currentPointRead() );
        

        if( roundStateRead() ) {
            if( previousRoundStateRead() == false ){
                previousRoundEqual();
                displayCharPositionWrite(0,0);
                displayStringWrite("Round Ongoing   ");
            }
            if(currentPointRead() != previousPointRead()){
                setEqual();
                displayCharPositionWrite(8,1);
                displayStringWrite( pointString );
            }
        }
        else{
            if( previousRoundStateRead() ){
                previousRoundEqual();
                displayCharPositionWrite(0,0);
                displayStringWrite("Round Over      ");
            }
        }
    }
    else {
        accumulatedDisplayTime = accumulatedDisplayTime + TIME_INCREMENT_MS;
    }
}

static void userInterfaceRoundUpdate()
{
    bool roundSwitch = roundButtonUpdate();
    if( roundSwitch ){
        roundStateWrite( !roundStateRead() )
    }
}

static void userInterfacePointUpdate()
{ 
    if( testPointButton == 0 ){
        pointIncrement();
    }
}

static void roundButtonInit()
{
    if( roundButton == 1) { //Sets initial state of FSM to BUTTON_UP if the button is not pressed
        roundButtonState = BUTTON_UP;
    } else { //Sets intial state of FSM to BUTTON_DOWN if button is pressed
        roundButtonState = BUTTON_DOWN;
    }
}


static bool roundButtonUpdate()
{
    bool roundButtonReleasedEvent = false;
    switch( roundButtonState ) {


    case BUTTON_UP:
        if( roundButton == 0 ) { //Sets the state to BUTTON_FALLING is the button was up and is now down
            roundButtonState = BUTTON_FALLING;
            accumulatedDebounceButtonTime = 0;
        }
        break;


    case BUTTON_FALLING:
        if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS ) { //Delays for debouncing
            if( roundButton == 0 ) { //Sets state to BUTTON_DOWN if button is still down after debounce time
                roundButtonState = BUTTON_DOWN;
            } else { //Sets state back to BUTTON_UP if button is up after debounce time
                roundButtonState = BUTTON_UP;
            }
        }
        accumulatedDebounceButtonTime = accumulatedDebounceButtonTime + TIME_INCREMENT_MS;
        break;


    case BUTTON_DOWN:
        if( roundButton == 1 ) { //Sets state to BUTTON_RISING if button was down and is now up
            roundButtonState = BUTTON_RISING;
            accumulatedDebounceButtonTime = 0;
        }
        break;


    case BUTTON_RISING:
        if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS ) { //Delays for debouncing
            if( roundButton == 1 ) { //Sets state to BUTTON_UP if button is still up after debouncing time
                roundButtonState = BUTTON_UP;
                roundButtonReleasedEvent = true; //Indicates that the button has been released
            } else { //Sets state back to BUTTON_DOWN if after debouncing time it is still down
                roundButtonState = BUTTON_DOWN;
            }
        }
        accumulatedDebounceButtonTime = accumulatedDebounceButtonTime +
                                        TIME_INCREMENT_MS;
        break;


    default:
        roundButtonInit(); //Initializes button state for the ignition button
        break;
    }
    return roundButtonReleasedEvent; //Returns false if the button has not been released, true if it has been released
}