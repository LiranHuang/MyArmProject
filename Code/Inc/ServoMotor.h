#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <stdint.h>

class ServoMotor {
private:
    int id;
    int angle;
    uint32_t channel;

public:
    ServoMotor(int motorId, uint32_t pwmChannel);
    void setAngle(int target);
    int getAngle() const;

private:
    uint32_t mapAngleToPulse(int angle);
};

#endif // SERVOMOTOR_H
