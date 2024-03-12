//=====[#include guards - begin]===============================================

#ifndef _SERVO_MOTOR_H_
#define _SERVO_MOTOR_H_

//=====[Declaration of public defines]=========================================

#define DUTY_RIGHT_MIN      .021
#define DUTY_RIGHT_MAX      .109
#define DUTY_LEFT_MIN       .025
#define DUTY_LEFT_MAX       .1079

#define DUTY_RIGHT_FLIP      .097
#define DUTY_LEFT_FLIP       .04

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void servoInit();
void rightFlipperWrite( float cycle );
void leftFlipperWrite( float cycle );

//=====[#include guards - end]=================================================

#endif // _SERVO_MOTOR_H_
