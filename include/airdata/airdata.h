/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#ifndef AIRDATA_H
#define AIRDATA_H

#include <stdlib.h>

namespace airdata {
/* 
* Returns indicated airspeed (m/s) given differential pressure (Pa) 
*/
float GetIas_ms(float qc_pa);
/* 
* Returns equivalent airspeed (m/s) given airspeed (m/s)
* and static pressure (Pa).
*/
float GetEas_ms(float ias_ms, float p_pa);
/* 
* Returns true airspeed (m/s) given airspeed (m/s) and temperature (C) 
*/
float GetTAS_ms(float AS, float T);

float GetPressureAltitude_m(float p);
float GetAGL_m(float p, float c);
float GetMSL_m(float H, float h);
float GetDensityAltitude_m(float p, float T);
float EstimateOAT_C(float T, float h);
float GetDensity_kgm3(float p, float T);

} // airdata

#endif
