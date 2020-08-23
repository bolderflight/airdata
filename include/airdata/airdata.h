/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_AIRDATA_H_
#define INCLUDE_AIRDATA_AIRDATA_H_

namespace airdata {
/*
* Computes indicated airspeed (m/s) from differential pressure (Pa)
*/
float Ias_mps(float p);
/*
* Computes equivalent airspeed (m/s) given IAS (m/s) and static pressure (Pa)
*/
float Eas_mps(float ias, float p);
/*
* Computes true airspeed (m/s) given EAS (m/s) and temperature (C)
*/
float Tas_mps(float eas, float t);
/*
* Pressure altitude (m) from static pressure (Pa)
*/
float PressureAltitude_m(float p);
/*
* Density altitude (m) given static pressure (Pa) and temperature (C)
*/
float DensityAltitude_m(float p, float t);
/*
* Estimated outside air temperature (C) as a fuction of surface temperature (C)
* and AGL altitude (m) using lapse rate
*/
float Oat_c(float t, float agl);
/*
* Estimated air density (kg/m^3) from temperature (C) and pressure (Pa) 
*/
float AirDensity_kgpm3(float p, float t);
}  // namespace airdata

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
