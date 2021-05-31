#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

#define BUFFER_SIZE 10

int buff_input[BUFFER_SIZE];
int buff_output[BUFFER_SIZE];

enum BMS_Data {BMS_SOC,BMS_Temperature,BMS_Data,TotalNumber};
enum Transmission {Stop_Tx, Start_Tx};

struct Register
{
  enum Transmission TransmissionType;
  unsigned TimeInterval;
  enum BMS_Data DataType;
  unsigned Num_of_Samples;
};

struct Datablock
{
  unsigned BMSDataSample;
  struct Datablock* next;
};


unsigned getdata_from_sensor(enum BMS_Data );

void decrement_to_zero(unsigned counter);

void Transmission_Controller(struct Register RxBuffer_st,struct Datablock** Head);

void ToConsole(unsigned output);

void fifofunc(unsigned output1);
