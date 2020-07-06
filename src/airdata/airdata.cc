/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include <math.h>
#include "types/types.h"

namespace airdata {

namespace {
static constexpr float A0 = 340.29f;  // standard sea level speed of sound, m/s
static constexpr float P0 = 101325.0f;  // standard sea level pressure, Pa
static constexpr float T0 = 288.15f;    // standard sea level temperature, K
static constexpr float L = 0.0065f;     // standard lapse rate, K/m
static constexpr float R = 8.31432f;    // gas constant, J/kg-mol
static constexpr float M = 0.0289644f;  // molecular mass dry air, kg/mol
static constexpr float G = 9.80665f;    // acceleration due to gravity, m/s/s

}  // anonymous

types::Speed GetIas(types::DiffPressure &p) {
  types::Speed ias;

  if (p.pa() < 0.0f) {
    p.pa(0.0f);
  }
  ias.mps(A0 * sqrtf(5.0f *
    (powf((p.pa() / P0 + 1.0f), (2.0f / 7.0f)) - 1.0f)));

  return ias;
}

types::Speed GetTas(types::Speed &a, types::Temperature &t) {
  types::Speed tas;

  if (a.mps() < 0.0f) {
    a.mps(0.0f);
  }
  tas.mps(a.mps() * sqrtf((t.k()/T0)));

  return tas;
}

types::Altitude GetPressureAltitude(types::StaticPressure &p) {
  types::Altitude pa;

  if (p.pa() < 0.0f) {
    p.pa(0.0f);
  }
  pa.m((T0/L)*(1.0f - powf((p.pa()/P0), ((L*R)/(M*G)))));

  return pa;
}

types::Altitude GetAGL(types::StaticPressure &p, types::Altitude &c) {
  types::Altitude AGL;
  types::Altitude press_alt = GetPressureAltitude(p);
  AGL.m(press_alt.m() - c.m());

  return AGL;
}

types::Altitude GetMSL(types::Altitude &agl, types::Altitude &alt) {
  types::Altitude MSL;

  MSL.m(agl.m() + alt.m());

  return MSL;
}

types::Altitude GetDensityAltitude(types::StaticPressure &p,
                                    types::Temperature &t) {
  types::Altitude da;
  if (p.pa() < 0.0f) {
    p.pa(0.0f);
  }
  da.m((T0/L)*(1.0f - powf(((p.pa()/P0)*(T0/(t.k()))),
    ((L*R)/(M*G - L*R)))));

  return da;
}

types::Temperature EstimateOAT(types::Temperature &t, types::Altitude &h) {
  types::Temperature eoat;
  eoat.k(t.k()-L*h.m());

  return eoat;
}

float GetDensity_kgm3(types::StaticPressure &p, types::Temperature &t) {
  if (p.pa() < 0.0f) {
    p.pa(0.0f);
  }
  return (M*p.pa())/(R*(t.k()));
}

}  // namespace airdata
