/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2023 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <cmath>
#endif

#include "airdata_constants.h"  // NOLINT
#include "airdata.h"  // NOLINT
#include "units.h"  // NOLINT

namespace bfs {
float Ias_mps(const float p) {
  if (p < 0.0f) {return 0.0f;}
  return SEA_LEVEL_SPEED_OF_SOUND_MPS * sqrtf(5.0f *
    (powf(p / SEA_LEVEL_PRESSURE_PA + 1.0f, 2.0f / 7.0f) - 1.0f));
}

float Eas_mps(const float dp, const float sp) {
  if ((dp < 0.0f) || (sp < 0.1f)) {
    return 0.0f;
  }
  return SEA_LEVEL_SPEED_OF_SOUND_MPS * sqrtf(5.0f * sp /
    SEA_LEVEL_PRESSURE_PA * (powf(dp / sp + 1.0f, 2.0f / 7.0f) - 1.0f));
}
/*
* Computes true airspeed (m/s) given EAS (m/s) and temperature (C)
*/
float Tas_mps(const float eas, const float t) {
  float t_k = convtemp(t, TempUnit::C, TempUnit::K);
  if ((eas < 0.0f) || (t_k < 0.0f)) {
    return 0.0f;
  }
  return eas * sqrtf(t_k / SEA_LEVEL_TEMPERATURE_K);
}
/*
* Pressure altitude (m) from static pressure (Pa)
*/
float PressureAltitude_m(float p) {
  if (p < 0.0f) {
    p = 0.0f;
  }
  return SEA_LEVEL_TEMPERATURE_K / LAPSE_RATE_KPM *
    (1.0f - powf(p / SEA_LEVEL_PRESSURE_PA,
    (LAPSE_RATE_KPM * GAS_CONSTANT_JPKGMOL) /
    (MOLECULAR_MASS_AIR_KGPMOL * G_MPS2)));
}
/*
* Density altitude (m) given static pressure (Pa) and temperature (C)
*/
float DensityAltitude_m(float p, const float t) {
  float t_k = convtemp(t, TempUnit::C, TempUnit::K);
  if (p < 0.0f) {
    p = 0.0f;
  }
  if (t_k < 1.0f) {
    t_k = 1.0f;
  }
  return SEA_LEVEL_TEMPERATURE_K / LAPSE_RATE_KPM *
    (1.0f - powf(p / SEA_LEVEL_PRESSURE_PA * SEA_LEVEL_TEMPERATURE_K / t_k,
    (LAPSE_RATE_KPM * GAS_CONSTANT_JPKGMOL) /
    (MOLECULAR_MASS_AIR_KGPMOL * G_MPS2 -
    LAPSE_RATE_KPM * GAS_CONSTANT_JPKGMOL)));
}
/*
* Estimated outside air temperature (C) as a fuction of surface temperature (C)
* and AGL altitude (m) using lapse rate
*/
float Oat_c(const float t, const float agl) {
  return t - LAPSE_RATE_KPM * agl;
}
/*
* Estimated air density (kg/m^3) from temperature (C) and pressure (Pa) 
*/
float AirDensity_kgpm3(float p, const float t) {
  float t_k = convtemp(t, TempUnit::C, TempUnit::K);
  if (p < 0.0f) {
    p = 0.0f;
  }
  if (t_k < 1.0f) {
    t_k = 1.0f;
  }
  return MOLECULAR_MASS_AIR_KGPMOL * p / (GAS_CONSTANT_JPKGMOL * t_k);
}
}  // namespace bfs
