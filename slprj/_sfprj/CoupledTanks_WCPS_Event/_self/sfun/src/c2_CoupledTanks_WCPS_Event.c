/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CoupledTanks_WCPS_Event_sfun.h"
#include "c2_CoupledTanks_WCPS_Event.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CoupledTanks_WCPS_Event_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[17] = { "sennum", "step_count", "kk",
  "j", "emgcounter", "nargin", "nargout", "yout", "ydelay", "structure",
  "yout_delay", "i", "yin_d", "yin", "delay", "yin_all", "num" };

/* Function Declarations */
static void initialize_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void initialize_params_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void enable_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void disable_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void set_sim_state_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void sf_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void c2_chartstep_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void initSimStructsc2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void registerMessagesc2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_num, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_yin_all, const char_T *c2_identifier,
  real_T c2_y[50005]);
static void c2_d_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[50005]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_delay, const char_T *c2_identifier, real_T
  c2_y[8]);
static void c2_f_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[8]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_yin, const char_T *c2_identifier, real_T
  c2_y[5]);
static void c2_h_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_i_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_yin_d, const char_T *c2_identifier, real_T
  c2_y[5]);
static void c2_j_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_k_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_i, const char_T *c2_identifier);
static real_T c2_l_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_m_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_yout_delay, const char_T *c2_identifier,
  real_T c2_y[5]);
static void c2_n_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_o_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  c2_struct_CAxie3DVBrLFQ7IqoeRl6D *c2_y);
static real_T c2_p_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_q_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_r_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_s_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[246]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_t_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_u_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c2_b_is_active_c2_CoupledTanks_WCPS_Event, const
  char_T *c2_identifier);
static uint8_T c2_v_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_i_not_empty = FALSE;
  chartInstance->c2_yin_d_not_empty = FALSE;
  chartInstance->c2_yin_not_empty = FALSE;
  chartInstance->c2_delay_not_empty = FALSE;
  chartInstance->c2_yin_all_not_empty = FALSE;
  chartInstance->c2_num_not_empty = FALSE;
  chartInstance->c2_is_active_c2_CoupledTanks_WCPS_Event = 0U;
}

