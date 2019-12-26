/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include "gtest/gtest.h"
#include "math.h"

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
  EXPECT_NEAR(28.5459769176023f, airdata::GetIas_ms(500.0f), 0.01f);
}

