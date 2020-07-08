# Airdata
This library contains airdata functions and classes.
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

This will build the library, an example executable called *airdata_example*, and an executable for testing using the Google Test framework, called *airdata_test*. The example executable source file is located at *examples/airdata_example.cc*. This code is built and tested on an AMD64 system running Linux and is likely to build on AMD64 systems running the Windows Subsystem for Linux (WSL). As an alternative, a Docker container has been [built](https://hub.docker.com/r/flybrianfly/gcc-cmake) which extends the gcc container to include CMake support and supports building this library.

## Namespace
This library is within the namespace *airdata*.

## Methods

**types::Speed CalcIas(const types::DiffPressure &p)** Returns indicated airspeed given differential pressure
```C++
types::Speed ias = airdata::CalcIas(dpress);
std::cout << "IAS (m/s): " << ias.mps() << std::endl;  // 28.5457
```

**types::Speed CalcTas(const types::Speed &a, const types::Temperature &t)** Returns true airspeed given airspeed and temperature
``` C++
types::Speed tas = airdata::CalcTas(speed, temp);
std::cout << "TAS (m/s): " << tas.mps() << std::endl;  // 30
```

**types::Altitude CalcPressureAltitude(const types::StaticPressure &p)** Returns pressure altitue given static pressure
``` C++
types::Altitude pa = airdata::CalcPressureAltitude(stpress);
std::cout << "Pressure Altitude (m): " << pa.m() << std::endl;  // 0
```

**types::Altitude CalcAGL(const types::StaticPressure &p, const types::Altitude &c)** Returns altitude Above Ground Level (AGL) given static pressure and a bias
``` C++
types::Altitude AGL = airdata::CalcAGL(stpress, bias);
std::cout << "AGL (m): " << AGL.m() << std::endl;  // -100
  
```

**types::Altitude CalcMSL(const types::Altitude &agl, const types::Altitude &alt)** Returns altitude above Mean Sea Level (MSL) given AGL and starting altitude
``` C++
types::Altitude msl = airdata::CalcMSL(agl, alt);
std::cout << "MSL (m): " << msl.m() << std::endl;  // 1000
```

**types::Altitude CalcDensityAltitude(const types::StaticPressure &p, const types::Temperature &t)** Returns density altitude given static pressure and temperature
``` C++
types::Altitude da = airdata::CalcDensityAltitude(stpress, temp);
std::cout << "Density Altitude (m): " << da.m() << std::endl;  // 0
```

**types::Temperature CalcOAT(const types::Temperature &t, const types::Altitude &h)** Returns estimated outside air temperature as a fuction of altitude
``` C++
types::Temperature eoat = airdata::CalcOAT(temp, alt);
std::cout << "OAT (C): " << eoat.c() << std::endl;  // 11.75
```
 
**types::Density CalcDensity(const types::StaticPressure &p, const types::Temperature &t)** Returns air density given temperature and pressure
``` C++
types::Density density = airdata::CalcDensity(stpress, temp);
st  d::cout << "Air Density (kg-m^3): " << density.kgpm3() << std::endl;// 1.225
```
