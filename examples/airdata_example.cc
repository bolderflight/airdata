/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2019 Bolder Flight Systems
*/

#include "airdata/airdata.h"
#include <iostream>

int main()
{
  
  std::cout << airdata::GetEas_ms(500, 101000.0f) << std::endl;

  return 0;
}
