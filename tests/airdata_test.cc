/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "airdata.h"
#include "gtest/gtest.h"

/* Test IAS zero input */
TEST(Ias, Zero) {
  EXPECT_EQ(0, bfs::Ias_mps(0.0f));
}
/* Test IAS negative input */
TEST(Ias, Negative) {
  EXPECT_EQ(0, bfs::Ias_mps(-10.0f));
}
/* Test IAS expected input */
TEST(Ias, Expected) {
  EXPECT_NEAR(28.5457, bfs::Ias_mps(500.0f), 0.001);
}
/* Test EAS zero input */
TEST(Eas, Zero) {
  EXPECT_EQ(0, bfs::Eas_mps(0.0f, 101325.0f));
  EXPECT_EQ(0, bfs::Eas_mps(20.0f, 0.0f));
}
/* Test EAS negative input */
TEST(Eas, Negative) {
  EXPECT_EQ(0, bfs::Eas_mps(-10.0f, 101325.0f));
  EXPECT_EQ(0, bfs::Eas_mps(20.0f, -10.0f));
}
/* Test EAS expected input */
TEST(Eas, Expected) {
  EXPECT_NEAR(28.5429, bfs::Eas_mps(500.0f, 90000.0f), 0.001);
}
/* Test TAS zero input */
TEST(Tas, Zero) {
  EXPECT_EQ(0, bfs::Tas_mps(0.0f, 15.0f));
}
/* Test TAS negative input */
TEST(Tas, Negative) {
  EXPECT_EQ(0, bfs::Tas_mps(-10.0f, 15.0f));
  EXPECT_EQ(0, bfs::Tas_mps(20.0f, -300.0f));
}
/* Test TAS expected input */
TEST(Tas, Expected) {
  EXPECT_NEAR(19.8257, bfs::Tas_mps(20.0f, 10.0f), 0.001);
}
/* Test Pressure Altitude zero input */
TEST(PressureAltitude, Zero) {
  EXPECT_NEAR(44330.7692f, bfs::PressureAltitude_m(0.0f), 0.01f);
}
/* Test Pressure Altitude negative input */
TEST(PressureAltitude, Negative) {
  EXPECT_NEAR(44330.7692f, bfs::PressureAltitude_m(-100.0f), 0.01f);
}
/* Test Pressure Altitude positive input */
TEST(PressureAltitude, Positive) {
  EXPECT_NEAR(9984.2683f, bfs::PressureAltitude_m(26500.0f), 0.5f);
}
/* Test Pressure Altitude sea level input */
TEST(PressureAltitude, SeaLevel) {
  EXPECT_FLOAT_EQ(0.0f, bfs::PressureAltitude_m(101325.0f));
}
/* Test Density Altitude zero input */
TEST(DensityAltitude, Zero) {
  EXPECT_NEAR(44330.7692f, bfs::DensityAltitude_m(0.0f, 0.0f), 0.01f);
}
/* Test Density Altitude negative input */
TEST(DensityAltitude, Negative) {
  EXPECT_NEAR(44330.7692f, bfs::DensityAltitude_m(-100.0f, -10.0f), 0.01f);
}
/* Test Density Altitude positive input */
TEST(DensityAltitude, Positive) {
  EXPECT_NEAR(700.3124f, bfs::DensityAltitude_m(93194.0f, 10.46f), 0.05f);
}
/* Test Density Altitude sea level input */
TEST(DensityAltitude, SeaLevel) {
  EXPECT_FLOAT_EQ(0.0f, bfs::DensityAltitude_m(101325.0f, 15.0f));
}
/* Test Outside Air Temperature zero input */
TEST(EstimateOAT, Zero) {
  EXPECT_FLOAT_EQ(0.0f, bfs::Oat_c(0.0f, 0.0f));
}
/* Test Outside Air Temperature negative input */
TEST(EstimateOAT, Negative) {
  EXPECT_NEAR(-9.35f, bfs::Oat_c(-10.0f, -100.0f), 0.01f);
}
/* Test Outside Air Temperature positive input */
TEST(EstimateOAT, Positive) {
  EXPECT_NEAR(11.75f, bfs::Oat_c(15.0f, 500.0f), 0.01f);
}
/* Test Get Density zero input */
TEST(GetDensity, Zero) {
  EXPECT_FLOAT_EQ(0.0f, bfs::AirDensity_kgpm3(0.0f, 0.0f));
}
/* Test Get Density negative input */
TEST(GetDensity, Negative) {
  EXPECT_FLOAT_EQ(0.0f, bfs::AirDensity_kgpm3(-10.0f, -10.0f));
}
/* Test Get Density positive input */
TEST(GetDensity, Positive) {
  EXPECT_NEAR(1.0066, bfs::AirDensity_kgpm3(79501.0f, 2.01f), 0.01f);
}
/* Test Get Density sea level input */
TEST(GetDensity, SeaLevel) {
  EXPECT_NEAR(1.2250, bfs::AirDensity_kgpm3(101325.0f, 15.0f), 0.01f);
}
