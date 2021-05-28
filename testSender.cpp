#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "stream_bms.h"

TEST_CASE("Test Case 1 : Working condition") {
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , 10};
  struct Datablock* firstblock = NULL;
  Transmission_Controller(sender_buffer_st, &firstblock);
  REQUIRE(firstblock != NULL);
  
}

TEST_CASE("Test Case 2 : Check no of Data Blocks") {
  int DataBlockCounter = 0;
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , 10};
  struct Datablock* firstblock = NULL;
  Transmission_Controller(sender_buffer_st, &firstblock);
  while(firstblock != NULL)
  {
    DataBlockCounter++;
    firstblock = firstblock->next;
  }
  REQUIRE(DataBlockCounter == 10);
  
}
