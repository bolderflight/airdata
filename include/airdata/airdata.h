/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_AIRDATA_H_
#define INCLUDE_AIRDATA_AIRDATA_H_

#include "types/types.h"
#include "airdata/constants.h"
#include "global_defs/global_defs.h"

namespace airdata {
/* Computes indicated airspeed from differential pressure */
template<typename T>
types::LinVel<T> Ias(const types::Pressure<T> &p) {
  types::LinVel<T> ias;
  if (p.pa() < 0) {
    ias.mps(0);
    return ias;
  }
  ias.mps(constants::STD_SEA_LEVEL_SPEED_OF_SOUND_MPS<T> * std::sqrt(static_cast<T>(5) * (std::pow(p.pa() / constants::STD_SEA_LEVEL_PRESSURE_PA<T> + static_cast<T>(1), static_cast<T>(2) / static_cast<T>(7)) - static_cast<T>(1))));
  return ias;
}
/* Computes equivalent airspeed given IAS and static pressure */
template<typename T>
types::LinVel<T> Eas(const types::LinVel<T> &ias, const types::Pressure<T> &p) {
  types::LinVel<T> eas;
  if ((ias.mps() < 0) || (p.pa() < 0)) {
    eas.mps(0);
    return eas;
  }
  eas.mps(ias.mps() * std::sqrt(p.pa() / constants::STD_SEA_LEVEL_PRESSURE_PA<T>));
}
/* Computes true airspeed given EAS and temperature */
template<typename T>
types::LinVel<T> Tas(const types::LinVel<T> &eas, const types::Temperature<T> &t) {
  types::LinVel<T> tas;
  if ((eas.mps() < 0) || (t.k() < 0)) {
    tas.mps(0);
    return tas;
  }
  tas.mps(eas.mps() * std::sqrt(t.k() / constants::STD_SEA_LEVEL_TEMPERATURE_K<T>));
  return tas;
}
/* Pressure altitude from static pressure */
template<typename T>
types::LinPos<T> PressureAltitude(const types::Pressure<T> &p) {
  types::LinPos<T> pa;
  types::Pressure<T> p_sat(p);
  if (p_sat.pa() < 0) {
    p_sat.pa(0);
  }
  pa.m(constants::STD_SEA_LEVEL_TEMPERATURE_K<T> / constants::LAPSE_RATE_KPM<T> * (static_cast<T>(1) - std::pow(p_sat.pa() / constants::STD_SEA_LEVEL_PRESSURE_PA<T>, (constants::LAPSE_RATE_KPM<T> * constants::GAS_CONSTANT_JPKGMOL<T>) / (constants::MOLECULAR_MASS_AIR_KGPMOL<T> * global::constants::G_MPS2<T>))));
  return pa;
}
/* Density altitude given static pressure temperature */
template<typename T>
types::LinPos<T> DensityAltitude(const types::Pressure<T> &p, const types::Temperature<T> &t) {
  types::LinPos<T> da;
  types::Pressure<T> p_sat(p);
  types::Temperature<T> t_sat(t);
  if (p_sat.pa() < 0) {
    p_sat.pa(0);
  }
  if (t_sat.k() < 1) {
    t_sat.k(1);
  }
  da.m(constants::STD_SEA_LEVEL_TEMPERATURE_K<T> / constants::LAPSE_RATE_KPM<T> * (static_cast<T>(1) - std::pow(p_sat.pa() / constants::STD_SEA_LEVEL_PRESSURE_PA<T> * constants::STD_SEA_LEVEL_TEMPERATURE_K<T> / t_sat.k(), (constants::LAPSE_RATE_KPM<T> * constants::GAS_CONSTANT_JPKGMOL<T>) / (constants::MOLECULAR_MASS_AIR_KGPMOL<T> * global::constants::G_MPS2<T> - constants::LAPSE_RATE_KPM<T> * constants::GAS_CONSTANT_JPKGMOL<T>))));
  return da;
}
/* Estimated outside air temperature as a fuction of AGL altitude using lapse rate */
template<typename T>
types::Temperature<T> Oat(const types::Temperature<T> &t, const types::LinPos<T> &agl) {
  types::Temperature<T> oat;
  oat.c(t.c() - constants::LAPSE_RATE_KPM<T> * agl.m());
  return oat;
}
/* Estimated air density from temperature and pressure */
template<typename T>
types::Density<T> AirDensity(const types::Pressure<T> &p, const types::Temperature<T> &t) {
  types::Density<T> air_density;
  types::Temperature<T> t_sat(t);
  if (p.pa() < 0) {
    air_density.kgpm3(0);
    return air_density;
  }
  if (t_sat.k() < 1) {
    t_sat.k(1);
  }
  air_density.kgpm3(constants::MOLECULAR_MASS_AIR_KGPMOL<T> * p.pa() / (constants::GAS_CONSTANT_JPKGMOL<T> * t_sat.k()));
  return air_density;
}

}  // namespace airdata

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
