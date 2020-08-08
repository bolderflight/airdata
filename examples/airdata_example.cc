/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include <iostream>
#include "types/types.h"

int main() {
  types::Pressure<float> dpress;
  dpress.pa(500.0f);
  types::LinVel<float> speed;
  speed.mps(30.0f);
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Pressure<float> stpress;
  stpress.pa(101325.0f);
  types::LinPos<float> alt;
  alt.m(500.0f);

  std::cout << "--- Inputs ---" << std::endl;
  std::cout << "Differential Pressure (pa): " << dpress.pa() << std::endl;
  std::cout << "Airspeed (m/s): " << speed.mps() << std::endl;
  std::cout << "Temperature (C): " << temp.c() << std::endl;
  std::cout << "Static Pressure (pa): " << stpress.pa() << std::endl;
  std::cout << "Altitude (m) AGL: " << alt.m() << std::endl;

  std::cout << "--- Functions ---" << std::endl;
  types::LinVel<float> ias = airdata::Ias(dpress);
  std::cout << "IAS (m/s): " << ias.mps() << std::endl;  // 28.5457
  types::LinVel<float> tas = airdata::Tas(speed, temp);
  std::cout << "TAS (m/s): " << tas.mps() << std::endl;  // 30
  types::LinPos<float> pa = airdata::PressureAltitude(stpress);
  std::cout << "Pressure Altitude (m): " << pa.m() << std::endl;  // 0
  types::LinPos<float> da = airdata::DensityAltitude(stpress, temp);
  std::cout << "Density Altitude (m): " << da.m() << std::endl;  // 0
  types::Temperature<float> eoat = airdata::Oat(temp, alt);
  std::cout << "OAT (C): " << eoat.c() << std::endl;  // 11.75
  types::Density<float> density = airdata::AirDensity(stpress, temp);
  std::cout << "Air Density (kg-m^3): " << density.kgpm3() << std::endl; // 1.225
  return 0;
}
