#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main()
{
  int mqID;
  int len;
  key_t key;
  char txt[100];
  key=333;
  if((mqID=msgget(key,0666|IPC_CREAT))==-1)
  {
    perror("msgget error\n");
    exit(1);
   }
  printf("Message queue created\n");
  while(1)
  {
    printf("\n waiting for message from sender");
    if(msgrcv(mqID,&txt,sizeof(txt),0,0)<0)
    {
      perror("Msgrcv");
      }
     printf("Message recieved:%s\n",txt);
     if(strcmp(txt,"bye")==0)
     {
       break;
     }
     }
   msgctl(mqID,IPC_RMID,NULL);
   printf("\n exited");
   return 0;
   }
     
