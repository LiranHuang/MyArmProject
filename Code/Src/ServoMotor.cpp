#include "ServoMotor.h"
#include "stm32f1xx_hal.h" // HAL header for Timer PWM control
#include <stdio.h>

extern TIM_HandleTypeDef htim2;
// External timer handle: must be initialized elsewhere using HAL

ServoMotor::ServorMotor(int motorId, uint32_t pwmChannel)
    :id(motorId), angle(0), channel(pwmChannel){}
 // motorId：    Logical ID for printing/debugging
 // pwmChannel： Timer channel used to drive the servo (e.g. TIM_CHANNEL_1)
 

void ServoMotor::setAngle(int target){
    angle = target;

    uint32_t pulse = mapAngleToPulse(angle);
    // Convert angle to PWM pulse width (500–2500 µs typically)

    __HAL_TIM_SET_COMPARE(&htim2, channel, pulse);
    // Write PWM pulse width to selected timer channel

    printf("Motor %d moved to angle: %d", id, angle);
    // Debug print (ensure printf retargeting is configured)
}

int ServoMotor::getAngle() const{
    return angle;
}
// Convert an angle in degrees to a PWM pulse width

uint32_t ServoMotor::mapAngleToPulse(int angle){
    return 500 + (angle * 2000)/180;
}
// pulse = 500 + (angle * 2000 / 180)
