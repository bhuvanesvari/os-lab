//Banker's algorithm
#include<stdio.h>
char res[10]={'A','B','C','D','E','F','G','H','I','J'};
void disp(int m,int n,int alloc[5][5],int max[5][5],int avble[5],int need[5][5]);
void safesq(int m,int n,int alloc[5][5],int avble[5],int need[5][5]);
void main()
{
    int i,j,ch,n,m,work1[5];
    int avble[5],alloc[5][5],max[5][5],need[5][5];
    printf("\nENTER THE NUMBER OF PROCESSES : \t");
    scanf("%d",&n);
    printf("\nENTER THE NUMBER OF RESOURCES : \t");
    scanf("%d",&m);
    printf("\nENTER THE MAXIMUM INSTANCES OF EACH RESOURCE\n");
    for(i=0;i<m;i++)
    {
        printf("\n\tRESOURCE %c:\t",res[i]);
        scanf("%d",&avble[i] );
    }
    printf("\nENTER THE MAXIMUM DEMAND OF EACH PROCESS FOR A RESOURCE\n");
    for(i=0;i<n;i++)
    {
        printf("\n\tFOR PROCESS P%d \n",i);
        for(j=0;j<m;j++)
        {
            printf("\n\tRESOURCE %c : \t",res[j]);
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nENTER THE MAX NO. OF INSTANCES OF A RESOURCE ALLOCATED TO");
    printf(" A PROCESS.\n");
    for(i=0;i<n;i++)
    {
        printf("\n\tFOR PROCESS P%d \n",i);
        for(j=0;j<m;j++)
        {
            printf("\n\tRESOURCE %c : \t",res[j]);
            scanf("%d",&alloc[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        work1[i]=0;
        for(j=0;j<n;j++)
        {
           work1[i]+=alloc[j][i];
        }
        printf("%d",work1[i]);
        avble[i]=avble[i] - work1[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    while(1)
    {
        printf("\n\n\tMENU:\n\t1]DISPLAY DATA\n\t2]GENERATE SAFE SEQUENCE");
        printf("\n\t3]EXIT\n\tENTER YOUR CHOICE:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                disp(m,n,alloc,max,avble,need);
                break;
            case 2:
                safesq(m,n,alloc,avble,need);
                break;
            case 3:
                exit(0);
            default:
                printf("\n\tINVALID CHOICE ENTERED.\n");
        }
    }
}
void disp(int m,int n,int alloc[5][5],int max[5][5],int avble[5],int need[5][5])
{    int i,j;
    printf("\n\tALLOCATION\tMAX\tNEED\tAVAIL");
    printf("\t\t");
    for(i=0;i<4;i++)
    {
        for(j=0;j<m;j++)
            printf("%c ",res[j]);
        printf(" ");
    }
    for(i=0;i<n;i++)
    {
        printf("\n\tP%d\t",i);
        for(j=0;j<m;j++)
            printf("%d ",alloc[i][j]);
        printf(" ");
        for(j=0;j<m;j++)
            printf("%d ",max[i][j]);
        printf("\t");
        for(j=0;j<m;j++)
            printf("%d ",need[i][j]);
        printf(" ");
        if(i==0)
        {
            for(j=0;j<m;j++)
                printf("%d ",avble[j]);
        }
    }
}
void safesq(int m,int n,int alloc[5][5],int avble[5],int need[5][5])
{
    int i,j,k=0,l,work[5],work1[5],fin[5],flag=0,flag1=0,safesq[6];
    for(i=0;i<m;i++)
        work[i]=avble[i];
    for(i=0;i<n;i++)
        fin[i]=0;
    for(l=0;l<n;l++)
    {
        for(i=0;i<n;i++)
        {
            flag1=0;
            if(fin[i]==0)
            {
                for(j=0; j<m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag1=1;
                        break;
                    }
                }
                if(flag1==0)
                {
                    for(j=0;j<m;j++)
                        work[j]=work[j]+alloc[i][j];
                    fin[i]=1;
                    safesq[k]=i;
                    k++;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(fin[i]==0)
        {
            printf("\n\tFOR THE GIVEN REQUIREMENT THE SYSTEM IS");
            printf(" NOT IN A SAFE STATE.\n");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\n\tTHE SAFE SEQUENCE IS:\t");
        for(i=0;i<n;i++)
            printf("P%d ",safesq[i]);
    }
}