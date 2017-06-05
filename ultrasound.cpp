
#include "ultrasound.h"

ultrasound::ultrasound(PinName Trigger,PinName Echo):
				trigger_out(Trigger),
				echo_in(Echo)
				
{
	echo_in.rise(callback(this,&ultrasound::start_measure));
	echo_in.fall(callback(this,&ultrasound::stop_measure));
	echo_back = do_nothing;
	echo_in.disable_irq();
}

void ultrasound::do_nothing(uint32_t param)
{
	//nothing to do
}

void ultrasound::attach(Callback<void(uint32_t dist_cm)> func)
{
	echo_back = func;
}


void ultrasound::trigger()
{
	trigger_out = 1;
	wait_us(9);//9 gets you 10.13
	trigger_out = 0;
	echo_in.enable_irq();
	t.reset();
	t.start();
}

void ultrasound::start_measure()
{
	t.start();
}

void ultrasound::stop_measure()
{
	t.stop();
	echo_in.disable_irq();

	echo_back(t.read_us() / 58);//time to distance conversion
}

