//cpu scheduling using rr without arrival time
#include<stdio.h>
#include<stdlib.h>
int main()
{
  char pro[]={'A','B','C'};
  int i;
  int st[10],temp[10],wt[1];
  int tq,t,flag,n,avg_wt;
  flag=0;// not completed
  printf("Enter the total number of processes(Arrival time is 0)\n");
  scanf("%d",&n);
  printf("Enter the time slice\n");
  scanf("%d",&tq);
  printf("Enter the service time\n");
  for(i=0;i<n;i++)
    {scanf("%d",&st[i]);}

  for(i=0;i<n;i++)
  { 
     
     temp[i]=st[i];
  }
  t=0;
  i=0;
  while(1)
  { 
    flag=1;
     for(i=0;i<n;i++)
     {
        if(temp[i]>0)
        {
          flag=0;
          if(temp[i]>tq)
          {
            t+=tq;
            temp[i]=temp[i]-tq;
          }
          else
          {
            t=t+temp[i];
            wt[i]=t-st[i];
            temp[i]=0;
          }
        }
      }     
     if(flag==1)
     {
       break;
     }
   }
   printf("The waiting time of the processes is\n");
  for(i=0;i<n;i++)
  {
    avg_wt+=wt[i];
    printf("%d\n",wt[i]);
  }
   avg_wt=avg_wt/n;
   printf("The average waiting time is %d\n",avg_wt);
   
   return 0;
  
}
