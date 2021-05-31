#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "stream_bms.h"

int buffer_input1[BUFFER_SIZE];
int buffer_output1[BUFFER_SIZE];

TEST_CASE("Test Case 1 : Working condition") {
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , BUFFER_SIZE};
  struct Datablock* firstblock = NULL;
  cout<<"*********************Test Case : 1********************\n";
  Transmission_Controller(sender_buffer_st, &firstblock);
  REQUIRE(firstblock != NULL);
  
}

TEST_CASE("Test Case 2 : Check no of Data Blocks") {
  int DataBlockCounter = 0;
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , BUFFER_SIZE};
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

TEST_CASE("Test Case 4 :  data tranfer check") {
  cout<<"*********************Test Case : 4********************\n";
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , BUFFER_SIZE};
  struct Datablock* firstblock = NULL;
  Transmission_Controller(sender_buffer_st, &firstblock);
  int fd[2];
  if(pipe(fd) == -1) { cout<<"pipe failed \n"; }
  int pid1 = fork();
  if(pid1 < 0){ cout<<" Fork failed \n";}
  if(pid1 == 0) {
    close(fd[0]);
    write(fd[1], buffer_output1, sizeof(int)*BUFFER_SIZE);
    close(fd[1]);
  }
  else{
    close(fd[1]);
    read(fd[0], buffer_input1, sizeof(int)*BUFFER_SIZE);
    close(fd[0]);
  }
  wait(NULL);
  for(int s=0; s<BUFFER_SIZE; s++){
  REQUIRE(buffer_input1[s] == buffer_output1[s]);
  }
  
}

