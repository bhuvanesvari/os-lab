#include<stdio.h>
#include<stdlib.h>
struct process
{
  char name[3];
  int at,st,wt,ft,tat;
  float ntat;
 }pro[100],temp;
int main()
{
  int i,x,j,n,tot_wt,time,tot_tat;
  float avg_wt,avg_tat,tot_ntat,avg_ntat;
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
 time=0;
  for(i=0;i<n;i++)
  { 
    for(j=i+1;j<n;j++)
    {
      if(pro[j].st<pro[i].st && pro[j].at<=time)
        {
           temp=pro[j];
           pro[j]=pro[i];
           pro[i]=temp;
         }
        
     }
      time+=pro[i].st;
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
    pro[i-1].ft=x;
  }
  tot_wt=0;
   for(i=0;i<n;i++)
   {
      tot_wt+=pro[i].wt;
    } 
   
   //calculation of turn around time
   for(i=0;i<n;i++)
   {
	   pro[i].tat=pro[i].ft-pro[i].at;
	   pro[i].ntat=(float)pro[i].tat/pro[i].st;
	   printf(" Process Name:%3s Arrival time: %d Service time: %d Waiting time: %d Finish Time: %d Turn around Time:%d Normalized turn Around time: %f\n",pro[i].name,pro[i].at,pro[i].st,pro[i].wt,pro[i].ft,pro[i].tat,pro[i].ntat);
   }
    tot_tat=0;
	tot_ntat=0;
	for(i=0;i<n;i++)
	{
		tot_tat+=pro[i].tat;
		tot_ntat+=pro[i].ntat;
	}
	//calculation of average waiting time and mean turn around time
   avg_wt=(float)tot_wt/n;
   avg_tat=(float)tot_tat/n;
   avg_ntat=(float)tot_ntat/n;
   printf("Average waiting time: %f\n Mean Turn Around Time: %f\n Mean of Normalized turn around time:%f\n",avg_wt,avg_tat,avg_ntat);
   
    return 0;
  }
     
    
    
  
  
  