static void initialize_params_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  const mxArray *c2_m0 = NULL;
  const mxArray *c2_mxField;
  c2_struct_CAxie3DVBrLFQ7IqoeRl6D c2_r0;
  sf_set_error_prefix_string(
    "Error evaluating data 'structure' in the parent workspace.\n");
  c2_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c2_mxField = sf_mex_getfield(c2_m0, "i", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c2_mxField), &c2_r0.i, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "count", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c2_mxField), &c2_r0.count, 1, 0,
                      0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "yin", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c2_mxField), c2_r0.yin, 1, 0, 0U,
                      1, 0U, 2, 1, 5);
  c2_mxField = sf_mex_getfield(c2_m0, "yin_d", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c2_mxField), c2_r0.yin_d, 1, 0, 0U,
                      1, 0U, 2, 5, 1);
  c2_mxField = sf_mex_getfield(c2_m0, "delay1", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c2_mxField), c2_r0.delay1, 1, 0,
                      0U, 1, 0U, 2, 41, 6);
  c2_mxField = sf_mex_getfield(c2_m0, "ranD", "structure", 0);
  sf_mex_import_named("structure", sf_mex_dup(c2_mxField), c2_r0.ranD, 1, 0, 0U,
                      1, 0U, 2, 1, 5);
  sf_mex_destroy(&c2_m0);
  chartInstance->c2_structure = c2_r0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[5];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[8];
  const mxArray *c2_c_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  int32_T c2_i2;
  real_T c2_e_u[5];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i3;
  static real_T c2_f_u[50005];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i4;
  real_T c2_g_u[5];
  const mxArray *c2_h_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T (*c2_yout_delay)[5];
  c2_yout_delay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(8), FALSE);
  for (c2_i0 = 0; c2_i0 < 5; c2_i0++) {
    c2_u[c2_i0] = (*c2_yout_delay)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 8; c2_i1++) {
    c2_b_u[c2_i1] = chartInstance->c2_delay[c2_i1];
  }

  c2_c_y = NULL;
  if (!chartInstance->c2_delay_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 8),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_i;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  if (!chartInstance->c2_i_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_b_hoistedGlobal = chartInstance->c2_num;
  c2_d_u = c2_b_hoistedGlobal;
  c2_e_y = NULL;
  if (!chartInstance->c2_num_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  for (c2_i2 = 0; c2_i2 < 5; c2_i2++) {
    c2_e_u[c2_i2] = chartInstance->c2_yin[c2_i2];
  }

  c2_f_y = NULL;
  if (!chartInstance->c2_yin_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  for (c2_i3 = 0; c2_i3 < 50005; c2_i3++) {
    c2_f_u[c2_i3] = chartInstance->c2_yin_all[c2_i3];
  }

  c2_g_y = NULL;
  if (!chartInstance->c2_yin_all_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 2, 10001, 5),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 5, c2_g_y);
  for (c2_i4 = 0; c2_i4 < 5; c2_i4++) {
    c2_g_u[c2_i4] = chartInstance->c2_yin_d[c2_i4];
  }

  c2_h_y = NULL;
  if (!chartInstance->c2_yin_d_not_empty) {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 1, 5),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_CoupledTanks_WCPS_Event;
  c2_h_u = c2_c_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[5];
  int32_T c2_i5;
  real_T c2_dv1[8];
  int32_T c2_i6;
  real_T c2_dv2[5];
  int32_T c2_i7;
  static real_T c2_dv3[50005];
  int32_T c2_i8;
  real_T c2_dv4[5];
  int32_T c2_i9;
  real_T (*c2_yout_delay)[5];
  c2_yout_delay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "yout_delay", c2_dv0);
  for (c2_i5 = 0; c2_i5 < 5; c2_i5++) {
    (*c2_yout_delay)[c2_i5] = c2_dv0[c2_i5];
  }

  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "delay", c2_dv1);
  for (c2_i6 = 0; c2_i6 < 8; c2_i6++) {
    chartInstance->c2_delay[c2_i6] = c2_dv1[c2_i6];
  }

  chartInstance->c2_i = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "i");
  chartInstance->c2_num = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "num");
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                        "yin", c2_dv2);
  for (c2_i7 = 0; c2_i7 < 5; c2_i7++) {
    chartInstance->c2_yin[c2_i7] = c2_dv2[c2_i7];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                        "yin_all", c2_dv3);
  for (c2_i8 = 0; c2_i8 < 50005; c2_i8++) {
    chartInstance->c2_yin_all[c2_i8] = c2_dv3[c2_i8];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
                        "yin_d", c2_dv4);
  for (c2_i9 = 0; c2_i9 < 5; c2_i9++) {
    chartInstance->c2_yin_d[c2_i9] = c2_dv4[c2_i9];
  }

  chartInstance->c2_is_active_c2_CoupledTanks_WCPS_Event = c2_u_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 7)),
     "is_active_c2_CoupledTanks_WCPS_Event");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_CoupledTanks_WCPS_Event(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void sf_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T (*c2_yout_delay)[5];
  real_T (*c2_ydelay)[8];
  real_T (*c2_yout)[5];
  c2_yout_delay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_ydelay = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c2_yout = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i10 = 0; c2_i10 < 5; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*c2_yout)[c2_i10], 0U);
  }

  for (c2_i11 = 0; c2_i11 < 8; c2_i11++) {
    _SFD_DATA_RANGE_CHECK((*c2_ydelay)[c2_i11], 1U);
  }

  for (c2_i12 = 0; c2_i12 < 5; c2_i12++) {
    _SFD_DATA_RANGE_CHECK((*c2_yout_delay)[c2_i12], 2U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_CoupledTanks_WCPS_Event(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CoupledTanks_WCPS_EventMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
  int32_T c2_i13;
  real_T c2_yout[5];
  int32_T c2_i14;
  real_T c2_ydelay[8];
  c2_struct_CAxie3DVBrLFQ7IqoeRl6D c2_b_structure;
  uint32_T c2_debug_family_var_map[17];
  real_T c2_sennum;
  real_T c2_step_count;
  real_T c2_kk;
  real_T c2_j;
  real_T c2_emgcounter;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_yout_delay[5];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_b_kk;
  int32_T c2_b_j;
  int32_T c2_b_emgcounter;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  real_T (*c2_b_yout_delay)[5];
  real_T (*c2_b_ydelay)[8];
  real_T (*c2_b_yout)[5];
  c2_b_yout_delay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_ydelay = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_yout = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i13 = 0; c2_i13 < 5; c2_i13++) {
    c2_yout[c2_i13] = (*c2_b_yout)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 8; c2_i14++) {
    c2_ydelay[c2_i14] = (*c2_b_ydelay)[c2_i14];
  }

  c2_b_structure = chartInstance->c2_structure;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_sennum, 0U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_step_count, 1U, c2_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_kk, 2U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_j, 3U, c2_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_emgcounter, 4U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 5U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 6U, c2_j_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_yout, 7U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_ydelay, 8U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_structure, 9U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_yout_delay, 10U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_i, 11U,
    c2_f_sf_marshallOut, c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_yin_d, 12U,
    c2_e_sf_marshallOut, c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_yin, 13U,
    c2_d_sf_marshallOut, c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_delay, 14U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_yin_all, 15U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c2_num, 16U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_sennum = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_step_count = 10000.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_yin_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    chartInstance->c2_i = c2_b_structure.i;
    chartInstance->c2_i_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    for (c2_i15 = 0; c2_i15 < 5; c2_i15++) {
      chartInstance->c2_yin[c2_i15] = c2_b_structure.yin[c2_i15];
    }

    chartInstance->c2_yin_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
    for (c2_i16 = 0; c2_i16 < 5; c2_i16++) {
      chartInstance->c2_yin_d[c2_i16] = c2_b_structure.yin_d[c2_i16];
    }

    chartInstance->c2_yin_d_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
    for (c2_i17 = 0; c2_i17 < 50005; c2_i17++) {
      chartInstance->c2_yin_all[c2_i17] = 0.0;
    }

    chartInstance->c2_yin_all_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    for (c2_i18 = 0; c2_i18 < 8; c2_i18++) {
      chartInstance->c2_delay[c2_i18] = 0.0;
    }

    chartInstance->c2_delay_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
    for (c2_i19 = 0; c2_i19 < 8; c2_i19++) {
      chartInstance->c2_delay[c2_i19] = c2_ydelay[c2_i19];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
    chartInstance->c2_num = 0.0;
    chartInstance->c2_num_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  chartInstance->c2_num++;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  for (c2_i20 = 0; c2_i20 < 8; c2_i20++) {
    chartInstance->c2_delay[c2_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  for (c2_i21 = 0; c2_i21 < 8; c2_i21++) {
    chartInstance->c2_delay[c2_i21] = c2_ydelay[c2_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_kk = 1.0;
  c2_b_kk = 0;
  while (c2_b_kk < 5) {
    c2_kk = 1.0 + (real_T)c2_b_kk;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
    chartInstance->c2_yin_all[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "yin_all", (int32_T)_SFD_INTEGER_CHECK("num", chartInstance->c2_num), 1,
      10001, 1, 0) + 10001 * ((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "yin_all", (int32_T)_SFD_INTEGER_CHECK("kk", c2_kk), 1, 5, 2, 0) - 1)) - 1]
      = c2_yout[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("yout", (int32_T)
      _SFD_INTEGER_CHECK("kk", c2_kk), 1, 5, 1, 0) - 1];
    c2_b_kk++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_j = 5.0;
  CV_EML_FOR(0, 1, 1, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  if (CV_EML_IF(0, 1, 1, chartInstance->c2_delay[5] != 88.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
    chartInstance->c2_yin[4] = chartInstance->c2_yin_all[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)_SFD_INTEGER_CHECK("num",
      chartInstance->c2_num), 1, 10001, 1, 0) + 40003];
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    if (CV_EML_IF(0, 1, 2, chartInstance->c2_num > 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      chartInstance->c2_yin[4] = chartInstance->c2_yin_all[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)_SFD_INTEGER_CHECK(
        "num-1", chartInstance->c2_num - 1.0), 1, 10001, 1, 0) + 40003];
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
      chartInstance->c2_yin_all[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "yin_all", (int32_T)_SFD_INTEGER_CHECK("num", chartInstance->c2_num), 1,
        10001, 1, 0) + 40003] = chartInstance->c2_yin_all[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)_SFD_INTEGER_CHECK(
        "num-1", chartInstance->c2_num - 1.0), 1, 10001, 1, 0) + 40003];
    }
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
  c2_j = 1.0;
  c2_b_j = 0;
  while (c2_b_j < 4) {
    c2_j = 1.0 + (real_T)c2_b_j;
    CV_EML_FOR(0, 1, 2, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
    if (CV_EML_IF(0, 1, 3, chartInstance->c2_delay[(int32_T)(real_T)
                  _SFD_EML_ARRAY_BOUNDS_CHECK("delay", (int32_T)
          _SFD_INTEGER_CHECK("j+1", c2_j + 1.0), 1, 8, 2, 0) - 1] != 88.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
      chartInstance->c2_yin[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("yin",
        (int32_T)_SFD_INTEGER_CHECK("j", c2_j), 1, 5, 1, 0) - 1] =
        chartInstance->c2_yin_all[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "yin_all", (int32_T)_SFD_INTEGER_CHECK("num", chartInstance->c2_num), 1,
        10001, 1, 0) + 10001 * ((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "yin_all", (int32_T)_SFD_INTEGER_CHECK("j", c2_j), 1, 5, 2, 0) - 1)) - 1];
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
      c2_emgcounter = 1.0;
      c2_b_emgcounter = 0;
      while (c2_b_emgcounter < 400) {
        c2_emgcounter = 1.0 + (real_T)c2_b_emgcounter;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
        if (CV_EML_IF(0, 1, 4, chartInstance->c2_num + c2_emgcounter <= 401.0))
        {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
          chartInstance->c2_yin_all[((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("yin_all", (int32_T)_SFD_INTEGER_CHECK(
            "num+emgcounter", chartInstance->c2_num + c2_emgcounter), 1, 10001,
            1, 0) + 10001 * ((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
            "yin_all", (int32_T)_SFD_INTEGER_CHECK("j", c2_j), 1, 5, 2, 0) - 1))
            - 1] = chartInstance->c2_yin[(int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("yin", (int32_T)_SFD_INTEGER_CHECK("j",
            c2_j), 1, 5, 1, 0) - 1];
        }

        c2_b_emgcounter++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
    }

    c2_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 2, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
  for (c2_i22 = 0; c2_i22 < 5; c2_i22++) {
    chartInstance->c2_yin_d[c2_i22] = chartInstance->c2_yin[c2_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 81);
  for (c2_i23 = 0; c2_i23 < 5; c2_i23++) {
    c2_yout_delay[c2_i23] = chartInstance->c2_yin_d[c2_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
  chartInstance->c2_i++;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -83);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i24 = 0; c2_i24 < 5; c2_i24++) {
    (*c2_b_yout_delay)[c2_i24] = c2_yout_delay[c2_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_CoupledTanks_WCPS_Event
  (SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_num_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_num, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_num), &c2_thisId);
  sf_mex_destroy(&c2_b_num);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_num_not_empty = FALSE;
  } else {
    chartInstance->c2_num_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_num;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_num = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_num), &c2_thisId);
  sf_mex_destroy(&c2_b_num);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  static real_T c2_b_inData[50005];
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  static real_T c2_u[50005];
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i25 = 0;
  for (c2_i26 = 0; c2_i26 < 5; c2_i26++) {
    for (c2_i27 = 0; c2_i27 < 10001; c2_i27++) {
      c2_b_inData[c2_i27 + c2_i25] = (*(real_T (*)[50005])c2_inData)[c2_i27 +
        c2_i25];
    }

    c2_i25 += 10001;
  }

  c2_i28 = 0;
  for (c2_i29 = 0; c2_i29 < 5; c2_i29++) {
    for (c2_i30 = 0; c2_i30 < 10001; c2_i30++) {
      c2_u[c2_i30 + c2_i28] = c2_b_inData[c2_i30 + c2_i28];
    }

    c2_i28 += 10001;
  }

  c2_y = NULL;
  if (!chartInstance->c2_yin_all_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 10001, 5),
                  FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_yin_all, const char_T *c2_identifier,
  real_T c2_y[50005])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yin_all), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_yin_all);
}

static void c2_d_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[50005])
{
  static real_T c2_dv5[50005];
  int32_T c2_i31;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_yin_all_not_empty = FALSE;
  } else {
    chartInstance->c2_yin_all_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 2,
                  10001, 5);
    for (c2_i31 = 0; c2_i31 < 50005; c2_i31++) {
      c2_y[c2_i31] = c2_dv5[c2_i31];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_yin_all;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static real_T c2_y[50005];
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_yin_all = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yin_all), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_yin_all);
  c2_i32 = 0;
  for (c2_i33 = 0; c2_i33 < 5; c2_i33++) {
    for (c2_i34 = 0; c2_i34 < 10001; c2_i34++) {
      (*(real_T (*)[50005])c2_outData)[c2_i34 + c2_i32] = c2_y[c2_i34 + c2_i32];
    }

    c2_i32 += 10001;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i35;
  real_T c2_b_inData[8];
  int32_T c2_i36;
  real_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i35 = 0; c2_i35 < 8; c2_i35++) {
    c2_b_inData[c2_i35] = (*(real_T (*)[8])c2_inData)[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 8; c2_i36++) {
    c2_u[c2_i36] = c2_b_inData[c2_i36];
  }

  c2_y = NULL;
  if (!chartInstance->c2_delay_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 8), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_delay, const char_T *c2_identifier, real_T
  c2_y[8])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_delay), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_delay);
}

