[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Airdata
This library contains functions for computing indicated airspeed, equivalent airspeed, true airspeed, pressure altitude, density altitude, and estimating outside air temperature (OAT) and air density. This library is compatible with Arduino and with CMake build systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Installation

## Arduino
Use the Arduino Library Manager to install this library or clone to your Arduino/libraries folder. Additionally, the [Bolder Flight Systems Units library](https://github.com/bolderflight/units) must be installed. This library is added as:

```C++
#include "airdata.h"
```

An example Arduino executable is located at *examples/arduino/airdata_example/airdata_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other devices.

## CMake
CMake is used to build this library, which is exported as a library target called *airdata*. The header is added as:

```C++
#include "airdata.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *airdata_example*, and an executable for testing using the Google Test framework, called *airdata_test*. The example executable source file is located at *examples/cmake/airdata_example.cc*.

# Namespace
This library is within the namespace *bfs*.

# Constants

Standard day sea level speed of sound (m/s), pressure (Pa), and temperature(C, K) are defined as constants *SEA_LEVEL_SPEED_OF_SOUND_MPS*, *SEA_LEVEL_PRESSURE_PA*, *SEA_LEVEL_TEMPERATURE_C*, and *SEA_LEVEL_TEMPERATURE_K*.

```C++
float a_mps = bfs::SEA_LEVEL_SPEED_OF_SOUND_MPS;
float p0_pa = bfs::SEA_LEVEL_PRESSURE_PA;
float t0_c = bfs::SEA_LEVEL_TEMPERATURE_C;
float t0_k = bfs::SEA_LEVEL_TEMPERATURE_K;
```

Environmental lapse rate (K/m or C/m) is defined as a constant *LAPSE_RATE_KPM*.

```C++
float l = bfs::LAPSE_RATE_KPM;
```

The gas constant (J/(kg mol)) and molecular mas (kg/mol) of air are defined as constants *GAS_CONSTANT_JPKGMOL* and *MOLECULAR_MASS_AIR_KGPMOL*.

```C++
float r = bfs::GAS_CONSTANT_JPKGMOL;
float m = bfs::MOLECULAR_MASS_AIR_KGPMOL;
```

# Functions

**float Ias_mps(const float p)** Returns indicated airspeed (m/s) given differential pressure (Pa)

```C++
float ias = bfs::Ias_mps(500.0f);
std::cout << "IAS (m/s): " << ias << std::endl;  // 28.5457
```

**float Eas_mps(const float dp, const float sp)** Returns equivalent airspeed (m/s) given differential pressure (Pa) and static pressure (Pa)

```C++
float eas = bfs::Eas_mps(500.0f, 90000.0f);
std::cout << "EAS (m/s): " << eas << std::endl;  // 28.5429
```

**float Tas_mps(const float eas, const float t)** Returns true airspeed (m/s) given equivalent airspeed (m/s) and temperature (C)

``` C++
float tas = bfs::Tas_mps(eas, 17);
std::cout << "TAS (m/s): " << tas << std::endl;  // 28.6418
```

**float PressureAltitude_m(const float p)** Returns pressure altitue (m) given static pressure (Pa)

``` C++
float pa = bfs::PressureAltitude_m(90000);
std::cout << "Pressure Altitude (m): " << pa << std::endl;  // 988.1
```

**float DensityAltitude_m(const float p, const float t)** Returns density altitude (m) given static pressure (Pa) and temperature (C)

``` C++
float da = bfs::DensityAltitude_m(90000, 10);
std::cout << "Density Altitude (m): " << da << std::endl;  // 1039.88
```

**float Oat_c(const float t, const float agl)** Returns estimated outside air temperature (C) as a function of surface temperature (C) and altitude above ground (m). Uses a standard lapse rate of 6.5 C per km.

``` C++
float oat = bfs::Oat_c(15, 400);
std::cout << "OAT (C): " << oat << std::endl;  // 12.4
```
 
**float AirDensity_kgpm3(const float p, const float t)** Returns air density (kg/m^3) given pressure (Pa) and temperature (C)

``` C++
float density = bfs::AirDensity_kgpm3(101325, 15);
std::cout << "Air Density (kg/m^3): " << density << std::endl;  // 1.225
```
