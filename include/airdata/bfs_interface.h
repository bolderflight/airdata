/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_BFS_INTERFACE_H_
#define INCLUDE_AIRDATA_BFS_INTERFACE_H_

#include "types/types.h"
#include "airdata/airdata.h"

namespace airdata {
/* Computes indicated airspeed from differential pressure. */
types::Ias Ias(const types::DiffPressure &p) {
  types::Ias ias;
  ias.mps(Ias(p.pa()));
  return ias;
}
/* Computes equivalent airspeed from IAS and static pressure */
types::Eas Eas(const types::Ias &ias, const types::StaticPressure &p) {
  types::Eas eas;
  eas.mps(Eas(ias.mps(), p.pa()));
  return eas;
}
/* Computes true airspeed given EAS and temperature */
types::Tas Tas(const types::Eas &eas, const types::Oat &t) {
  types::Tas tas;
  tas.mps(Tas(eas.mps(), t.c()));
  return tas;
}
/* Pressure altitude from static pressure */
types::PressureAltitude PressureAltitude(const types::StaticPressure &p) {
  types::PressureAltitude press_alt;
  press_alt.m(PressureAltitude(p.pa()));
  return press_alt;
}
/* Density altitude given static pressure and temperature */
types::DensityAltitude DensityAltitude(const types::StaticPressure &p, const types::Oat &t) {
  types::DensityAltitude da;
  da.m(DensityAltitude(p.pa(), t.c()));
  return da;
}
/* Estimated outside air temperature as a fuction of surface temperature and AGL altitude using lapse rate */
types::Oat Oat(const types::Oat &surface_oat, const types::AglAltitude &agl) {
  types::Oat oat;
  oat.c(Oat(surface_oat.c(), agl.m()));
  return oat;
}
/* Estimated air density from temperature and pressure */
types::AirDensity AirDensity(const types::StaticPressure &p, const types::Oat &t) {
  types::AirDensity air_density;
  air_density.kgpm3(AirDensity(p.pa(), t.c()));
  return air_density;
}

}  // namespace airdata

#endif  // INCLUDE_AIRDATA_BFS_INTERFACE_H_
