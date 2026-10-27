
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

static REAL limit_abs(REAL x, REAL lim)
{
	if (x > lim) return lim;
	if (x < -lim) return -lim;
	return x;

}


void FB_Regulator(struct FB_Regulator* inst)
{/*
	float prop_part = inst->e * inst->k_p;
	if (prop_part > inst->max_abs_value) prop_part = inst->max_abs_value;
	if (prop_part < -inst->max_abs_value) prop_part = -inst->max_abs_value;
	
	float intteg_input = (inst->e * inst->k_i * inst->dt) + inst->iyOld;
	inst->integrator.in = intteg_input;
	
	inst->integrator.dt = 1.0f;
	FB_Integrator(&inst->integrator);
	
	float sum_u = prop_part + inst->integrator.out;
	
	float limited_u = sum_u;
	if (limited_u > inst->max_abs_value) limited_u = inst->max_abs_value;
	if (limited_u > -inst->max_abs_value) limited_u = -inst->max_abs_value;
	
	inst->u = limited_u; */
	
	
	REAL p_part;
	REAL sum_unlim;
	
	p_part = limit_abs(inst->k_p*inst->e, inst->max_abs_value);
	
	inst->integrator.in = inst->k_i * inst->e + inst->iyOld / inst->dt;
	inst->integrator.dt = inst->dt;
	
	FB_Integrator(&inst->integrator);
	
	sum_unlim = p_part + inst->integrator.out;
	
	inst->u = limit_abs(sum_unlim, inst->max_abs_value);
	
	
	inst->iyOld = inst->u - sum_unlim;
	
	
	
	
	
	
}
