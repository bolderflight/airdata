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

Note that you'll need CMake version 3.13 or above; it is recommended to build and install CMake from source, directions are located in the [CMake GitLab repository](https://github.com/Kitware/CMake).

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *airdata_example*, and an executable for testing using the Google Test framework, called *airdata_test*. The example executable source file is located at *examples/airdata_example.cc*. This code is built and tested on AMD64 and AARCH64 systems running Linux and on AMD64 systems running the Windows Subsystem for Linux (WSL).

## Namespace
This library is within the namespace *airdata*.

## Methods

**types::Speed Ias(const types::Pressure &p)** Returns indicated airspeed given differential pressure
```C++
types::Pressure<float> dpress;
dpress.pa(500.0f);
types::Speed<float> ias = airdata::Ias(dpress);
std::cout << "IAS (m/s): " << ias.mps() << std::endl;  // 28.5457
```

**types::Speed Tas(const types::Speed &a, const types::Temperature &t)** Returns true airspeed given airspeed and temperature
``` C++
types::Speed<float> speed;
speed.mps(30.0f);
types::Temperature<float> temp;
temp.c(15.0f);
types::Speed<float> tas = airdata::Tas(speed, temp);
std::cout << "TAS (m/s): " << tas.mps() << std::endl;  // 30
```

**types::Altitude PressureAltitude(const types::StaticPressure &p)** Returns pressure altitue given static pressure
``` C++
types::Pressure<float> stpress;
stpress.pa(101325.0f);
types::Altitude<float> pa = airdata::PressureAltitude(stpress);
std::cout << "Pressure Altitude (m): " << pa.m() << std::endl;  // 0
```

**types::Altitude DensityAltitude(const types::StaticPressure &p, const types::Temperature &t)** Returns density altitude given static pressure and temperature
``` C++
types::Pressure<float> stpress;
stpress.pa(101325.0f);
types::Temperature<float> temp;
temp.c(15.0f);
types::Altitude<float> da = airdata::DensityAltitude(stpress, temp);
std::cout << "Density Altitude (m): " << da.m() << std::endl;  // 0
```

**types::Temperature Oat(const types::Temperature &t, const types::Altitude &h)** Returns estimated outside air temperature as a fuction of altitude
``` C++
types::Temperature<float> temp;
temp.c(15.0f);
types::Altitude<float> alt;
alt.m(500.0f);
types::Temperature<float> eoat = airdata::Oat(temp, alt);
std::cout << "OAT (C): " << eoat.c() << std::endl;  // 11.75
```
 
**types::Density AirDensity(const types::StaticPressure &p, const types::Temperature &t)** Returns air density given temperature and pressure
``` C++
types::Pressure<float> stpress;
stpress.pa(101325.0f);
types::Temperature<float> temp;
temp.c(15.0f);
types::Density<float> density = airdata::AirDensity(stpress, temp);
std::cout << "Air Density (kg-m^3): " << density.kgpm3() << std::endl;// 1.225
```
