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
types::Speed CalcIas(const types::DiffPressure &p);

/* 
* Returns true airspeed given airspeed and temperature 
*/
types::Speed CalcTas(const types::Speed &a, const types::Temperature &t);

/*
* Returns pressure altitue given static pressure
*/
types::Altitude CalcPressureAltitude(const types::StaticPressure &p);

/*
* Returns altitude Above Ground Level (AGL) given static pressure and a bias 
* altitude
*/
types::Altitude CalcAGL(const types::StaticPressure &p,
                        const types::Altitude &c);

/* 
* Returns altitude above Mean Sea Level (MSL) given AGL and starting altitude 
*/
types::Altitude CalcMSL(const types::Altitude &agl, const types::Altitude &alt);

/*
* Returns density altitude given static pressure temperature
*/
types::Altitude CalcDensityAltitude(const types::StaticPressure &p,
                                    const types::Temperature &t);

/*
* Returns estimated outside air temperature as a fuction of altitude
*/
types::Temperature CalcOAT(const types::Temperature &t,
                            const types::Altitude &h);

/* 
* Returns air density (kg-m^3) given temperature and pressure
*/
types::Density CalcDensity(const types::StaticPressure &p,
                            const types::Temperature &t);

}  // namespace airdata

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
