#include"stream_bms.h"

void decrement_to_zero(unsigned counter)
{
  for(int i=counter; i>0; i--)
  {
    /*do nothing */
  }
  return;
}

unsigned getdata_from_sensor(enum BMS_Data Sensor)
{
  switch(Sensor)
  {
    case BMS_SOC:
      return (rand() % 100);
      break;
    case BMS_Temperature:
      return (rand() % 50);
      break;
    case BMS_Data:
      return(rand() % 25);
      break;
    default:
      return(rand() % 10);
      break;
  }
}

void ToConsole(unsigned output)
{
  cout<<output<<"\n";
}

void Transmission_Controller(struct Register RxBuffer_st,struct Datablock** Head)
{
  for(int temp=0;temp < BUFFER_SIZE ;temp++)
  {
  decrement_to_zero(RxBuffer_st.TimeInterval);
  struct Datablock* new_node = (struct Datablock*) malloc(sizeof(struct Datablock));
   new_node->BMSDataSample = getdata_from_sensor(RxBuffer_st.DataType);
   new_node->next = *Head;
   *Head = new_node;
    ToConsole(new_node->BMSDataSample);
    buffer_output1[temp] = new_node->BMSDataSample;
  } 
}

#ifdef MAIN
int main()
{
  struct Register sender_buffer_st = {Start_Tx, 100,BMS_SOC , BUFFER_SIZE};
  struct Datablock* firstblock = NULL;
  Transmission_Controller(sender_buffer_st, &firstblock);
}
#endif 
