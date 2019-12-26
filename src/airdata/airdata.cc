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
static constexpr float A0 = 340.29f;   // standard sea level speed of sound, m/s
static constexpr float P0 = 101325.0f; // standard sea level pressure, Pa
static constexpr float T0 = 288.15f;   // standard sea level temperature, K
static constexpr float L = 0.0065f;    // standard lapse rate, K/m
static constexpr float R = 8.314f;     // gas constant, J/kg-mol
static constexpr float M = 0.02895f;   // molecular mass dry air, kg/mol
static constexpr float G = 9.80665f;     // acceleration due to gravity, m/s/s
} // anonymous

float GetIas_ms(float qc_pa)
{
  if (qc_pa < 0.0f) {
    qc_pa = 0.0f;
  }
  return A0 * sqrtf(5.0f * (powf((qc_pa / P0 + 1.0f), (2.0f / 7.0f)) - 1.0f));
}

float GetEas_ms(float qc_pa, float p_pa)
{
  return A0 * sqrtf(5.0f * p_pa / P0 * (powf((qc_pa / p_pa + 1.0f), (2.0f / 7.0f)) - 1.0f));
}

} // airdata
