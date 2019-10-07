//Address translation in paging
#include<stdio.h>
#include<unistd.h>
#define N  8

int page[N];
int main()
{
  int i;
  int logical_address,physical_address,p_no,offset;

    for(i=0;i<N;i++)
    {
        printf("pageno %d: Enter frame no ",i);
        scanf(" %d",&page[i]);
    }

  while(1)
  {
    printf("Enter the Logical Address :");
    scanf("%d",&logical_address);  
     if(logical_address==-1) ||(logical_address > (N*4)
 break;
    p_no=(logical_address/4);
    printf("%d %d",p_no,page[p_no]);
    offset=logical_address%4;
    if(page[p_no]==-1)
       printf("\npage fault: given logical address hasn't been loadded in the RAM");
    else
    {
        physical_address=page[p_no]*4+offset;
        printf("\nPhysical Address : %d",physical_address);
    }
 }
  return 0;
}
