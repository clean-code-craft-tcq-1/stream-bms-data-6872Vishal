#include <iostream>

using namespace std;

struct Register
{
  unsigned TransmissionType;
  unsigned TimeInterval;
  unsigned DataType;
  unsigned Num_of_Samples;
};

struct Datablock
{
  unsigned BMSData;
  //unsigned SampleNumber;
  struct Datablock* next;
};

struct localstorage
{
  struct Datablock Tx_st;
  struct localstorage *P;
};

unsigned getdata_from_sensor();

void decrement_to_zero(unsigned counter);

void Transmission_Controller(struct Register RxBuffer_st,struct Datablock& Head);

void ToConsole(unsigned output);

