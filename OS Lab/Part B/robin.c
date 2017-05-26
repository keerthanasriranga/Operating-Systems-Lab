#include<stdio.h>
#include<stdlib.h>
void main()
{
int
n,bt[10],pt[10],at[10],temp[10],g1[20],g2[20],sum_wt=0,sum_tt=0,i,j,total,k=0,x,tq,counter=0;
printf("Enter the number of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter the at,bt,priority of %d process\n",i+1);
	scanf("%d",&at[i]);
	scanf("%d",&bt[i]);
	temp[i]=bt[i];
}
x=n;
printf("Enter time quantam\n");
scanf("%d",&tq);
printf("Process\tWaiting\tTurnaround\n");
for(total=0,i=0;x!=0;)
{
	if(temp[i]<=tq && at[i]<=total && temp[i]>0)
	{
		total+=temp[i];
		temp[i]=0;
		counter=1;
		g1[k]=i+1;
		g2[k++]=total;
	}
	else if(at[i]<=total && temp[i]>0)
	{
		total+=tq;
		temp[i]-=tq;
		g1[k]=i+1;
		g2[k++]=total;
	}
	if(counter==1 && temp[i]==0)
	{
		x--;
		counter=0;
		printf("p[%d]\t%d\t%d\n",i+1,total-at[i]-bt[i],total-at[i]);
		sum_tt+=(total-at[i]);
		sum_wt+=total-at[i]-bt[i];
	}
	i=(i+1)%n;
		
}
g1[k]=i+1;
g2[k++]=total;
printf("\nAverage waiting time : %f\n",(sum_wt*1.0)/n);
printf("\nAverage Turnaround time : %f\n",(sum_tt*1.0)/n);
for(i=0;i<k;i++)
if(i==0||g1[i]!=g1[i-1])printf("\t%d\t",g1[i]);
for(i=0;i<k-1;i++)
if(g1[i]!=g1[i+1])printf("\t%d\t",g2[i]);

}
