# ultrasound
Callback, Interrupt and timer based HC_SR04 Ultrasonic library

# Usage
```cpp
#include "ultrasound.h"

ultrasound mySens(PA_8,PA_9);//Trigger, Echo

void echo_back_handler(uint32_t dist_cm)
{
    printf("echo received with pulse width : %d  cm\n",dist_cm);
}

int main() 
{
    mySens.attach(&echo_back_handler);

    while(1) 
    {
        wait(1.0);
        mySens.trigger();
    }
}

```