static void c2_f_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[8])
{
  real_T c2_dv6[8];
  int32_T c2_i37;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_delay_not_empty = FALSE;
  } else {
    chartInstance->c2_delay_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                  8);
    for (c2_i37 = 0; c2_i37 < 8; c2_i37++) {
      c2_y[c2_i37] = c2_dv6[c2_i37];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_delay;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[8];
  int32_T c2_i38;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_delay = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_delay), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_delay);
  for (c2_i38 = 0; c2_i38 < 8; c2_i38++) {
    (*(real_T (*)[8])c2_outData)[c2_i38] = c2_y[c2_i38];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i39;
  real_T c2_b_inData[5];
  int32_T c2_i40;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i39 = 0; c2_i39 < 5; c2_i39++) {
    c2_b_inData[c2_i39] = (*(real_T (*)[5])c2_inData)[c2_i39];
  }

  for (c2_i40 = 0; c2_i40 < 5; c2_i40++) {
    c2_u[c2_i40] = c2_b_inData[c2_i40];
  }

  c2_y = NULL;
  if (!chartInstance->c2_yin_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_yin, const char_T *c2_identifier, real_T
  c2_y[5])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yin), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_yin);
}

static void c2_h_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv7[5];
  int32_T c2_i41;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_yin_not_empty = FALSE;
  } else {
    chartInstance->c2_yin_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                  5);
    for (c2_i41 = 0; c2_i41 < 5; c2_i41++) {
      c2_y[c2_i41] = c2_dv7[c2_i41];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_yin;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i42;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_yin = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yin), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_yin);
  for (c2_i42 = 0; c2_i42 < 5; c2_i42++) {
    (*(real_T (*)[5])c2_outData)[c2_i42] = c2_y[c2_i42];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i43;
  real_T c2_b_inData[5];
  int32_T c2_i44;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i43 = 0; c2_i43 < 5; c2_i43++) {
    c2_b_inData[c2_i43] = (*(real_T (*)[5])c2_inData)[c2_i43];
  }

  for (c2_i44 = 0; c2_i44 < 5; c2_i44++) {
    c2_u[c2_i44] = c2_b_inData[c2_i44];
  }

  c2_y = NULL;
  if (!chartInstance->c2_yin_d_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_i_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_yin_d, const char_T *c2_identifier, real_T
  c2_y[5])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yin_d), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_yin_d);
}

