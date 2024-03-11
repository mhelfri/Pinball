//=====[#include guards - begin]===============================================

#ifndef _ROUND_CONTROL_H_
#define _ROUND_CONTROL_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void roundInit();
void roundStateWrite( bool state );
bool roundStateRead();
bool previousRoundStateRead();
void previousRoundEqual();
int roundCountRead();
void roundCountReset();

//=====[#include guards - end]=================================================

#endif // _ROUND_CONTROL_H_
