#include "ServoMotor.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>

extern TIM_HandleTypeDef htim2;

ServoMotor::ServorMotor(int motorId, uint32_t pwmChannel)
    :id(motorId), angle(0), channel(pwmChannel){}

void ServoMotor::SetAngle(int target){
    angle = target;
    uint32_t pulse = mapAngleToPulse(angle);
    __HAL_TIM_SET_COMPARE(&htim2, channel, pulse);
    printf("Motor %d moved to angle: %d", id, angle);
}

int ServoMotor::getAngle() const{
    return angle;
}

uint32_t ServoMotor::mapAngleToPulse(int angle){
    return 500 + (angle * 2000)/180;
}