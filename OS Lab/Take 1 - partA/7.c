#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
pid_t  pid;
int i;
for(i=0;i<3;i++)
{
	pid=fork();
	if(pid<0)
	{
		printf("Error\n");
		exit(0);
	}
	else if(pid==0)
	{
	printf("Child process %d is %d\n",(i+1),getpid());
	}
	else
	{
	wait(NULL);
	if(i==2)
	printf("Child Process %d completed\n",i+1);
	}
}
}