static void c2_j_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv8[5];
  int32_T c2_i45;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_yin_d_not_empty = FALSE;
  } else {
    chartInstance->c2_yin_d_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv8, 1, 0, 0U, 1, 0U, 1, 5);
    for (c2_i45 = 0; c2_i45 < 5; c2_i45++) {
      c2_y[c2_i45] = c2_dv8[c2_i45];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_yin_d;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i46;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_yin_d = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_yin_d), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_yin_d);
  for (c2_i46 = 0; c2_i46 < 5; c2_i46++) {
    (*(real_T (*)[5])c2_outData)[c2_i46] = c2_y[c2_i46];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_i_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_k_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_b_i, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i), &c2_thisId);
  sf_mex_destroy(&c2_b_i);
  return c2_y;
}

static real_T c2_l_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_i_not_empty = FALSE;
  } else {
    chartInstance->c2_i_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_i;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_i = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_i), &c2_thisId);
  sf_mex_destroy(&c2_b_i);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i47;
  real_T c2_b_inData[5];
  int32_T c2_i48;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i47 = 0; c2_i47 < 5; c2_i47++) {
    c2_b_inData[c2_i47] = (*(real_T (*)[5])c2_inData)[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 5; c2_i48++) {
    c2_u[c2_i48] = c2_b_inData[c2_i48];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_m_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_yout_delay, const char_T *c2_identifier,
  real_T c2_y[5])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_yout_delay), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_yout_delay);
}

