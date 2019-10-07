 Page repalcement using LRU
#define N  4

#include<stdio.h>
#include<conio.h>

void init();
void display();
int global_time();
int lru();
int is_free_slot_avilable();
int isitinRAM(int );
struct RAM
{
  int pno;
  int time;
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
	}
	else
	{
	   printf("\nPage Miss");
	   if( (f_no=is_free_slot_avilable()) != -1)
	   {   frame[f_no].pno=p_no;
	       frame[f_no].time=global_time();
	   }
	   else
	   {
	      f_no=lru();
	      printf("%d",f_no);
	      frame[f_no].pno=p_no;
	      frame[f_no].time=global_time();
	   }

	}
       display();
   }

   getch();
   return 0;
}
int lru()
{
   int i,min=9999,f_no;
   for(i=0;i<N;i++)
     if(frame[i].time<min)
     {
	min=frame[i].time;
	f_no=i;
     }
  printf("%d",f_no);
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
    frame[i].time=frame[i].pno=-1;
}
void display()
{ int i;
  printf("\nFrame(RAM)  Time");
  for(i=0;i<N;i++)
    printf("\n%4d %10d",frame[i].pno,frame[i].time);

}
