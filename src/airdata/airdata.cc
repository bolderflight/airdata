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
static constexpr float A0_mps_ = 340.29f;
  // standard sea level speed of sound, m/s
static constexpr float P0_pa_ = 101325.0f;  // standard sea level pressure, Pa
static constexpr float T0_k_ = 288.15f;    // standard sea level temperature, K
static constexpr float L_kpm_ = 0.0065f;     // standard lapse rate, K/m
static constexpr float R_jpkgmol_ = 8.31432f;    // gas constant, J/kg-mol
static constexpr float M_kgpmol_ = 0.0289644f;
  // molecular mass dry air, kg/mol
static constexpr float G_mps2_ = 9.80665f;
  // acceleration due to gravity, m/s^2

}  // anonymous namespace

types::Speed CalcIas(const types::DiffPressure &p) {
  types::Speed ias;
  types::DiffPressure dpress;
  dpress = p;
  if (dpress.pa() < 0.0f) {
    dpress.pa(0.0f);
  }
  ias.mps(A0_mps_ * sqrtf(5.0f *
    (powf((dpress.pa() / P0_pa_ + 1.0f), (2.0f / 7.0f)) - 1.0f)));

  return ias;
}

types::Speed CalcTas(const types::Speed &a, const types::Temperature &t) {
  types::Speed tas;
  types::Speed speed;
  speed = a;
  types::Temperature temp;
  temp = t;
  if (speed.mps() < 0.0f) {
    speed.mps(0.0f);
  }
  tas.mps(speed.mps() * sqrtf((temp.k()/T0_k_)));

  return tas;
}

types::Altitude CalcPressureAltitude(const types::StaticPressure &p) {
  types::Altitude pa;
  types::StaticPressure stpress;
  stpress = p;
  if (stpress.pa() < 0.0f) {
    stpress.pa(0.0f);
  }
  pa.m((T0_k_/L_kpm_)*(1.0f - powf((stpress.pa()/P0_pa_),
                                  ((L_kpm_*R_jpkgmol_)/(M_kgpmol_*G_mps2_)))));

  return pa;
}

types::Altitude CalcAGL(const types::StaticPressure &p,
                          const types::Altitude &c) {
  types::Altitude AGL;
  types::StaticPressure stpress;
  stpress = p;
  types::Altitude alt;
  alt = c;
  types::Altitude press_alt = CalcPressureAltitude(stpress);
  AGL.m(press_alt.m() - alt.m());

  return AGL;
}

types::Altitude CalcMSL(const types::Altitude &agl,
                          const types::Altitude &alt) {
  types::Altitude MSL;
  types::Altitude AGL;
  AGL = agl;
  types::Altitude ALT;
  ALT = alt;
  MSL.m(AGL.m() + ALT.m());

  return MSL;
}

types::Altitude CalcDensityAltitude(const types::StaticPressure &p,
                                    const types::Temperature &t) {
  types::Altitude da;
  types::StaticPressure stpress;
  stpress = p;
  types::Temperature temp;
  temp = t;
  if (stpress.pa() < 0.0f) {
    stpress.pa(0.0f);
  }
  da.m((T0_k_/L_kpm_)*(1.0f - powf(((stpress.pa()/P0_pa_)*(T0_k_/(temp.k()))),
    ((L_kpm_*R_jpkgmol_)/(M_kgpmol_*G_mps2_ - L_kpm_*R_jpkgmol_)))));

  return da;
}

types::Temperature CalcOAT(const types::Temperature &t,
                            const types::Altitude &h) {
  types::Temperature eoat;
  types::Temperature temp;
  temp = t;
  types::Altitude alt;
  alt = h;
  eoat.k(temp.k()-L_kpm_*alt.m());

  return eoat;
}

types::Density CalcDensity(const types::StaticPressure &p,
                        const types::Temperature &t) {
  types::Density density;
  types::StaticPressure stpress;
  stpress = p;
  types::Temperature temp;
  temp = t;
  if (stpress.pa() < 0.0f) {
    stpress.pa(0.0f);
  }
  density.kgpm3((M_kgpmol_*stpress.pa())/(R_jpkgmol_*(temp.k())));

  return density;
}

}  // namespace airdata
