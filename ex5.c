//simple producer consumer problem
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
int sharedmemory;
sem_t prodLock,conLock;

int produce_item()
{
  static int a=0;
  return a++;
}

int get()
{
  int item=sharedmemory;
  sharedmemory=0;
  return item;
}

void put(int item)
{
  sharedmemory=item;
}


void * producer()
{
  int item;
  while(1)
  { 
    item=produce_item();
    sem_wait(&prodLock);put(item);
    printf("Producer produced the item:%d\n",item);
    sem_post(&conLock);
  }
}

void * consumer()
{int item;
while(1)
  {
    sleep(1);
    sem_wait(&conLock);
     item=get();
    printf("Consumer consumed : %d\n",item);
    sem_post(&prodLock);}
}



int main()
{
  pthread_attr_t *attr=NULL;
  pthread_t pId;
  pthread_t cId;
  
  sem_init(&prodLock,0,1);
  sem_init(&conLock,0,0); 

  pthread_create(&pId,attr,producer,0);
  pthread_create(&cId,attr,consumer,0);

  pthread_join(pId,NULL);
  pthread_join(cId,NULL);

  return 0;
}
