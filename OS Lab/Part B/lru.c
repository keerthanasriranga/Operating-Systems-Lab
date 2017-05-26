#include<stdio.h>
void main()
{
int p[20],fr[5],n,i,j,k,l,fn,fs[5],pf=0,index;
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("enter the elements\n");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("Enter frame size");
scanf("%d",&fn);
for(i=0;i<fn;i++)
fr[i]=-1;
int flag1,flag2;
for(j=0;j<n;j++)
{
	printf("\n%d\n\n",p[j]);
	flag1=0,flag2=0;
	for(i=0;i<fn;i++)
	if(fr[i]==p[j])
	{
		flag1=1;
		flag2=1;
		printf("Inserted in loop 1\t");
		break;
	}
	if(flag1==0)
	{
		for(i=0;i<fn;i++)
		{		
			
			if(fr[i]==-1)
			{
				fr[i]=p[j];
				flag2=1;
				printf("Inserted in loop 2\t");
				break;
			}
		}
	}
	if(flag2==0)
	{
		for(i=0;i<fn;i++)
		fs[i]=0;
		for(k=j-1,l=1;l<=fn-1;l++,k--)
		{
			for(i=0;i<fn;i++)
			if(p[k]==fr[i])fs[i]=1;
		}
		for(i=0;i<fn;i++)if(fs[i]==0)index=i;
		fr[index]=p[j];
		pf++;
	}
	for(i=0;i<fn;i++)printf("%d\n",fr[i]);
}
printf("\n The nnumber of page faults are %d",pf);
}

		
	
