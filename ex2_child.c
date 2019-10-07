#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMSZ 27
 main()
{
  int shmid;
  key_t key;
  char* shm,*s;
  //key value
  key=1234;
  //create tge segment
  if((shmid=shmget(key,SHMSZ,0666))<0)
  {
    perror("shmget error");
    exit(1);
   }
  //attach the segment to our data space
  if((shm=shmat(shmid,NULL,0))==(char *)-1)
  {
     perror("shmat");
     exit(1);
   }
  //read what the server put in the memory
  for(s=shm;*s!='\0';s++)
  {
    putchar(*s);
   }
  putchar('\n');
  //finally change the first character to #
  *shm='#';
  shmdt(shm);
  //shmctl(shmid,IPC_RMID,NULL); 
  }
