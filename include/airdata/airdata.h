/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_AIRDATA_H_
#define INCLUDE_AIRDATA_AIRDATA_H_

#include "airdata/constants.h"
#include "global_defs/global_defs.h"
#include <cmath>

namespace airdata {
/* Computes indicated airspeed (m/s) from differential pressure (Pa) */
template<typename T>
T Ias(const T &p) {
  if (p < static_cast<T>(0)) {return static_cast<T>(0);}
  return constants::STD_SEA_LEVEL_SPEED_OF_SOUND_MPS<T> * std::sqrt(static_cast<T>(5) * (std::pow(p / constants::STD_SEA_LEVEL_PRESSURE_PA<T> + static_cast<T>(1), static_cast<T>(2) / static_cast<T>(7)) - static_cast<T>(1)));
}
/* Computes equivalent airspeed (m/s) given IAS (m/s) and static pressure (Pa) */
template<typename T>
T Eas(const T &ias, const T &p) {
  if ((ias < static_cast<T>(0)) || (p < static_cast<T>(0))) {
    return static_cast<T>(0);
  }
  return ias * std::sqrt(p / constants::STD_SEA_LEVEL_PRESSURE_PA<T>);
}
/* Computes true airspeed (m/s) given EAS (m/s) and temperature (C) */
template<typename T>
T Tas(const T &eas, const T &t) {
  /* Convert temperature to K */
  T t_k = global::conversions::C_to_K<T>(t);
  if ((eas < static_cast<T>(0)) || (t_k < static_cast<T>(0))) {
    return static_cast<T>(0);
  }
  return eas * std::sqrt(t_k / constants::STD_SEA_LEVEL_TEMPERATURE_K<T>);
}
/* Pressure altitude (m) from static pressure (Pa) */
template<typename T>
T PressureAltitude(const T &p) {
  T p_sat = p;
  if (p_sat < static_cast<T>(0)) {
    p_sat = static_cast<T>(0);
  }
  return constants::STD_SEA_LEVEL_TEMPERATURE_K<T> / constants::LAPSE_RATE_KPM<T> * (static_cast<T>(1) - std::pow(p_sat / constants::STD_SEA_LEVEL_PRESSURE_PA<T>, (constants::LAPSE_RATE_KPM<T> * constants::GAS_CONSTANT_JPKGMOL<T>) / (constants::MOLECULAR_MASS_AIR_KGPMOL<T> * global::constants::G_MPS2<T>)));
}
/* Density altitude (m) given static pressure (Pa) and temperature (C) */
template<typename T>
T DensityAltitude(const T &p, const T &t) {
  T p_sat = p;;
  T t_sat = global::conversions::C_to_K(t);
  if (p_sat < static_cast<T>(0)) {
    p_sat = static_cast<T>(0);
  }
  if (t_sat < static_cast<T>(1)) {
    t_sat = static_cast<T>(1);
  }
  return constants::STD_SEA_LEVEL_TEMPERATURE_K<T> / constants::LAPSE_RATE_KPM<T> * (static_cast<T>(1) - std::pow(p_sat / constants::STD_SEA_LEVEL_PRESSURE_PA<T> * constants::STD_SEA_LEVEL_TEMPERATURE_K<T> / t_sat, (constants::LAPSE_RATE_KPM<T> * constants::GAS_CONSTANT_JPKGMOL<T>) / (constants::MOLECULAR_MASS_AIR_KGPMOL<T> * global::constants::G_MPS2<T> - constants::LAPSE_RATE_KPM<T> * constants::GAS_CONSTANT_JPKGMOL<T>)));
}
/* Estimated outside air temperature (C) as a fuction of surface temperature (C) and AGL altitude (m) using lapse rate */
template<typename T>
T Oat(const T &t, const T &agl) {
  return t - constants::LAPSE_RATE_KPM<T> * agl;
}
/* Estimated air density (kg/m^3) from temperature (C) and pressure (Pa) */
template<typename T>
T AirDensity(const T &p, const T &t) {
  T t_sat = global::conversions::C_to_K(t);
  if (p < static_cast<T>(0)) {
    return static_cast<T>(0);
  }
  if (t_sat < static_cast<T>(1)) {
    t_sat = static_cast<T>(1);
  }
  return constants::MOLECULAR_MASS_AIR_KGPMOL<T> * p / (constants::GAS_CONSTANT_JPKGMOL<T> * t_sat);
}
}  // namespace airdata

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
