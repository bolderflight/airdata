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

namespace bfs {
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
}  // namespace bfs

#endif  // INCLUDE_AIRDATA_AIRDATA_H_
