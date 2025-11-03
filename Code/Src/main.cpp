#include "stm32f1xx_hal.h"
#include "RoboticArm.h"

extern "C" void SystemClock_Config(void);
extern "C" void MX_GPIO_Init(void);
extern "C" void MX_USART2_UART_Init(void);
extern "C" void MX_TIM2_Init(Void);

extern TIM_HandleTypeDef htim2;

int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_USART2_UART_Init();
    MX_GPIO_Init();
    MX_TIM2_Init();
}

RoboticArm arm;
arm.moveJoint(0,45);
arm.moveJoint(1,90);
arm.printStatus();

HAL_Delay(2000)
arm.reset();
arm.printStatus();

while(1){}
