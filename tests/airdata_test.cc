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
