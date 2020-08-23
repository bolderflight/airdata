/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include <cmath>
#include "global_defs/global_defs.h"

namespace airdata {
namespace {
static constexpr float STD_SEA_LEVEL_SPEED_OF_SOUND_MPS_ = 340.29f;
static constexpr float STD_SEA_LEVEL_PRESSURE_PA_ = 101325.0f;
static constexpr float STD_SEA_LEVEL_TEMPERATURE_C_ = 15.0f;
static constexpr float STD_SEA_LEVEL_TEMPERATURE_K_ = 288.15f;
static constexpr float LAPSE_RATE_KPM_ = 0.0065f;
static constexpr float GAS_CONSTANT_JPKGMOL_ = 8.31446261815324f;
static constexpr float MOLECULAR_MASS_AIR_KGPMOL_ = 0.0289644f;
}  // anonymous namespace
/*
* Computes indicated airspeed (m/s) from differential pressure (Pa)
*/
float Ias_mps(float p) {
  if (p < 0.0f) {return 0.0f;}
  return STD_SEA_LEVEL_SPEED_OF_SOUND_MPS_ * sqrtf(5.0f * (powf(p / STD_SEA_LEVEL_PRESSURE_PA_ + 1.0f, 2.0f / 7.0f) - 1.0f));
}
/*
* Computes equivalent airspeed (m/s) given differential pressure (Pa) and static pressure (Pa)
*/
float Eas_mps(float dp, float sp) {
  if ((dp < 0.0f) || (sp < 0.1f)) {  // static pressure avoid divide by 0
    return 0.0f;
  }
  return STD_SEA_LEVEL_SPEED_OF_SOUND_MPS_ * sqrtf(5.0f * sp / STD_SEA_LEVEL_PRESSURE_PA_ * (powf(dp / sp + 1.0f, 2.0f / 7.0f) - 1.0f));
}
/*
* Computes true airspeed (m/s) given EAS (m/s) and temperature (C)
*/
float Tas_mps(float eas, float t) {
  /* Convert temperature to K */
  float t_k = global::conversions::C_to_K<float>(t);
  if ((eas < 0.0f) || (t_k < 0.0f)) {
    return 0.0f;
  }
  return eas * sqrtf(t_k / STD_SEA_LEVEL_TEMPERATURE_K_);
}
/*
* Pressure altitude (m) from static pressure (Pa)
*/
float PressureAltitude_m(float p) {
  if (p < 0.0f) {
    p = 0.0f;
  }
  return STD_SEA_LEVEL_TEMPERATURE_K_ / LAPSE_RATE_KPM_ * (1.0f - powf(p / STD_SEA_LEVEL_PRESSURE_PA_, (LAPSE_RATE_KPM_ * GAS_CONSTANT_JPKGMOL_) / (MOLECULAR_MASS_AIR_KGPMOL_ * global::constants::G_MPS2<float>)));
}
/*
* Density altitude (m) given static pressure (Pa) and temperature (C)
*/
float DensityAltitude_m(float p, float t) {
  float t_k = global::conversions::C_to_K<float>(t);
  if (p < 0.0f) {
    p = 0.0f;
  }
  if (t_k < 1.0f) {
    t_k = 1.0f;
  }
  return STD_SEA_LEVEL_TEMPERATURE_K_ / LAPSE_RATE_KPM_ * (1.0f - powf(p / STD_SEA_LEVEL_PRESSURE_PA_ * STD_SEA_LEVEL_TEMPERATURE_K_ / t_k, (LAPSE_RATE_KPM_ * GAS_CONSTANT_JPKGMOL_) / (MOLECULAR_MASS_AIR_KGPMOL_ * global::constants::G_MPS2<float> - LAPSE_RATE_KPM_ * GAS_CONSTANT_JPKGMOL_)));
}
/*
* Estimated outside air temperature (C) as a function of surface temperature (C)
* and AGL altitude (m) using lapse rate
*/
float Oat_c(float t, float agl) {
  return t - LAPSE_RATE_KPM_ * agl;
}
/*
* Estimated air density (kg/m^3) from temperature (C) and pressure (Pa) 
*/
float AirDensity_kgpm3(float p, float t) {
  float t_k = global::conversions::C_to_K<float>(t);
  if (p < 0.0f) {
    return 0.0f;
  }
  if (t_k < 1.0f) {
    t_k = 1.0f;
  }
  return MOLECULAR_MASS_AIR_KGPMOL_ * p / (GAS_CONSTANT_JPKGMOL_ * t_k);
}

}  // namespace airdata
