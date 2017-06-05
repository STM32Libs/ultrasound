#ifndef __ULTRASOUND__
#define  __ULTRASOUND__

#include "mbed.h"

class ultrasound
{
public:
    ultrasound(PinName Trigger,PinName Echo);

    void trigger();
    void attach(Callback<void(uint32_t dist_cm)> func);

private:
    static void do_nothing(uint32_t param);
    void start_measure();
    void stop_measure();
    Callback<void(uint32_t dist_cm)> echo_back;

public:
    DigitalOut trigger_out;
    InterruptIn echo_in;
    Timer t;
};

#endif /*__ULTRASOUND__*/