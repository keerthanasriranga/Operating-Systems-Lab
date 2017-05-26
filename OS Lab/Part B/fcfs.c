#include<stdio.h>
#include<stdlib.h>
void main()
{
int
n,bt[10],at[10],temp1,temp2,i,j,wt[10],sum_wt=0,sum_tt=0,exec[10],tt[10],pn[10];
printf("Enter the number of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter the at,bt of %d process\n",i+1);
	scanf("%d",&at[i]);
	scanf("%d",&bt[i]);
	pn[i]=i;
}
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
	if(at[i]>at[j])
	{
		temp1=pn[i];
		pn[i]=pn[j];
		pn[j]=temp1;
		
		temp2=bt[i];
		bt[i]=bt[j];
		bt[j]=temp2;
	}
}
wt[0]=0;
exec[0]=bt[0];
tt[0]=bt[0];
for(i=1;i<n;i++)
{
	exec[i]=exec[i-1]+bt[i];
	wt[i]=exec[i-1]-at[i];
	tt[i]=wt[i]+bt[i];
	sum_wt+=wt[i];
	sum_tt+=tt[i];
}
printf("\nAverage turnourand time is %f\n",(sum_tt*1.0)/n);
printf("\nAverage waitng time is %f\n",(sum_wt*1.0)/n);
printf("-------Gnatt Chart----------\n");
for(i=0;i<n;i++)
{
	printf("\t%d\t",pn[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
	printf("\t\t%d",exec[i]);
}
}
