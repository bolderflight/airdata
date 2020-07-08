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
  types::DiffPressure dpress;
  dpress.pa(500.0f);

  types::Speed speed;
  speed.mps(30.0f);

  types::Temperature temp;
  temp.c(15.0f);

  types::StaticPressure stpress;
  stpress.pa(101325.0f);

  types::Altitude bias;
  bias.m(100.0f);

  types::Altitude agl;
  agl.m(500.0f);

  types::Altitude alt;
  alt.m(500.0f);

  std::cout << "--- Inputs ---" << std::endl;
  std::cout << "Differential Pressure (pa): " << dpress.pa() << std::endl;
  std::cout << "Airspeed (m/s): " << speed.mps() << std::endl;
  std::cout << "Temperature (C): " << temp.c() << std::endl;
  std::cout << "Static Pressure (pa): " << stpress.pa() << std::endl;
  std::cout << "Bias (m): " << bias.m() << std::endl;
  std::cout << "Given AGL (m): " << agl.m() << std::endl;
  std::cout << "Starting Altitude (m): " << alt.m() << std::endl;

  std::cout << "--- Functions ---" << std::endl;

  types::Speed ias = airdata::CalcIas(dpress);
  std::cout << "IAS (m/s): " << ias.mps() << std::endl;  // 28.5457

  types::Speed tas = airdata::CalcTas(speed, temp);
  std::cout << "TAS (m/s): " << tas.mps() << std::endl;  // 30

  types::Altitude pa = airdata::CalcPressureAltitude(stpress);
  std::cout << "Pressure Altitude (m): " << pa.m() << std::endl;  // 0

  types::Altitude AGL = airdata::CalcAGL(stpress, bias);
  std::cout << "AGL (m): " << AGL.m() << std::endl;  // -100

  types::Altitude msl = airdata::CalcMSL(agl, alt);
  std::cout << "MSL (m): " << msl.m() << std::endl;  // 1000

  types::Altitude da = airdata::CalcDensityAltitude(stpress, temp);
  std::cout << "Density Altitude (m): " << da.m() << std::endl;  // 0

  types::Temperature eoat = airdata::CalcOAT(temp, alt);
  std::cout << "OAT (C): " << eoat.c() << std::endl;  // 11.75

  types::Density density = airdata::CalcDensity(stpress, temp);
  std::cout << "Air Density (kg-m^3): " << density.kgpm3() << std::endl;
        // 1.225

  return 0;
}