static void c2_n_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv9[5];
  int32_T c2_i49;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv9, 1, 0, 0U, 1, 0U, 1, 5);
  for (c2_i49 = 0; c2_i49 < 5; c2_i49++) {
    c2_y[c2_i49] = c2_dv9[c2_i49];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_yout_delay;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i50;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_yout_delay = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_yout_delay), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_yout_delay);
  for (c2_i50 = 0; c2_i50 < 5; c2_i50++) {
    (*(real_T (*)[5])c2_outData)[c2_i50] = c2_y[c2_i50];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  c2_struct_CAxie3DVBrLFQ7IqoeRl6D c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i51;
  real_T c2_d_u[5];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i52;
  real_T c2_e_u[5];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i53;
  real_T c2_f_u[246];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i54;
  real_T c2_g_u[5];
  const mxArray *c2_g_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_struct_CAxie3DVBrLFQ7IqoeRl6D *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c2_b_u = c2_u.i;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_b_y, "i", "i", 0);
  c2_c_u = c2_u.count;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c2_y, c2_c_y, "count", "count", 0);
  for (c2_i51 = 0; c2_i51 < 5; c2_i51++) {
    c2_d_u[c2_i51] = c2_u.yin[c2_i51];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  sf_mex_addfield(c2_y, c2_d_y, "yin", "yin", 0);
  for (c2_i52 = 0; c2_i52 < 5; c2_i52++) {
    c2_e_u[c2_i52] = c2_u.yin_d[c2_i52];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 2, 5, 1),
                FALSE);
  sf_mex_addfield(c2_y, c2_e_y, "yin_d", "yin_d", 0);
  for (c2_i53 = 0; c2_i53 < 246; c2_i53++) {
    c2_f_u[c2_i53] = c2_u.delay1[c2_i53];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 2, 41, 6),
                FALSE);
  sf_mex_addfield(c2_y, c2_f_y, "delay1", "delay1", 0);
  for (c2_i54 = 0; c2_i54 < 5; c2_i54++) {
    c2_g_u[c2_i54] = c2_u.ranD[c2_i54];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  sf_mex_addfield(c2_y, c2_g_y, "ranD", "ranD", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_o_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  c2_struct_CAxie3DVBrLFQ7IqoeRl6D *c2_y)
{
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[6] = { "i", "count", "yin", "yin_d",
    "delay1", "ranD" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 6, c2_fieldNames, 0U, 0);
  c2_thisId.fIdentifier = "i";
  c2_y->i = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "i", "i", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "count";
  c2_y->count = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "count", "count", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "yin";
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "yin",
    "yin", 0)), &c2_thisId, c2_y->yin);
  c2_thisId.fIdentifier = "yin_d";
  c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "yin_d",
    "yin_d", 0)), &c2_thisId, c2_y->yin_d);
  c2_thisId.fIdentifier = "delay1";
  c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "delay1",
    "delay1", 0)), &c2_thisId, c2_y->delay1);
  c2_thisId.fIdentifier = "ranD";
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "ranD",
    "ranD", 0)), &c2_thisId, c2_y->ranD);
  sf_mex_destroy(&c2_u);
}

