define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "stream_bms.h"

TEST_CASE("infers the breach according to limits") {
  struct Register sender_buffer_st = {1, 100, 1, 10};
  struct Datablock* firstblock = NULL;
  Transmission_Controller(sender_buffer_st, firstblock);
  REQUIRE(firstblock != NULL);
  
}
