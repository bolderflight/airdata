/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_AIRDATA_H_
#define INCLUDE_AIRDATA_AIRDATA_H_

#include <stdlib.h>
#include "types/types.h"

namespace airdata {

/* 
* Returns indicated airspeed given differential pressure
*/
types::Speed GetIas(types::DiffPressure &p);

/* 
* Returns true airspeed given airspeed and temperature 
*/
types::Speed GetTas(types::Speed &a, types::Temperature &t);

/*
* Returns pressure altitue given static pressure
*/
types::Altitude GetPressureAltitude(types::StaticPressure &p);

/*
* Returns altitude Above Ground Level (AGL) given static pressure and a bias 
* altitude
*/
types::Altitude GetAGL(types::StaticPressure &p, types::Altitude &c);

/* 
* Returns altitude above Mean Sea Level (MSL) given AGL and starting altitude 
*/
types::Altitude GetMSL(types::Altitude &agl, types::Altitude &alt);

/*
* Returns density altitude given static pressure temperature
*/
types::Altitude GetDensityAltitude(types::StaticPressure &p,
                                    types::Temperature &t);

/*
* Returns estimated outside air temperature as a fuction of altitude
*/
types::Temperature EstimateOAT(types::Temperature &t, types::Altitude &h);

/* 
* Returns air density (kg-m^3) given temperature and pressure
*/
float GetDensity_kgm3(types::StaticPressure &p, types::Temperature &t);

}  // namespace airdata

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
