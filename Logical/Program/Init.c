#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	float dt = 0.01f;
	float Tj = 0.3f;
	
	
	fb_controller.max_abs_value = 24.0f;
	fb_controller.dt = dt;
	fb_controller.iyOld = 0.0f;
	fb_controller.integrator.out = 0.0f;
	
	fb_motor.ke = 0.01f;
	fb_motor.Tm = 0.05f;
	fb_motor.dt = dt;
	fb_motor.w = 0.0f;
	fb_motor.phi = 0.0f;
	fb_motor.integrator.out = 0.0f;
	
	fb_motor2.ke = 0.01f;
	fb_motor2.Tm = 0.05f;
	fb_motor2.dt = dt;
	fb_motor2.w = 0.0f;
	fb_motor2.phi = 0.0f;
	fb_motor2.integrator.out = 0.0f;
	
	fb_controller.k_p = fb_motor.ke * fb_motor.Tm / Tj;
	fb_controller.k_i = fb_motor.ke / Tj;
	
	counter = 0.0f;
	Speed = 0.0f;
	Enable = 1;
}
