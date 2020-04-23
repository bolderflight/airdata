/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include "gtest/gtest.h"

/* Test IAS zero input */
TEST(Ias, Zero) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetIas_ms(0.0f));
}
/* Test IAS negative input */
TEST(Ias, Negative) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetIas_ms(-10.0f));
}
/* Test IAS positive input */
TEST(Ias, Positive) {
  EXPECT_NEAR(28.5459f, airdata::GetIas_ms(500.0f), 0.01f);
}

/* Test TAS all zero input */
TEST(Tas, ZeroAll) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetTas_ms(0.0f, 0.0f));
}
/* Test TAS airspeed zero input */
TEST(Tas, ZeroAs) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetTas_ms(0.0f, 15.0f));
}
/* Test TAS temperature zero input */
TEST(Tas, ZeroT) {
  EXPECT_NEAR(48.6812f, airdata::GetTas_ms(50.0f, 0.0f), 0.01f);
}
/* Test TAS all negative input */
TEST(Tas, NegativeAll) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetTas_ms(-10.0f, -10.0f));
}
/* Test TAS airspeed negative input */
TEST(Tas, NegativeAs) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetTas_ms(-10.0f, 15.0f));
}
/* Test TAS temperature negative input */
TEST(Tas, NegativeT) {
  EXPECT_NEAR(47.7818f, airdata::GetTas_ms(50.0f, -10.0f), 0.1f);
}
/* Test TAS positive input */
TEST(Tas, Positive) {
  EXPECT_NEAR(30.7709f, airdata::GetTas_ms(30.0f, 30.0f), 0.01f);
}
/* Test TAS sea level temperature input */
TEST(Tas, SeaLevelT) {
  EXPECT_NEAR(30.0f, airdata::GetTas_ms(30.0f, 15.0f), 0.01f);
}

/* Test Pressure Altitude zero input */
TEST(PressureAltitude, Zero) {
  EXPECT_NEAR(44330.7692f, airdata::GetPressureAltitude_m(0.0f), 0.01f);
}
/* Test Pressure Altitude negative input */
TEST(PressureAltitude, Negative) {
  EXPECT_NEAR(44330.7692f, airdata::GetPressureAltitude_m(-100.0f), 0.01f);
}
/* Test Pressure Altitude positive input */
TEST(PressureAltitude, Positive) {
  EXPECT_NEAR(9984.2683f, airdata::GetPressureAltitude_m(26500.0f), 0.01f);
}
/* Test Pressure Altitude sea level input */
TEST(PressureAltitude, SeaLevel) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetPressureAltitude_m(101325.0f));
}

/* Test AGL zero input */
TEST(AGL, ZeroC) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetAGL_m(101325.0f, 0.0f));
}
/* Test AGL negative input */
TEST(AGL, NegativeC) {
  EXPECT_FLOAT_EQ(100.0f, airdata::GetAGL_m(101325.0f, -100.0f));
}
/* Test AGL positive input */
TEST(AGL, PositiveC) {
  EXPECT_FLOAT_EQ(-100.0f, airdata::GetAGL_m(101325.0f, 100.0f));
}

/* Test MSL zero input */
TEST(MSL, Zero) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetMSL_m(0.0f, 0.0f));
}
/* Test MSL positive input */
TEST(MSL, Positive) {
  EXPECT_FLOAT_EQ(1000.0f, airdata::GetMSL_m(500.0f, 500.0f));
}
/* Test MSL mixed input */
TEST(MSL, Mixed) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetMSL_m(500.0f, -500.0f));
}

/* Test Density Altitude zero input */
TEST(DensityAltitude, Zero) {
  EXPECT_NEAR(44330.7692f, airdata::GetDensityAltitude_m(0.0f, 0.0f), 0.01f);
}
/* Test Density Altitude negative input */
TEST(DensityAltitude, Negative) {
  EXPECT_NEAR(44330.7692f, airdata::GetDensityAltitude_m(-100.0f, -10.0f),
    0.01f);
}
/* Test Density Altitude positive input */
TEST(DensityAltitude, Positive) {
  EXPECT_NEAR(700.3124f, airdata::GetDensityAltitude_m(93194.0f, 10.46f),
    0.01f);
}
/* Test Density Altitude sea level input */
TEST(DensityAltitude, SeaLevel) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetDensityAltitude_m(101325.0f, 15.0f));
}

/* Test Outside Air Temperature zero input */
TEST(EstimateOAT, Zero) {
  EXPECT_FLOAT_EQ(0.0f, airdata::EstimateOAT_C(0.0f, 0.0f));
}
/* Test Outside Air Temperature negative input */
TEST(EstimateOAT, Negative) {
  EXPECT_NEAR(-9.35f, airdata::EstimateOAT_C(-10.0f, -100.0f), 0.01f);
}
/* Test Outside Air Temperature positive input */
TEST(EstimateOAT, Positive) {
  EXPECT_NEAR(11.75f, airdata::EstimateOAT_C(15.0f, 500.0f), 0.01f);
}

/* Test Get Density zero input */
TEST(GetDensity, Zero) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetDensity_kgm3(0.0f, 0.0f));
}
/* Test Get Density negative input */
TEST(GetDensity, Negative) {
  EXPECT_FLOAT_EQ(0.0f, airdata::GetDensity_kgm3(-10.0f, -10.0f));
}
/* Test Get Density positive input */
TEST(GetDensity, Positive) {
  EXPECT_NEAR(1.0066, airdata::GetDensity_kgm3(79501.0f, 2.01f), 0.01f);
}
/* Test Get Density sea level input */
TEST(GetDensity, SeaLevel) {
  EXPECT_NEAR(1.2250, airdata::GetDensity_kgm3(101325.0f, 15.0f), 0.01f);
}