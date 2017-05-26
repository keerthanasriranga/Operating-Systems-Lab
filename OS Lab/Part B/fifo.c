#include<stdio.h>
void main()
{
int p[20],fr[5],n,i,j,k,l,fn,fs[5],pf=0,pgavl,flag=0;
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("enter the elements\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("Enter frame size");
scanf("%d",&fn);
for(i=0;i<fn;i++)
fr[i]=-1;
k=0;
for(j=1;j<=n;j++)
{
	pgavl=0,flag=0;
	for(i=0;i<fn;i++)
	if(fr[i]==p[j])
	{
		pgavl=1;
		break;
	}
	if(pgavl==0)
	{
		for(i=0;i<fn;i++)
		if(fr[i]==-1)
		{
			fr[i]=p[j];	
			pf++;
			flag=1;
			break;
		}
		if(flag==0)
		{
			fr[k]=p[j];
			k=(k+1)%fn;
			pf++;
		}
	}
	printf("\nInserting %d\n\n",p[j]);
	for(i=0;i<fn;i++)printf("%d\n",fr[i]);
}
printf("\nNumber of page faults are %d",pf);
}
		