static real_T c2_p_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_q_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv10[5];
  int32_T c2_i55;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c2_i55 = 0; c2_i55 < 5; c2_i55++) {
    c2_y[c2_i55] = c2_dv10[c2_i55];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_r_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv11[5];
  int32_T c2_i56;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 5, 1);
  for (c2_i56 = 0; c2_i56 < 5; c2_i56++) {
    c2_y[c2_i56] = c2_dv11[c2_i56];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_s_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[246])
{
  real_T c2_dv12[246];
  int32_T c2_i57;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv12, 1, 0, 0U, 1, 0U, 2, 41,
                6);
  for (c2_i57 = 0; c2_i57 < 246; c2_i57++) {
    c2_y[c2_i57] = c2_dv12[c2_i57];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_structure;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_struct_CAxie3DVBrLFQ7IqoeRl6D c2_y;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_structure = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_structure), &c2_thisId,
                        &c2_y);
  sf_mex_destroy(&c2_b_structure);
  *(c2_struct_CAxie3DVBrLFQ7IqoeRl6D *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i58;
  real_T c2_b_inData[8];
  int32_T c2_i59;
  real_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i58 = 0; c2_i58 < 8; c2_i58++) {
    c2_b_inData[c2_i58] = (*(real_T (*)[8])c2_inData)[c2_i58];
  }

  for (c2_i59 = 0; c2_i59 < 8; c2_i59++) {
    c2_u[c2_i59] = c2_b_inData[c2_i59];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_CoupledTanks_WCPS_Event_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_t_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i60;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i60, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i60;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_u_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c2_b_is_active_c2_CoupledTanks_WCPS_Event, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_v_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_CoupledTanks_WCPS_Event), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_CoupledTanks_WCPS_Event);
  return c2_y;
}

