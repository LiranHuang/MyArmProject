#ifndef ROBOTICARM_H
#define ROBOTICARM_H

#include "ServoMotor.h"

class RoboticArm{
    private:
    ServoMotor joints[2]; // Servo array (joint[0] and joint[1])
    
    public: 
    RoboticArm();
    void moveJoint(int index, int angle); // Move a specific joint to the target angle.
    void reset(); // Reset all joints back to default angle (0°).
    void printStatus();
    // Construct a robotic arm with two servo joints.
};
// Simple 2-DOF robotic arm abstraction class.

#endif // ROBOTICARM_H