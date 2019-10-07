//creation of child process and communication
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  int p[3];
  pid_t pid;
  char inbuf[10],outbuf[10];
  if(pipe(p)==-1)
    {
      printf("Pipe creation failed\n");
      }
  else
  {
    printf("Inter process communication pipe is created\n");
   }
    pid=fork();
   if(pid>0) 
      {
        printf("Child process created succesfully with id: %d \n",pid);
        printf("In parent procces: (process id) %d \n",getpid());
        printf("Enter the data to be sent to child\n");
        scanf("%s",outbuf);
        write(p[1],outbuf,10);
       }
   else if(pid==0)
     {
     sleep(10);
     printf("In child process:(child process id %d) waiting for data from parent process\n",getpid());
     read(p[0],inbuf,10);
     printf("The data recieved by the child (process id %d) from parent(process id %d) is %s\n",getpid(),getppid(),inbuf);
     }
    else
    {
    printf("Failed to create child process");
    }
    return 0;
    }
    
     
