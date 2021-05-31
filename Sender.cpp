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

void fifofunc(unsigned output1)
{
    int fd = open("myfifo", O_WRONLY);
  if(write(fd, &output1,sizeof(output1)) == -1)
  {
    cout<<"failed to write\n";
  }
  close(fd);
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
    //ToConsole(new_node->BMSDataSample);
    buffer_output1[temp] = new_node->BMSDataSample;
  }
  
}
/*
int PipelineSender(void)
{
  pid_t childpid;
  int fd[2];
  
  if((pipe(fd) == -1) || ((childpid = fork()) == -1)){
    perror("Failed to setup pipeline");
    return 1;
  }
  if(childpid == 0)
  {
    if(dup2(fd[1],STDOUT_FILENO)== -1)
    {
      cout<<"Failed to redirect stdout of sender \n";
    }
    else if((close(fd[0]) == -1) || (close(fd[1]) == -1))
    {
      cout<<"Failed to close extra pipe descriptors on Sender \n";
    }
    else
    {
      
    }
    return 1;
  }
    if(dup2(fd[0],STDIN_FILENO)== -1)
    {
      cout<<"Failed to redirect stdin of receiver \n";
    }
    else if((close(fd[0]) == -1) || (close(fd[1]) == -1))
    {
      cout<<"Failed to close extra pipe descriptors on receiver\n";
    }
    else
    {
    }
    return 1;
}
*/
