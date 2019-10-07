 Page repalcement using optimal
#include<stdio.h>

void main()

{

  int s;

  int mm[10],re[3330];

  int i,j;

  int k,l;

  int n,x;
  
  int sa[10];

  printf("enter main memory size");

  scanf("%d",&s);

  printf("\nenter number of elements in reference string");

  scanf("%d",&n);

  printf("\nenter elements of reference string");

  for(i=0;i<n;i++)

     scanf("%d",&re[i]);

  for(i=0;i<n;i++)

     printf("%d",re[i]);



  for(j=0;j<s;j++)

      mm[j]=-1;



  for(i=0;i<n;i++)

   {


       for(j=0;j<s;j++)

         {

            if(mm[j]==re[i])

              {

                 break;

              }

         }



       if(j>=s)

        {

             for(j=0;j<s&&mm[j]!=-1;j++);

             if(j<s)

                mm[j]=re[i];

             else

              {

                 l=0;
                 printf("\nPAGE FAULT OCCURS:\n");
                 for(j=0;j<s;j++)
                    {
                       for(k=i+1;(k<n)&&(mm[j]!=re[k]);k++);
                       if(k<n)
                       {
                           sa[j]=(k+1);
                           
                       }
                       else
                       {    
                           sa[j]=99999;
                           
                       }
                    }                           
                  x=0;
                  for(l=0;l<s;l++)
                    {
                       if(sa[l]>x)
                        {
                          x=sa[l];
                          k=l;
                        }
                    }

                  mm[k]=re[i];

              }

              for(j=0;j<s;j++)


                {

                   printf("%4d\t",mm[j]);

                }

              printf("\n");

        }

    }
}




