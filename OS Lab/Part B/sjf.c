#include<stdio.h>
#include<stdlib.h>
void main()
{
int
n,bt[10],at[10],temp[10],g1[30],g2[30],sum_wt=0,sum_tt=0,i,j,time,smallest,k=0;
printf("Enter the number of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter the at,bt of %d process\n",i+1);
	scanf("%d",&at[i]);
	scanf("%d",&bt[i]);
	temp[i]=bt[i];
}
int count=0;
int s1=-1,s2=-1;
bt[9]=9999;
printf("Process\tWaiting time\tTurnaround Time\n");
for(time=0;count!=n;time++)
{
	smallest=9;
	for(i=0;i<n;i++)
	{
		if(bt[i]<bt[smallest] && at[i]<=time && bt[i]>0)
		{
			if(s2==-1)s1=i,s2=0;
			smallest=i;
		}
	}
	bt[smallest]--;
	if(smallest!=i)
	{
		g1[k]=s1+1;
		g2[k++]=time;
	}
	if(bt[smallest]==0)
	{
		count++;
		printf("p[%d]\t%d\t%d\n",smallest+1,time+1-temp[smallest]-at[smallest],time+1-at[smallest]);
		sum_wt+=time+1-temp[smallest]-at[smallest];
		sum_tt+=time+1-at[smallest];
	}
	s1=smallest;
	
}
g1[k]=s1+1;
g2[k++]=time;
printf("\n average tt time %f\n",(sum_tt*1.0)/n);
printf("\n average wt time %f\n",(sum_wt*1.0)/n);
printf("----Gnatt Chart-----\n");
for(i=0;i<k-1;i++)
printf("\t%d\t",g1[i]);
printf("\n");
for(i=0;i<k-1;i++)
printf(" \t\t%d",g2[i]);
}
