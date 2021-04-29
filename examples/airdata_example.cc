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


#include <iostream>
#include "airdata/airdata.h"

int main() {
  float ias = bfs::Ias_mps(500.0f);
  std::cout << "IAS (m/s): " << ias << std::endl;  // 28.5457
  float eas = bfs::Eas_mps(500.0f, 90000.0f);
  std::cout << "EAS (m/s): " << eas << std::endl;  // 28.5429
  float tas = bfs::Tas_mps(eas, 17.0f);
  std::cout << "TAS (m/s): " << tas << std::endl;  // 28.6418
  float pa = bfs::PressureAltitude_m(90000.0f);
  std::cout << "Pressure Altitude (m): " << pa << std::endl;  // 988.518
  float da = bfs::DensityAltitude_m(90000.0f, 10.0f);
  std::cout << "Density Altitude (m): " << da << std::endl;  // 1039.88
  float oat = bfs::Oat_c(15.0f, 400.0f);
  std::cout << "OAT (C): " << oat << std::endl;  // 12.4
  float density = bfs::AirDensity_kgpm3(101325.0f, 15.0f);
  std::cout << "Air Density (kg/m^3): " << density << std::endl;  // 1.225
  return 0;
}
