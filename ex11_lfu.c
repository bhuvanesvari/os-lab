 Page repalcement using lfu
#define N  4

#include<stdio.h>


void init();
void display();
int global_time();
int lfu();
int lfu_time(int);
int is_free_slot_avilable();
int isitinRAM(int );
struct RAM
{
  int pno;
  int time;
  int frq;
}frame[N];

int q_ptr=0;
int main()
{
   int p_no,f_no;

   init();
   display();

   while(1)
   {
      printf("\nRequest Page.No: ");
      scanf("%d",&p_no);      if(p_no==-1) break;
	if( (f_no=isitinRAM(p_no)) != -1 )
	{
	    printf("\nPage Hit");
	    frame[f_no].time=global_time();
	    frame[f_no].frq++;

	}
	else
	{
	   printf("\nPage Miss");
	   if( (f_no=is_free_slot_avilable()) != -1)
	   {   frame[f_no].pno=p_no;
	       frame[f_no].time=global_time();
	       frame[f_no].frq=1;
	   }
	   else
	   {
	      f_no=lfu();
	      f_no=lfu_time(frame[f_no].frq);
	      frame[f_no].pno=p_no;
	      frame[f_no].time=global_time();
	      frame[f_no].frq=1;
	   }

	}
       display();
   }

   getch();
   return 0;
}
int lfu_time(int frq)
{
   int i,min=9999,f_no;
   for(i=0;i<N;i++)
     if(frame[i].time<min && frame[i].frq==frq)
     {
	min=frame[i].time;
	f_no=i;
     }
  return f_no;
}

int lfu()
{
   int i,min=9999,f_no;
   for(i=0;i<N;i++)
     if(frame[i].frq<min)
     {
	min=frame[i].frq;
	f_no=i;
     }
  return f_no;
}

int global_time()
{
  static int t=0;
  return ++t;
}
int is_free_slot_avilable()
{
  int i;
  for(i=0;i<N;i++)
  if(frame[i].pno==-1)
    return i;

  return -1;

}
int isitinRAM(int p_no)
{ int i;
  for(i=0;i<N;i++)
  if(frame[i].pno==p_no)
    return i;

  return -1;
}
void init()
{ int i;
  for(i=0;i<N;i++)
    frame[i].frq=frame[i].time=frame[i].pno=-1;
}
void display()
{ int i;
  printf("\nFrame(RAM)  Time     Frequency" );
  for(i=0;i<N;i++)
    printf("\n%4d %10d %10d",frame[i].pno,frame[i].time,frame[i].frq);

}
