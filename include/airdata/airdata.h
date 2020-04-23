/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_AIRDATA_H_
#define INCLUDE_AIRDATA_AIRDATA_H_

#include <stdlib.h>

namespace airdata {

/* 
* Returns indicated airspeed (m/s) given differential pressure (Pa) 
*/
float GetIas_ms(float qc_pa);

/* 
* Returns true airspeed (m/s) given airspeed (m/s) and temperature (C) 
*/
float GetTas_ms(float AS_ms, float T_C);

/*
* Returns pressure altitue (m) given static pressure (Pa)
*/
float GetPressureAltitude_m(float p_pa);

/*
* Returns altitude Above Ground Level (AGL) (m) given static pressure (pa) and a bias (m)
*/
float GetAGL_m(float p_pa, float c_m);

/* 
* Returns altitude above Mean Sea Level (MSL) (m) given AGL (m) and starting altitude (m) 
*/
float GetMSL_m(float H_m, float h_m);

/*
* Returns density altitude (m) given static pressure (pa) and temperature (C) 
*/
float GetDensityAltitude_m(float p_pa, float T_C);

/*
* Returns estimated outside air temperature (C) as a fuction of altitude (m) 
*/
float EstimateOAT_C(float T_C, float h_m);

/* 
* Returns air density (kg-m^3) given temperature (C) and pressure (pa) 
*/
float GetDensity_kgm3(float p_pa, float T_C);

}  // namespace airdata

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
