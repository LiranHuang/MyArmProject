#ifndef ROBOTICARM.H
#define ROBOTICARM.H

#include "ServoMotor.h"

class RoboticArm{
    private:
    ServoMotor joints[2];
    
    public:
    RoboticArm();
    void moveJoint(int index, int angle);
    void reset();
    void printStatus();
};

#endif