
#include "ultrasound.h"

ultrasound::ultrasound(PinName Trigger,PinName Echo):
				echo(Echo),
				trigger(Trigger)
{
	trigger.rise(callback(this,&ultrasound::start_measure));
	trigger.fall(callback(this,&ultrasound::stop_measure));
	echo_back = do_nothing;
}

void ultrasound::do_nothing(uint32_t param)
{
	//nothing to do
}

void ultrasound::attach(Callback<void(uint32_t data)> func)
{
	echo_back = func;
}


void ultrasound::send_echo()
{
	echo = 1;
	wait_us(10);
	echo = 0;
	t.start();
}

void ultrasound::start_measure()
{
	t.start();
}

void ultrasound::stop_measure()
{
	t.stop();
	echo_back(t.read_us());
}

