
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	
	counter = counter + fb_motor.dt;
	if (counter  >= 60.0f) counter = 0.0f;
	if (counter > 20.0f && counter < 40.0f) Speed = 60.0f;
	else {
		Speed = 0.0f;
	}
	fb_controller.e = Speed - fb_motor.w;
	
	FB_Regulator(&fb_controller);
	
	fb_motor.u = fb_controller.u;
	fb_motor2.u = Speed*fb_motor2.ke;
	
	FB_Motor(&fb_motor2);
	FB_Motor(&fb_motor);
}