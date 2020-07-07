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

**float CalcIas_ms(float qc_pa)** Returns indicated airspeed given differential pressure
```C++
std::cout << "IAS (m/s): " << airdata::CalcIas_ms(qc_pa) << std::endl;  // 28.5457
```

**float CalcTas_ms(float AS_ms, float T_C)** Returns true airspeed given airspeed and temperature
``` C++
std::cout << "TAS (m/s): " << airdata::CalcTas_ms(AS_ms, T_C) << std::endl;  // 30
```

**float CalcPressureAltitude_m(float p_pa)** Returns pressure altitue given static pressure
``` C++
std::cout << "Pressure Altitude (m): " << airdata::CalcPressureAltitude_m(p_pa) << std::endl;  // 0
```

**float CalcAGL_m(float p_pa, float c_m)** Returns altitude Above Ground Level (AGL) given static pressure and a bias
``` C++
std::cout << "AGL (m): " << airdata::CalcAGL_m(p_pa, c_m) << std::endl;  // -100
  
```

**float CalcMSL_m(float H_m, float h_m)** Returns altitude above Mean Sea Level (MSL) given AGL and starting altitude
``` C++
std::cout << "MSL (m): " << airdata::CalcMSL_m(H_m, h_m) << std::endl;  // 1000
```

**float CalcDensityAltitude_m(float p_pa, float T_C)** Returns density altitude given static pressure and temperature
``` C++
std::cout << "Density Altitude (m): " <<airdata::CalcDensityAltitude_m(p_pa, T_C) << std::endl;  // 0
```

**float CalcOAT_C(float T_C, float h_m)** Returns estimated outside air temperature as a fuction of altitude
``` C++
std::cout << "OAT (C): " << airdata::CalcOAT_C(T_C, h_m) << std::endl;  
// 11.75
```
 
**float CalcDensity_kgm3(float p_pa, float T_C)** Returns air density given temperature and pressure
``` C++
std::cout << "Air Density (kg-m^3): " << airdata::CalcDensity_kgm3(p_pa, T_C) << std::endl;  // 1.225
```
