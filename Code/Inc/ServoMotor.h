#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <stdint.h>

class ServoMotor {
private:
    int id;
    int angle;
    uint32_t channel; // Timer channel used for PWM output (TIM_CHANNEL_X)

public:
    ServoMotor(int motorId, uint32_t pwmChannel);
    void setAngle(int target); // Set the servo angle in degrees [0 - 180]
    int getAngle() const; // Get the last commanded angle
    // Construct a servo motor controller object

private:
    uint32_t mapAngleToPulse(int angle);
    //Mapping helper: Convert angle -> PWM pulse width
};

// Basic servo motor control class for STM32 PWM hardware.

#endif // SERVOMOTOR_H
