#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "stream_bms.h"

TEST_CASE("Test Case 1 : Working condition") {
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , 10};
  struct Datablock* firstblock = NULL;
  cout<<"*********************Test Case : 1********************\n";
  Transmission_Controller(sender_buffer_st, &firstblock);
  REQUIRE(firstblock != NULL);
  
}

TEST_CASE("Test Case 2 : Check no of Data Blocks") {
  int DataBlockCounter = 0;
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , 10};
  struct Datablock* firstblock = NULL;
  cout<<"*********************Test Case : 2********************\n";
  Transmission_Controller(sender_buffer_st, &firstblock);
  while(firstblock != NULL)
  {
    DataBlockCounter++;
    firstblock = firstblock->next;
  }
  REQUIRE(DataBlockCounter == 10);
  
}

TEST_CASE("Test Case 3 : Check Sensor output data") {
cout<<"*********************Test Case : 3********************\n";
  int temp;
  temp = getdata_from_sensor(BMS_Temperature);
  REQUIRE(temp < 50);
  temp = getdata_from_sensor(BMS_Data);
  REQUIRE(temp < 25);
  temp = getdata_from_sensor(TotalNumber);
  REQUIRE(temp < 10);  
}
