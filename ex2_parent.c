#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMSZ 27
 main()
{
  char c;
  int shmid;
  key_t key;
  char* shm,*s;
  //key value
  key=1234;
  //create the segment
  if((shmid=shmget(key,SHMSZ,IPC_CREAT|0666))<0)
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
  //add data to shared memory
  s=shm;
  for(c='a';c<='z';c++)
  {
    *s++=c;
  }
  *s='\0';
  //wait until the other process changes the first character of our memory to*
  while(*shm!='#')
  {
    sleep(1);
   }
   shmdt(shm);
   shmctl(shmid,IPC_RMID,NULL); 
} 

