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
  types::DiffPressure dpress;
  dpress.pa(0.0f);
  types::Speed ias = airdata::CalcIas(dpress);

  EXPECT_EQ(0.0f, ias.mps());
}
/* Test IAS negative input */
TEST(Ias, Negative) {
  types::DiffPressure dpress;
  dpress.pa(-10.0f);
  types::Speed ias = airdata::CalcIas(dpress);

  EXPECT_FLOAT_EQ(0.0f, ias.mps());
}
/* Test IAS positive input */
TEST(Ias, Positive) {
  types::DiffPressure dpress;
  dpress.pa(500.0f);
  types::Speed ias = airdata::CalcIas(dpress);

  EXPECT_NEAR(28.5459f, ias.mps(), 0.01f);
}

/* Test TAS all zero input */
TEST(Tas, ZeroAll) {
  types::Speed speed;
  speed.mps(0.0f);
  types::Temperature temp;
  temp.c(0.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_EQ(0.0f, tas.mps());
}
/* Test TAS airspeed zero input */
TEST(Tas, ZeroAs) {
  types::Speed speed;
  speed.mps(0.0f);
  types::Temperature temp;
  temp.c(15.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_FLOAT_EQ(0.0f, tas.mps());
}
/* Test TAS temperature zero input */
TEST(Tas, ZeroT) {
  types::Speed speed;
  speed.mps(50.0f);
  types::Temperature temp;
  temp.c(0.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_NEAR(48.6812f, tas.mps(), 0.01f);
}
/* Test TAS all negative input */
TEST(Tas, NegativeAll) {
  types::Speed speed;
  speed.mps(-10.0f);
  types::Temperature temp;
  temp.c(-10.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_FLOAT_EQ(0.0f, tas.mps());
}
/* Test TAS airspeed negative input */
TEST(Tas, NegativeAs) {
  types::Speed speed;
  speed.mps(-10.0f);
  types::Temperature temp;
  temp.c(15.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_FLOAT_EQ(0.0f, tas.mps());
}
/* Test TAS temperature negative input */
TEST(Tas, NegativeT) {
  types::Speed speed;
  speed.mps(50.0f);
  types::Temperature temp;
  temp.c(-10.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_NEAR(47.7818f, tas.mps(), 0.1f);
}
/* Test TAS positive input */
TEST(Tas, Positive) {
  types::Speed speed;
  speed.mps(30.0f);
  types::Temperature temp;
  temp.c(30.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_NEAR(30.7709f, tas.mps(), 0.01f);
}
/* Test TAS sea level temperature input */
TEST(Tas, SeaLevelT) {
  types::Speed speed;
  speed.mps(30.0f);
  types::Temperature temp;
  temp.c(15.0f);
  types::Speed tas = airdata::CalcTas(speed, temp);

  EXPECT_NEAR(30.0f, tas.mps(), 0.01f);
}

/* Test Pressure Altitude zero input */
TEST(PressureAltitude, Zero) {
  types::StaticPressure stpress;
  stpress.pa(0.0f);
  types::Altitude pa = airdata::CalcPressureAltitude(stpress);

  EXPECT_NEAR(44330.7692f, pa.m(), 0.01f);
}
/* Test Pressure Altitude negative input */
TEST(PressureAltitude, Negative) {
  types::StaticPressure stpress;
  stpress.pa(-100.0f);
  types::Altitude pa = airdata::CalcPressureAltitude(stpress);

  EXPECT_NEAR(44330.7692f, pa.m(), 0.01f);
}
/* Test Pressure Altitude positive input */
TEST(PressureAltitude, Positive) {
  types::StaticPressure stpress;
  stpress.pa(26500.0f);
  types::Altitude pa = airdata::CalcPressureAltitude(stpress);

  EXPECT_NEAR(9984.2683f, pa.m(), 0.01f);
}
/* Test Pressure Altitude sea level input */
TEST(PressureAltitude, SeaLevel) {
  types::StaticPressure stpress;
  stpress.pa(101325.0f);
  types::Altitude pa = airdata::CalcPressureAltitude(stpress);

  EXPECT_FLOAT_EQ(0.0f, pa.m());
}

/* Test AGL zero input */
TEST(AGL, ZeroC) {
  types::StaticPressure stpress;
  stpress.pa(101325.0f);
  types::Altitude bias;
  bias.m(0.0f);
  types::Altitude agl = airdata::CalcAGL(stpress, bias);

  EXPECT_FLOAT_EQ(0.0f, agl.m());
}
/* Test AGL negative input */
TEST(AGL, NegativeC) {
  types::StaticPressure stpress;
  stpress.pa(101325.0f);
  types::Altitude bias;
  bias.m(-100.0f);
  types::Altitude agl = airdata::CalcAGL(stpress, bias);

  EXPECT_FLOAT_EQ(100.0f, agl.m());
}
/* Test AGL positive input */
TEST(AGL, PositiveC) {
  types::StaticPressure stpress;
  stpress.pa(101325.0f);
  types::Altitude bias;
  bias.m(100.0f);
  types::Altitude agl = airdata::CalcAGL(stpress, bias);

  EXPECT_FLOAT_EQ(-100.0f, agl.m());
}

/* Test MSL zero input */
TEST(MSL, Zero) {
  types::Altitude agl;
  agl.m(0.0f);
  types::Altitude alt;
  alt.m(0.0f);
  types::Altitude msl = airdata::CalcMSL(agl, alt);

  EXPECT_FLOAT_EQ(0.0f, msl.m());
}
/* Test MSL positive input */
TEST(MSL, Positive) {
  types::Altitude agl;
  agl.m(500.0f);
  types::Altitude alt;
  alt.m(500.0f);
  types::Altitude msl = airdata::CalcMSL(agl, alt);

  EXPECT_FLOAT_EQ(1000.0f, msl.m());
}
/* Test MSL mixed input */
TEST(MSL, Mixed) {
  types::Altitude agl;
  agl.m(500.0f);
  types::Altitude alt;
  alt.m(-500.0f);
  types::Altitude msl = airdata::CalcMSL(agl, alt);

  EXPECT_FLOAT_EQ(0.0f, msl.m());
}

/* Test Density Altitude zero input */
TEST(DensityAltitude, Zero) {
  types::StaticPressure stpress;
  stpress.pa(0.0f);
  types::Temperature temp;
  temp.c(0.0f);
  types::Altitude da = airdata::CalcDensityAltitude(stpress, temp);

  EXPECT_NEAR(44330.7692f, da.m(), 0.01f);
}
/* Test Density Altitude negative input */
TEST(DensityAltitude, Negative) {
  types::StaticPressure stpress;
  stpress.pa(-100.0f);
  types::Temperature temp;
  temp.c(-10.0f);
  types::Altitude da = airdata::CalcDensityAltitude(stpress, temp);

  EXPECT_NEAR(44330.7692f, da.m(), 0.01f);
}
/* Test Density Altitude positive input */
TEST(DensityAltitude, Positive) {
  types::StaticPressure stpress;
  stpress.pa(93194.0f);
  types::Temperature temp;
  temp.c(10.46f);
  types::Altitude da = airdata::CalcDensityAltitude(stpress, temp);

  EXPECT_NEAR(700.3124f, da.m(), 0.01f);
}
/* Test Density Altitude sea level input */
TEST(DensityAltitude, SeaLevel) {
  types::StaticPressure stpress;
  stpress.pa(101325.0f);
  types::Temperature temp;
  temp.c(15.0f);
  types::Altitude da = airdata::CalcDensityAltitude(stpress, temp);

  EXPECT_FLOAT_EQ(0.0f, da.m());
}

/* Test Outside Air Temperature zero input */
TEST(OAT, Zero) {
  types::Temperature temp;
  temp.c(0.0f);
  types::Altitude alt;
  alt.m(0.0f);
  types::Temperature eoat = airdata::CalcOAT(temp, alt);

  EXPECT_FLOAT_EQ(0.0f, eoat.c());
}
/* Test Outside Air Temperature negative input */
TEST(OAT, Negative) {
  types::Temperature temp;
  temp.c(-10.0f);
  types::Altitude alt;
  alt.m(-100.0f);
  types::Temperature eoat = airdata::CalcOAT(temp, alt);

  EXPECT_NEAR(-9.35f, eoat.c(), 0.01f);
}
/* Test Outside Air Temperature positive input */
TEST(OAT, Positive) {
  types::Temperature temp;
  temp.c(15.0f);
  types::Altitude alt;
  alt.m(500.0f);
  types::Temperature eoat = airdata::CalcOAT(temp, alt);

  EXPECT_NEAR(11.75f, eoat.c(), 0.01f);
}

/* Test Density zero input */
TEST(Density, Zero) {
  types::StaticPressure stpress;
  stpress.pa(0.0f);
  types::Temperature temp;
  temp.c(0.0f);
  types::Density density = airdata::CalcDensity(stpress, temp);

  EXPECT_FLOAT_EQ(0.0f, density.kgpm3());
}
/* Test Density negative input */
TEST(Density, Negative) {
  types::StaticPressure stpress;
  stpress.pa(-10.0f);
  types::Temperature temp;
  temp.c(-10.0f);
  types::Density density = airdata::CalcDensity(stpress, temp);

  EXPECT_FLOAT_EQ(0.0f, density.kgpm3());
}
/* Test Density positive input */
TEST(Density, Positive) {
  types::StaticPressure stpress;
  stpress.pa(79501.0f);
  types::Temperature temp;
  temp.c(2.01f);
  types::Density density = airdata::CalcDensity(stpress, temp);

  EXPECT_NEAR(1.0066, density.kgpm3(), 0.01f);
}
/* Test Density sea level input */
TEST(Density, SeaLevel) {
  types::StaticPressure stpress;
  stpress.pa(101325.0f);
  types::Temperature temp;
  temp.c(15.0f);
  types::Density density = airdata::CalcDensity(stpress, temp);

  EXPECT_NEAR(1.2250, density.kgpm3(), 0.01f);
}
