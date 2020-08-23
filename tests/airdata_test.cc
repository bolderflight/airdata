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
  EXPECT_EQ(0, airdata::Ias_mps(0));
}
/* Test IAS negative input */
TEST(Ias, Negative) {
  EXPECT_EQ(0, airdata::Ias_mps(-10));
}
/* Test IAS expected input */
TEST(Ias, Expected) {
  EXPECT_NEAR(28.5457, airdata::Ias_mps(500), 0.001);
}
/* Test EAS zero input */
TEST(Eas, Zero) {
  EXPECT_EQ(0, airdata::Eas_mps(0, 101325));
  EXPECT_EQ(0, airdata::Eas_mps(20, 0));
}
/* Test EAS negative input */
TEST(Eas, Negative) {
  EXPECT_EQ(0, airdata::Eas_mps(-10, 101325));
  EXPECT_EQ(0, airdata::Eas_mps(20, -10));
}
/* Test EAS expected input */
TEST(Eas, Expected) {
  EXPECT_NEAR(28.5429, airdata::Eas_mps(500, 90000), 0.001);
}
/* Test TAS zero input */
TEST(Tas, Zero) {
  EXPECT_EQ(0, airdata::Tas_mps(0, 15));
}
/* Test TAS negative input */
TEST(Tas, Negative) {
  EXPECT_EQ(0, airdata::Tas_mps(-10, 15));
  EXPECT_EQ(0, airdata::Tas_mps(20, -300));
}
/* Test TAS expected input */
TEST(Tas, Expected) {
  EXPECT_NEAR(19.8257, airdata::Tas_mps(20, 10), 0.001);
}
/* Test Pressure Altitude zero input */
TEST(PressureAltitude, Zero) {
  EXPECT_NEAR(44330.7692f, airdata::PressureAltitude_m(0.0f), 0.01f);
}
/* Test Pressure Altitude negative input */
TEST(PressureAltitude, Negative) {
  EXPECT_NEAR(44330.7692f, airdata::PressureAltitude_m(-100.0f), 0.01f);
}
/* Test Pressure Altitude positive input */
TEST(PressureAltitude, Positive) {
  EXPECT_NEAR(9984.2683f, airdata::PressureAltitude_m(26500.0f), 0.5f);
}
/* Test Pressure Altitude sea level input */
TEST(PressureAltitude, SeaLevel) {
  EXPECT_FLOAT_EQ(0.0f, airdata::PressureAltitude_m(101325.0f));
}
/* Test Density Altitude zero input */
TEST(DensityAltitude, Zero) {
  EXPECT_NEAR(44330.7692f, airdata::DensityAltitude_m(0.0f, 0.0f), 0.01f);
}
/* Test Density Altitude negative input */
TEST(DensityAltitude, Negative) {
  EXPECT_NEAR(44330.7692f, airdata::DensityAltitude_m(-100.0f, -10.0f), 0.01f);
}
/* Test Density Altitude positive input */
TEST(DensityAltitude, Positive) {
  EXPECT_NEAR(700.3124f, airdata::DensityAltitude_m(93194.0f, 10.46f), 0.05f);
}
/* Test Density Altitude sea level input */
TEST(DensityAltitude, SeaLevel) {
  EXPECT_FLOAT_EQ(0.0f, airdata::DensityAltitude_m(101325.0f, 15.0f));
}
/* Test Outside Air Temperature zero input */
TEST(EstimateOAT, Zero) {
  EXPECT_FLOAT_EQ(0.0f, airdata::Oat_c(0.0f, 0.0f));
}
/* Test Outside Air Temperature negative input */
TEST(EstimateOAT, Negative) {
  EXPECT_NEAR(-9.35f, airdata::Oat_c(-10.0f, -100.0f), 0.01f);
}
/* Test Outside Air Temperature positive input */
TEST(EstimateOAT, Positive) {
  EXPECT_NEAR(11.75f, airdata::Oat_c(15.0f, 500.0f), 0.01f);
}
/* Test Get Density zero input */
TEST(GetDensity, Zero) {
  EXPECT_FLOAT_EQ(0.0f, airdata::AirDensity_kgpm3(0.0f, 0.0f));
}
/* Test Get Density negative input */
TEST(GetDensity, Negative) {
  EXPECT_FLOAT_EQ(0.0f, airdata::AirDensity_kgpm3(-10.0f, -10.0f));
}
/* Test Get Density positive input */
TEST(GetDensity, Positive) {
  EXPECT_NEAR(1.0066, airdata::AirDensity_kgpm3(79501.0f, 2.01f), 0.01f);
}
/* Test Get Density sea level input */
TEST(GetDensity, SeaLevel) {
  EXPECT_NEAR(1.2250, airdata::AirDensity_kgpm3(101325.0f, 15.0f), 0.01f);
}

