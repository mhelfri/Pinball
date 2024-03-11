//=====[Libraries]=============================================================

#include "pinball.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    pinballInit();
    while (true) {
        pinballUpdate();
    }
}