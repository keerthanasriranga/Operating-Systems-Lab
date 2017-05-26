#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
int i;
pid_t pid;
for(i=0;i<3;i++)
{
pid=fork();
if(pid<0)
{
printf("Error");
exit(-1);
}
else if(pid==0)
{
printf("Child process %d process id %d\n",(i+1),getpid());
}
else{
wait(NULL);
if(i==2)
printf("--------------------\n");
printf("Process %d completed\n",(i+1));
exit(0);
}
}
}
