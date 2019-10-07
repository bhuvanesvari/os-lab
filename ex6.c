//reader-writer problem(many readers one writer)
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<unistd.h>
#include<sched.h>
#include<stdlib.h>

#define MAXTHREAD 5

int SharedData;
void* reader();
void* writer();
sem_t rLock,wLock;
int rc=0;

int main()
{
   
   pthread_t rId[MAXTHREAD],wId;
   int i,k[MAXTHREAD];
//initialisation of semaphores
   sem_init(&rLock,0,1);
   sem_init(&wLock,0,1);

//creation of reader thread
   for(i=0;i<MAXTHREAD;i++)
      {
          k[i]=i+1;
          if(pthread_create(&rId[i],0,reader,&k[i])!=0)
            {
               perror("Cannot create a reader\n"); exit(1);
             }
          
       }
 
 //creation of writer thread
    if(pthread_create(&wId,0,writer,0)!=0)
      {
         perror("Cannot create writer\n");
         exit(1);
       }

//to synchronize the execution with the main thread
    pthread_join(wId,0);
    for(i=0;i<MAXTHREAD;i++)
      {
         pthread_join(rId[i],0);
      }

//destroy the created semaphores
     sem_destroy(&rLock);
     sem_destroy(&wLock);
     
    return 0;
}

//reader process

void* reader(void* arg)
{
   sleep(1);
   int id = *(int *)arg;
   while(1)
     {
         sleep(1);
         sem_wait(&rLock);
         rc++;
         if(rc==1)
           
              sem_wait(&wLock);
         sem_post(&rLock);
         printf("\n Reader %d read value:%d...",id,SharedData);
         sem_wait(&rLock);
         rc--;
         if(rc==0)
             sem_post(&wLock);
         sem_post(&rLock);
      }
        
}   

//writer process
int getNext()
{
   static int data=100;
   return data++;
}
void* writer()
{
  while(1)
    {
      sem_wait(&wLock);
      printf("\n Writer writing  No. of readers:%d",rc);
      sem_post(&rLock);
      SharedData=getNext();
      sem_post(&wLock);
      sleep(1);
    }
   
}        

