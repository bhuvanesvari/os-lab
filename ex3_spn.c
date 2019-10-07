//cpu scheduling using spn
#include<stdio.h>
#include<stdlib.h>
struct process
{
  char name[3];
  int at,st,wt;
 }pro[100],temp;
int main()
{
  int i,x,j,n,tot_wt;
  float avg_wt;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  getchar();
  printf("Enter the names of the processes\n");
  for(j=0;j<n;j++)
  {
    fgets(pro[j].name,sizeof(pro[j].name),stdin);
    }
  printf("Enter the arrival time\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&pro[i].at);
    }
    
  printf("Enter the service time\n");  
  for(i=0;i<n;i++)
  {
    scanf("%d",&pro[i].st);
    }
 //In spn the input should be sorted based on the service time
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(pro[j].st<pro[i].st)
        {
           temp=pro[j];
           pro[j]=pro[i];
           pro[i]=temp;
         }
     }
  }
  //calculation of waiting time for each process
  for(i=1;i<=n;i++)
  {
    x=0;
    for(j=i;j!=0;j--)
    {
     x=x+pro[j-1].st;
    }
    pro[i].wt=x-pro[i].at;
  
  }
  tot_wt=0;
   for(i=0;i<n;i++)
   {
      tot_wt+=pro[i].wt;
      printf(" Process Name:%s Arrival time: %d Service time: %d Waiting time: %d\n",pro[i].name,pro[i].at,pro[i].st,pro[i].wt);
   } 
   avg_wt=(float)tot_wt/n;
   printf("Average waiting time: %f\n",avg_wt);
    return 0;
  }
     
    
    
  
  
  
