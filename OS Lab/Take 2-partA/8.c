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
printf("Child process %d parent id %d\n",getpid(),getppid());
}
else{
wait(NULL);
printf("parent Process %d child id %d\n",getpid(),pid);
exit(0);
}
}
}
