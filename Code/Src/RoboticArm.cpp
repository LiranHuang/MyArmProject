#include "RoboticArm.h" // Required for TIM_CHANNEL_X with STM32 HAL
#include <stdio.h>

RoboticArm::RoboticArm()
    :joints{ServoMotor(1, TIM_CHANNEL_1), // Joint 1
        ServoMotor(2, TIM_CHANNEL_2)} //Joint 2
{}
// Constructor for a simple 2-DOF robotic arm

void RoboticArm::moveJoint(int index, int angle){
    if(index<0 || index >=2) return;
    joints[index].setAngle(angle);
}
// Move a specific joint to a target angle
// index： Joint index (0 or 1)
// angle： Target angle in degrees [0-180]

void RoboticArm::reset(){
    for(int i=0; i<2; ++i)
       joints[i].setAngle(0);
}
// Reset both joints back to 0 degrees

void RoboticArm::printStatus(){
    for(int i=0; i<2; ++i)
    printf("Joint %d: %d\n", i+1, joints[i].getAngle());
}
// Print current status of both joints