
{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*вход интегрирующего звена*)
		out : {REDUND_UNREPLICABLE} REAL; (*выход интегрирующего звена*)
		dt : {REDUND_UNREPLICABLE} REAL; (*шаг расчета (с)*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL; (*входное напряжение (В)*)
		w : {REDUND_UNREPLICABLE} REAL; (*частота вращения (об\мин)*)
		phi : {REDUND_UNREPLICABLE} REAL; (*положение (рад)*)
		integrator : {REDUND_UNREPLICABLE} FB_Integrator; (*интегратор*)
		Tm : {REDUND_UNREPLICABLE} REAL; (*электромеханическая постоянная времени (с)*)
		ke : {REDUND_UNREPLICABLE} REAL; (*постоянная ЭДС двигателя (В*мин\об)*)
		dt : {REDUND_UNREPLICABLE} REAL; (*шаг расчета (с)*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Regulator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL; (*рассогласование между задающим воздействием и реальной скоростью вращения вала ДПТ (об\мин)*)
		u : {REDUND_UNREPLICABLE} REAL; (*напряжение, подаваемое на вход (В)*)
		k_p : {REDUND_UNREPLICABLE} REAL; (*пропорциональый коэфициент регулятора*)
		k_i : {REDUND_UNREPLICABLE} REAL; (*интегральный коэфициент регулятора*)
		integrator : {REDUND_UNREPLICABLE} FB_Integrator; (*интегратор*)
		iyOld : {REDUND_UNREPLICABLE} REAL; (*хранение предыдущего значения схемы противонакопления*)
		max_abs_value : {REDUND_UNREPLICABLE} REAL; (*граница блока ограничения (В)*)
		dt : {REDUND_UNREPLICABLE} REAL; (*шаг расчета (с)*)
	END_VAR
END_FUNCTION_BLOCK
