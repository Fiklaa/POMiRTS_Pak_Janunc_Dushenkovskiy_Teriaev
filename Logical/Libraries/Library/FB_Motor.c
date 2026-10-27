
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{/*
	float delta_w = (inst->u / inst->ke)- inst->w;
	inst->w += delta_w * (inst->dt / inst->Tm);
	
	inst->integrator.in = inst->w;
	inst->integrator.dt = inst->dt;
	
	FB_Integrator(&inst->integrator);
	
	inst->phi = inst->integrator.out;
*/
	
	inst->integrator.in = (inst->u / inst->ke - inst->w) / inst->Tm;
	inst->integrator.dt = inst->dt;
	FB_Integrator(&inst->integrator);
	
	inst->w = inst->integrator.out;
	
	inst->phi = inst->phi + inst->w * 0.10471975512f * inst->dt;
}
