#include "RoboticArm.h"
#include <stdio.h>

RoboticArm::RoboticArm()
    :joints{ServoMotor(1, TIM_CHANNEL_1), ServoMotor(2, TIM_CHANNEL_2)}
{}

void RoboticArm::moveJoint(int index, int angle){
    if(index<0 || index >=2) return;
    joints[index].setAngle(angle);
}

void RoboticArm::reset(){
    for(int i=0; i<2; ++i)
       joints[i].setAngle(0);
}

void RoboticArm::printStatus(){
    for(int i=0; i<2; ++i)
    printf("Joint %d: %d\n", i+1, joints[i].getAngle());
}