/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2023 Bolder Flight Systems Inc
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

#ifndef AIRDATA_SRC_AIRDATA_CONSTANTS_H_  // NOLINT
#define AIRDATA_SRC_AIRDATA_CONSTANTS_H_

/* Standard day sea level speed of sound, m/s */
static constexpr float SEA_LEVEL_SPEED_OF_SOUND_MPS = 340.29f;
/* Standard day sea level pressure, Pa */
static constexpr float SEA_LEVEL_PRESSURE_PA = 101325.0f;
/* Standard day sea level temperature, C */
static constexpr float SEA_LEVEL_TEMPERATURE_C = 15.0f;
/* Standard day sea level temperature, K */
static constexpr float SEA_LEVEL_TEMPERATURE_K = 288.15f;
/* Environmental lapse rate K/m */
static constexpr float LAPSE_RATE_KPM = 0.0065f;
/* Gas constant J/kg-mol */
static constexpr float GAS_CONSTANT_JPKGMOL = 8.31446261815324f;
/* Molecular mass of air, kg/mol */
static constexpr float MOLECULAR_MASS_AIR_KGPMOL = 0.0289644f;

#endif  // AIRDATA_SRC_AIRDATA_CONSTANTS_H_ NOLINT
