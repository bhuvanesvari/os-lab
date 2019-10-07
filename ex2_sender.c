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
   printf("\nEnter message:");
   gets(txt);
   len=strlen(txt);
  if(msgsnd(mqID,&txt,len,0)==-1)
  {
    perror("Message send msgsnd\n");
  }
  if(strcmp(txt,"bye")==0)
  {
    break;
  }
  }
  msgctl(mqID,IPC_RMID,NULL);
  printf("Exited\n");
  return 0;
  }
     
  
