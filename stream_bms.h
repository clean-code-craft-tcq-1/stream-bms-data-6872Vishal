#include <iostream>

using namespace std;

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

/*struct localstorage
{
  struct Datablock Tx_st;
  struct localstorage *P;
};*/

unsigned getdata_from_sensor();

void decrement_to_zero(unsigned counter);

void Transmission_Controller(struct Register RxBuffer_st,struct Datablock** Head);

void ToConsole(unsigned output);

