/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#ifndef INCLUDE_AIRDATA_CONSTANTS_H_
#define INCLUDE_AIRDATA_CONSTANTS_H_

namespace airdata {
namespace constants {
template<typename T>
static constexpr T STD_SEA_LEVEL_SPEED_OF_SOUND_MPS = static_cast<T>(340.29);
template<typename T>
static constexpr T STD_SEA_LEVEL_PRESSURE_PA = static_cast<T>(101325);
template<typename T>
static constexpr T STD_SEA_LEVEL_TEMPERATURE_C = static_cast<T>(15);
template<typename T>
static constexpr T STD_SEA_LEVEL_TEMPERATURE_K = static_cast<T>(288.15);
template<typename T>
static constexpr T LAPSE_RATE_KPM = static_cast<T>(0.0065);
template<typename T>
static constexpr T GAS_CONSTANT_JPKGMOL = static_cast<T>(8.31446261815324);
template<typename T>
static constexpr T MOLECULAR_MASS_AIR_KGPMOL = static_cast<T>(0.0289644);
}  // namespace constants
}  // namespace airdata

#endif  // INCLUDE_AIRDATA_CONSTANTS_H_
