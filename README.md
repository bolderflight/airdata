# Airdata
This library contains airdata functions.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *airdata*. The header is added as:

```
#include "airdata/airdata.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *airdata_example*, and an executable for testing using the Google Test framework, called *airdata_test*. The example executable source file is located at *examples/airdata_example.cc*.

## Namespace
This library is within the namespace *bfs*.

## Methods

**float Ias_mps(float p)** Returns indicated airspeed (m/s) given differential pressure (Pa)

```C++
float ias = bfs::Ias_mps(500.0f);
std::cout << "IAS (m/s): " << ias << std::endl;  // 28.5457
```

**float Eas_mps(float dp, float sp)** Returns equivalent airspeed (m/s) given differential pressure (Pa) and static pressure (Pa)

```C++
float eas = bfs::Eas_mps(500.0f, 90000.0f);
std::cout << "EAS (m/s): " << eas << std::endl;  // 28.5429
```

**float Tas_mps(float eas, float t)** Returns true airspeed (m/s) given equivalent airspeed (m/s) and temperature (C)

``` C++
float tas = bfs::Tas_mps(eas, 17);
std::cout << "TAS (m/s): " << tas << std::endl;  // 26.9964
```

**float PressureAltitude_m(float p)** Returns pressure altitue (m) given static pressure (Pa)

``` C++
float pa = bfs::PressureAltitude_m(90000);
std::cout << "Pressure Altitude (m): " << pa << std::endl;  // 988.1
```

**float DensityAltitude_m(float p, float t)** Returns density altitude (m) given static pressure (Pa) and temperature (C)

``` C++
float da = bfs::DensityAltitude_m(90000, 10);
std::cout << "Density Altitude (m): " << da << std::endl;  // 1039.88
```

**float Oat_c(float t, float agl)** Returns estimated outside air temperature (C) as a function of surface temperature (C) and altitude above ground (m)

``` C++
float oat = bfs::Oat_c(15, 400);
std::cout << "OAT (C): " << oat << std::endl;  // 12.4
```
 
**float AirDensity_kgpm3(float p, float t)** Returns air density (kg/m^3) given pressure (Pa) and temperature (C)

``` C++
float density = bfs::AirDensity_kgpm3(101325, 15);
std::cout << "Air Density (kg/m^3): " << density << std::endl;  // 1.225
```
