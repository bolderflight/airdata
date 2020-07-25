/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include "types/types.h"
#include "gtest/gtest.h"

/* Test IAS zero input */
TEST(Ias, Zero) {
  types::Pressure<float> dpress;
  dpress.pa(0.0f);
  types::Speed<float> ias = airdata::Ias(dpress);
  EXPECT_EQ(0.0f, ias.mps());
}
/* Test IAS negative input */
TEST(Ias, Negative) {
  types::Pressure<float> dpress;
  dpress.pa(-10.0f);
  types::Speed<float> ias = airdata::Ias(dpress);
  EXPECT_FLOAT_EQ(0.0f, ias.mps());
}
/* Test IAS positive input */
TEST(Ias, Positive) {
  types::Pressure<float> dpress;
  dpress.pa(500.0f);
  types::Speed<float> ias = airdata::Ias(dpress);
  EXPECT_NEAR(28.5459f, ias.mps(), 0.5f);
}
/* Test TAS all zero input */
TEST(Tas, ZeroAll) {
  types::Speed<float> speed;
  speed.mps(0.0f);
  types::Temperature<float> temp;
  temp.c(0.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_EQ(0.0f, tas.mps());
}
/* Test TAS airspeed zero input */
TEST(Tas, ZeroAs) {
  types::Speed<float> speed;
  speed.mps(0.0f);
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_FLOAT_EQ(0.0f, tas.mps());
}
/* Test TAS temperature zero input */
TEST(Tas, ZeroT) {
  types::Speed<float> speed;
  speed.mps(50.0f);
  types::Temperature<float> temp;
  temp.c(0.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_NEAR(48.6812f, tas.mps(), 0.5f);
}
/* Test TAS all negative input */
TEST(Tas, NegativeAll) {
  types::Speed<float> speed;
  speed.mps(-10.0f);
  types::Temperature<float> temp;
  temp.c(-10.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_FLOAT_EQ(0.0f, tas.mps());
}
/* Test TAS airspeed negative input */
TEST(Tas, NegativeAs) {
  types::Speed<float> speed;
  speed.mps(-10.0f);
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_FLOAT_EQ(0.0f, tas.mps());
}
/* Test TAS temperature negative input */
TEST(Tas, NegativeT) {
  types::Speed<float> speed;
  speed.mps(50.0f);
  types::Temperature<float> temp;
  temp.c(-10.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_NEAR(47.7818f, tas.mps(), 0.1f);
}
/* Test TAS positive input */
TEST(Tas, Positive) {
  types::Speed<float> speed;
  speed.mps(30.0f);
  types::Temperature<float> temp;
  temp.c(30.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_NEAR(30.7709f, tas.mps(), 0.5f);
}
/* Test TAS sea level temperature input */
TEST(Tas, SeaLevelT) {
  types::Speed<float> speed;
  speed.mps(30.0f);
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Speed<float> tas = airdata::Tas(speed, temp);
  EXPECT_NEAR(30.0f, tas.mps(), 0.5f);
}
/* Test Pressure Altitude zero input */
TEST(PressureAltitude, Zero) {
  types::Pressure<float> stpress;
  stpress.pa(0.0f);
  types::Altitude<float> pa = airdata::PressureAltitude(stpress);
  EXPECT_NEAR(44330.7692f, pa.m(), 0.5f);
}
/* Test Pressure Altitude negative input */
TEST(PressureAltitude, Negative) {
  types::Pressure<float> stpress;
  stpress.pa(-100.0f);
  types::Altitude<float> pa = airdata::PressureAltitude(stpress);
  EXPECT_NEAR(44330.7692f, pa.m(), 0.5f);
}
/* Test Pressure Altitude positive input */
TEST(PressureAltitude, Positive) {
  types::Pressure<float> stpress;
  stpress.pa(26500.0f);
  types::Altitude<float> pa = airdata::PressureAltitude(stpress);
  EXPECT_NEAR(9984.2683f, pa.m(), 0.5f);
}
/* Test Pressure Altitude sea level input */
TEST(PressureAltitude, SeaLevel) {
  types::Pressure<float> stpress;
  stpress.pa(101325.0f);
  types::Altitude<float> pa = airdata::PressureAltitude(stpress);
  EXPECT_FLOAT_EQ(0.0f, pa.m());
}
/* Test Density Altitude zero input */
TEST(DensityAltitude, Zero) {
  types::Pressure<float> stpress;
  stpress.pa(0.0f);
  types::Temperature<float> temp;
  temp.c(0.0f);
  types::Altitude<float> da = airdata::DensityAltitude(stpress, temp);
  EXPECT_NEAR(44330.7692f, da.m(), 0.5f);
}
/* Test Density Altitude negative input */
TEST(DensityAltitude, Negative) {
  types::Pressure<float> stpress;
  stpress.pa(-100.0f);
  types::Temperature<float> temp;
  temp.c(-10.0f);
  types::Altitude<float> da = airdata::DensityAltitude(stpress, temp);
  EXPECT_NEAR(44330.7692f, da.m(), 0.5f);
}
/* Test Density Altitude positive input */
TEST(DensityAltitude, Positive) {
  types::Pressure<float> stpress;
  stpress.pa(93194.0f);
  types::Temperature<float> temp;
  temp.c(10.46f);
  types::Altitude<float> da = airdata::DensityAltitude(stpress, temp);
  EXPECT_NEAR(700.3124f, da.m(), 0.5f);
}
/* Test Density Altitude sea level input */
TEST(DensityAltitude, SeaLevel) {
  types::Pressure<float> stpress;
  stpress.pa(101325.0f);
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Altitude<float> da = airdata::DensityAltitude(stpress, temp);
  EXPECT_FLOAT_EQ(0.0f, da.m());
}
/* Test Outside Air Temperature zero input */
TEST(OAT, Zero) {
  types::Temperature<float> temp;
  temp.c(0.0f);
  types::Altitude<float> alt;
  alt.m(0.0f);
  types::Temperature<float> eoat = airdata::Oat(temp, alt);
  EXPECT_FLOAT_EQ(0.0f, eoat.c());
}
/* Test Outside Air Temperature negative input */
TEST(OAT, Negative) {
  types::Temperature<float> temp;
  temp.c(-10.0f);
  types::Altitude<float> alt;
  alt.m(-100.0f);
  types::Temperature<float> eoat = airdata::Oat(temp, alt);
  EXPECT_NEAR(-9.35f, eoat.c(), 0.5f);
}
/* Test Outside Air Temperature positive input */
TEST(OAT, Positive) {
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Altitude<float> alt;
  alt.m(500.0f);
  types::Temperature<float> eoat = airdata::Oat(temp, alt);
  EXPECT_NEAR(11.75f, eoat.c(), 0.5f);
}

/* Test Density zero input */
TEST(Density, Zero) {
  types::Pressure<float> stpress;
  stpress.pa(0.0f);
  types::Temperature<float> temp;
  temp.c(0.0f);
  types::Density<float> density = airdata::AirDensity(stpress, temp);
  EXPECT_FLOAT_EQ(0.0f, density.kgpm3());
}
/* Test Density negative input */
TEST(Density, Negative) {
  types::Pressure<float> stpress;
  stpress.pa(-10.0f);
  types::Temperature<float> temp;
  temp.c(-10.0f);
  types::Density<float> density = airdata::AirDensity(stpress, temp);
  EXPECT_FLOAT_EQ(0.0f, density.kgpm3());
}
/* Test Density positive input */
TEST(Density, Positive) {
  types::Pressure<float> stpress;
  stpress.pa(79501.0f);
  types::Temperature<float> temp;
  temp.c(2.01f);
  types::Density<float> density = airdata::AirDensity(stpress, temp);
  EXPECT_NEAR(1.0066, density.kgpm3(), 0.5f);
}
/* Test Density sea level input */
TEST(Density, SeaLevel) {
  types::Pressure<float> stpress;
  stpress.pa(101325.0f);
  types::Temperature<float> temp;
  temp.c(15.0f);
  types::Density<float> density = airdata::AirDensity(stpress, temp);
  EXPECT_NEAR(1.2250, density.kgpm3(), 0.5f);
}
