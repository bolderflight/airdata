/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include <iostream>

int main() {
  float qc_pa = 500.0f;
  float AS_ms = 30.0f;
  float T_C = 15.0f;
  float p_pa = 101325.0f;
  float c_m = 100.0f;
  float H_m = 500.0f;
  float h_m = 500.0f;

  std::cout << "--- Inputs ---" << std::endl;
  std::cout << "Differential Pressure (pa): " << qc_pa << std::endl;
  std::cout << "Airspeed (m/s): " << AS_ms << std::endl;
  std::cout << "Temperature (C): " << T_C << std::endl;
  std::cout << "Static Pressure (pa): " << p_pa << std::endl;
  std::cout << "Bias (m): " << c_m << std::endl;
  std::cout << "Given AGL (m): " << H_m << std::endl;
  std::cout << "Starting Altitude (m): " << h_m << std::endl;

  std::cout << "--- Functions ---" << std::endl;
  std::cout << "IAS (m/s): " << airdata::GetIas_ms(qc_pa) << std::endl;
    // 28.5457
  std::cout << "TAS (m/s): " << airdata::GetTas_ms(AS_ms, T_C) << std::endl;
    // 30
  std::cout << "Pressure Altitude (m): " <<
    airdata::GetPressureAltitude_m(p_pa) << std::endl;  // 0
  std::cout << "AGL (m): " << airdata::GetAGL_m(p_pa, c_m) << std::endl;
    // -100
  std::cout << "MSL (m): " << airdata::GetMSL_m(H_m, h_m) << std::endl;
    // 1000
  std::cout << "Density Altitude (m): " <<
    airdata::GetDensityAltitude_m(p_pa, T_C) << std::endl;  // 0
  std::cout << "Estimated OAT (C): " << airdata::EstimateOAT_C(T_C, h_m) <<
    std::endl;  // 11.75
  std::cout << "Air Density (kg-m^3): " <<
    airdata::GetDensity_kgm3(p_pa, T_C) << std::endl;  // 1.225

  return 0;
}