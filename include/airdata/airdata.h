/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
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

#ifndef INCLUDE_AIRDATA_AIRDATA_H_
#define INCLUDE_AIRDATA_AIRDATA_H_

#include <cmath>
#include <type_traits>
#include "units/units.h"

namespace bfs {
/*
* Computes indicated airspeed (m/s) from differential pressure (Pa)
*/
template<typename T>
T Ias_mps(const T p) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  if (p < static_cast<T>(0)) {return static_cast<T>(0);}
  return SEA_LEVEL_SPEED_OF_SOUND_MPS<T> * std::sqrt(static_cast<T>(5) *
    (std::pow(p / SEA_LEVEL_PRESSURE_PA<T> + static_cast<T>(1),
    static_cast<T>(2) / static_cast<T>(7)) - static_cast<T>(1)));
}
/*
* Computes equivalent airspeed (m/s) given differential pressure (Pa)
* and static pressure (Pa)
*/
template<typename T>
T Eas_mps(const T dp, const T sp) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  if ((dp < static_cast<T>(0)) || (sp < static_cast<T>(0.1))) {
    return static_cast<T>(0);
  }
  return SEA_LEVEL_SPEED_OF_SOUND_MPS<T> * std::sqrt(static_cast<T>(5) *
    sp / SEA_LEVEL_PRESSURE_PA<T> * (std::pow(dp / sp + static_cast<T>(1),
    static_cast<T>(2) / static_cast<T>(7)) - static_cast<T>(1)));
}
/*
* Computes true airspeed (m/s) given EAS (m/s) and temperature (C)
*/
template<typename T>
T Tas_mps(const T eas, const T t) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  T t_k = convtemp(t, TempUnit::C, TempUnit::K);
  if ((eas < static_cast<T>(0)) || (t_k < static_cast<T>(0))) {
    return static_cast<T>(0);
  }
  return eas * std::sqrt(t_k / SEA_LEVEL_TEMPERATURE_K<T>);
}
/*
* Pressure altitude (m) from static pressure (Pa)
*/
template<typename T>
T PressureAltitude_m(T p) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  if (p < static_cast<T>(0)) {
    p = static_cast<T>(0);
  }
  return SEA_LEVEL_TEMPERATURE_K<T> / LAPSE_RATE_KPM<T> *
    (static_cast<T>(1) - std::pow(p / SEA_LEVEL_PRESSURE_PA<T>,
    (LAPSE_RATE_KPM<T> * GAS_CONSTANT_JPKGMOL<T>) /
    (MOLECULAR_MASS_AIR_KGPMOL<T> * G_MPS2<T>)));
}
/*
* Density altitude (m) given static pressure (Pa) and temperature (C)
*/
template<typename T>
T DensityAltitude_m(T p, const T t) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  T t_k = convtemp(t, TempUnit::C, TempUnit::K);
  if (p < static_cast<T>(0)) {
    p = static_cast<T>(0);
  }
  if (t_k < static_cast<T>(1)) {
    t_k = static_cast<T>(1);
  }
  return SEA_LEVEL_TEMPERATURE_K<T> / LAPSE_RATE_KPM<T> *
    (static_cast<T>(1) - std::pow(p / SEA_LEVEL_PRESSURE_PA<T>
    * SEA_LEVEL_TEMPERATURE_K<T> / t_k,
    (LAPSE_RATE_KPM<T> * GAS_CONSTANT_JPKGMOL<T>) /
    (MOLECULAR_MASS_AIR_KGPMOL<T> * G_MPS2<T> -
    LAPSE_RATE_KPM<T> * GAS_CONSTANT_JPKGMOL<T>)));
}
/*
* Estimated outside air temperature (C) as a fuction of surface temperature (C)
* and AGL altitude (m) using lapse rate
*/
template<typename T>
T Oat_c(const T t, const T agl) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  return t - LAPSE_RATE_KPM<T> * agl;
}
/*
* Estimated air density (kg/m^3) from temperature (C) and pressure (Pa) 
*/
template<typename T>
T AirDensity_kgpm3(T p, const T t) {
  static_assert(std::is_floating_point<T>::value,
                "Only floating point types supported");
  T t_k = convtemp(t, TempUnit::C, TempUnit::K);
  if (p < static_cast<T>(0)) {
    p = static_cast<T>(0);
  }
  if (t_k < static_cast<T>(1)) {
    t_k = static_cast<T>(1);
  }
  return MOLECULAR_MASS_AIR_KGPMOL<T> * p / (GAS_CONSTANT_JPKGMOL<T> * t_k);
}
}  // namespace bfs

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
