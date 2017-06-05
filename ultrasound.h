#ifndef __ULTRASOUND__
#define  __ULTRASOUND__

#include "mbed.h"

class ultrasound
{
public:
    ultrasound(PinName Trigger,PinName Echo);

    void send_echo();
    void attach(Callback<void(uint32_t data)> func);

private:
    static void do_nothing(uint32_t param);
    void start_measure();
    void stop_measure();
    Callback<void(uint32_t data)> echo_back;

public:
    DigitalOut echo;
    InterruptIn trigger;
    Timer t;
};

#endif /*__ULTRASOUND__*/