#include"stream_bms.h"

void decrement_to_zero(unsigned counter)
{
  for(int i=counter; i>0; i--)
  {
    /*do nothing */
  }
  return;
}

unsigned getdata_from_sensor()
{
  return (rand() % 100);
}

void ToConsole(unsigned output)
{
  cout<<output<<"\n";
}
//struct Datablock *Head = NULL;
void Transmission_Controller(struct Register RxBuffer_st,struct Datablock& Head)
{
 
  for(int temp=RxBuffer_st.Num_of_Samples;temp>0;temp--)
  {
  decrement_to_zero(RxBuffer_st.TimeInterval);
  struct Datablock* new_node = (struct Datablock*) malloc(sizeof(struct Datablock));
   new_node->BMSData = getdata_from_sensor();
   new_node->next = Head;
   Head = new_node;
    ToConsole(new_node->BMSData);
  }
  
}
