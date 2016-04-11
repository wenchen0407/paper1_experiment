#ifndef __SIMUL_step_delay_Embed_fcn_sfun_h__
#define __SIMUL_step_delay_Embed_fcn_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "sfcdebug.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */
extern int32_T _sfEvent_;
extern uint32_T _SIMUL_step_delay_Embed_fcnMachineNumber_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
extern void SIMUL_step_delay_Embed_fcn_initializer(void);
extern void SIMUL_step_delay_Embed_fcn_terminator(void);

/* Function Definitions */
#endif
