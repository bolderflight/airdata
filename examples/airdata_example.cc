/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include <iostream>
#include "airdata/airdata.h"

int main() {
  float ias = airdata::Ias_mps(500.0f);
  std::cout << "IAS (m/s): " << ias << std::endl;  // 28.5457
  float eas = airdata::Eas_mps(500, 90000.0f);
  std::cout << "EAS (m/s): " << eas << std::endl;  // 26.9032
  float tas = airdata::Tas_mps(eas, 17);
  std::cout << "TAS (m/s): " << tas << std::endl;  // 26.9964
  float pa = airdata::PressureAltitude_m(90000);
  std::cout << "Pressure Altitude (m): " << pa << std::endl;  // 988.518
  float da = airdata::DensityAltitude_m(90000, 10);
  std::cout << "Density Altitude (m): " << da << std::endl;  // 1039.88
  float oat = airdata::Oat_c(15, 400);
  std::cout << "OAT (C): " << oat << std::endl;  // 12.4
  float density = airdata::AirDensity_kgpm3(101325, 15);
  std::cout << "Air Density (kg/m^3): " << density << std::endl;  // 1.225
  return 0;
}
