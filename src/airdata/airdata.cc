/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include <math.h>

namespace airdata {

namespace {
static constexpr float A0 = 340.29f;  // standard sea level speed of sound, m/s
static constexpr float P0 = 101325.0f;  // standard sea level pressure, Pa
static constexpr float T0 = 288.15f;    // standard sea level temperature, K
static constexpr float L = 0.0065f;     // standard lapse rate, K/m
static constexpr float R = 8.31432f;    // gas constant, J/kg-mol
static constexpr float M = 0.0289644f;  // molecular mass dry air, kg/mol
static constexpr float G = 9.80665f;    // acceleration due to gravity, m/s/s
}  // anonymous

float GetIas_ms(float qc_pa) {
  if (qc_pa < 0.0f) {
    qc_pa = 0.0f;
  }
  return A0 * sqrtf(5.0f * (powf((qc_pa / P0 + 1.0f), (2.0f / 7.0f)) - 1.0f));
}

float GetTas_ms(float AS_ms, float T_C) {
  if (AS_ms < 0.0f) {
    AS_ms = 0.0f;
  }
  return AS_ms * sqrtf((T_C+273.15f)/T0);
}

float GetPressureAltitude_m(float p_pa) {
  if (p_pa < 0.0f) {
    p_pa = 0.0f;
  }
  return (T0/L)*(1.0f - powf((p_pa/P0), ((L*R)/(M*G))));
}

float GetAGL_m(float p_pa, float c_m) {
  return GetPressureAltitude_m(p_pa) - c_m;
}

float GetMSL_m(float H_m, float h_m) {
  return H_m + h_m;
}

float GetDensityAltitude_m(float p_pa, float T_C) {
  if (p_pa < 0.0f) {
    p_pa = 0.0f;
  }
  return (T0/L)*(1.0f - powf(((p_pa/P0)*(T0/(T_C+273.15f))),
    ((L*R)/(M*G - L*R))));
}

float EstimateOAT_C(float T_C, float h_m) {
  return ((T_C+273.15) - L*h_m) - 273.15;
}

float GetDensity_kgm3(float p_pa, float T_C) {
  if (p_pa < 0.0f) {
    p_pa = 0.0f;
  }
  return (M*p_pa)/(R*(T_C+273.15f));
}

}  // namespace airdata
