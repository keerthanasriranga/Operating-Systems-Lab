#include<stdio.h>
#include<stdlib.h>
int full=0,empty=3,mutex=1,c,x=0;
int signal(int s){return (++s);}
int wait(int s){return (--s);}

void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("%d item produced",x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);

printf("%d item consumed",x);
x--;
mutex=signal(mutex);
}

void main()
{

while(1){
printf("\nEnter 1)Producer2)Consumer3)Exit\n");
scanf("%d",&c);
switch(c)
{
	case 1 : if(mutex==1&&empty!=0)
		producer();
		else
		printf("Buffer is empty");
		break;
	case 2 : if(mutex==1&&full!=0)
		consumer();
		else
		printf("Buffer is empty");
		break;
	default:exit(0);
}
}
}