static uint8_T c2_v_emlrt_marshallIn(SFc2_CoupledTanks_WCPS_EventInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_CoupledTanks_WCPS_EventInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_CoupledTanks_WCPS_Event_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3621093130U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(532096931U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1485737038U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3289683796U);
}

mxArray *sf_c2_CoupledTanks_WCPS_Event_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("h9YRkxXDN7vhE5GJGqL3pB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_CoupledTanks_WCPS_Event_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_CoupledTanks_WCPS_Event(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"yout_delay\",},{M[4],M[0],T\"delay\",S'l','i','p'{{M1x2[332 337],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[308 309],M[0],}}},{M[4],M[0],T\"num\",S'l','i','p'{{M1x2[346 349],M[0],}}},{M[4],M[0],T\"yin\",S'l','i','p'{{M1x2[328 331],M[0],}}},{M[4],M[0],T\"yin_all\",S'l','i','p'{{M1x2[338 345],M[0],}}},{M[4],M[0],T\"yin_d\",S'l','i','p'{{M1x2[310 315],M[0],}}},{M[8],M[0],T\"is_active_c2_CoupledTanks_WCPS_Event\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CoupledTanks_WCPS_Event_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
    chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CoupledTanks_WCPS_EventMachineNumber_,
           2,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_CoupledTanks_WCPS_EventMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CoupledTanks_WCPS_EventMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CoupledTanks_WCPS_EventMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"yout");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ydelay");
          _SFD_SET_DATA_PROPS(2,2,0,1,"yout_delay");
          _SFD_SET_DATA_PROPS(3,10,0,0,"structure");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,4,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1734);
        _SFD_CV_INIT_EML_IF(0,1,0,464,479,-1,722);
        _SFD_CV_INIT_EML_IF(0,1,1,927,946,1001,1219);
        _SFD_CV_INIT_EML_IF(0,1,2,1014,1022,-1,1203);
        _SFD_CV_INIT_EML_IF(0,1,3,1266,1285,1524,1589);
        _SFD_CV_INIT_EML_IF(0,1,4,1421,1445,-1,1507);
        _SFD_CV_INIT_EML_FOR(0,1,0,833,846,881);
        _SFD_CV_INIT_EML_FOR(0,1,1,913,923,1223);
        _SFD_CV_INIT_EML_FOR(0,1,2,1252,1262,1593);
        _SFD_CV_INIT_EML_FOR(0,1,3,1390,1411,1519);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)
            c2_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)c2_h_sf_marshallIn);

        {
          real_T (*c2_yout)[5];
          real_T (*c2_ydelay)[8];
          real_T (*c2_yout_delay)[5];
          c2_yout_delay = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S,
            1);
          c2_ydelay = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
          c2_yout = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_yout);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_ydelay);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_yout_delay);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_structure);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CoupledTanks_WCPS_EventMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3KKYY7l85qVilMSaW3lA7G";
}

static void sf_opaque_initialize_c2_CoupledTanks_WCPS_Event(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_CoupledTanks_WCPS_Event
    ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
  initialize_c2_CoupledTanks_WCPS_Event
    ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  enable_c2_CoupledTanks_WCPS_Event((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  disable_c2_CoupledTanks_WCPS_Event((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_CoupledTanks_WCPS_Event(void *chartInstanceVar)
{
  sf_c2_CoupledTanks_WCPS_Event((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_CoupledTanks_WCPS_Event
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_CoupledTanks_WCPS_Event
    ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CoupledTanks_WCPS_Event();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_CoupledTanks_WCPS_Event(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CoupledTanks_WCPS_Event();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_CoupledTanks_WCPS_Event
    ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_CoupledTanks_WCPS_Event
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_CoupledTanks_WCPS_Event(S);
}

static void sf_opaque_set_sim_state_c2_CoupledTanks_WCPS_Event(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_CoupledTanks_WCPS_Event(S, st);
}

static void sf_opaque_terminate_c2_CoupledTanks_WCPS_Event(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CoupledTanks_WCPS_Event_optimization_info();
    }

    finalize_c2_CoupledTanks_WCPS_Event
      ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CoupledTanks_WCPS_Event
    ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CoupledTanks_WCPS_Event(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CoupledTanks_WCPS_Event
      ((SFc2_CoupledTanks_WCPS_EventInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_CoupledTanks_WCPS_Event(SimStruct *S)
{
  /* Actual parameters from chart:
     structure
   */
  const char_T *rtParamNames[] = { "structure" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CoupledTanks_WCPS_Event_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2414722804U));
  ssSetChecksum1(S,(2468998955U));
  ssSetChecksum2(S,(3719197202U));
  ssSetChecksum3(S,(4034075817U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_CoupledTanks_WCPS_Event(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_CoupledTanks_WCPS_Event(SimStruct *S)
{
  SFc2_CoupledTanks_WCPS_EventInstanceStruct *chartInstance;
  chartInstance = (SFc2_CoupledTanks_WCPS_EventInstanceStruct *)utMalloc(sizeof
    (SFc2_CoupledTanks_WCPS_EventInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_CoupledTanks_WCPS_EventInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_CoupledTanks_WCPS_Event;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_CoupledTanks_WCPS_Event_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CoupledTanks_WCPS_Event(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CoupledTanks_WCPS_Event(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CoupledTanks_WCPS_Event(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CoupledTanks_WCPS_Event_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
