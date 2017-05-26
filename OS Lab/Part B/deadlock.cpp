#include<iostream>
#include<cstring>
using namespace std;
struct process
{
int max[3];
int allocated[3];
int need[3];
string pname;
bool isProcessed;
};
int main()
{
int n,total[3],available[3],i,j,select;
string sequence;
bool flag;
cout<<"Enter max for each resource";
cin>>total[0]>>total[1]>>total[2];
for(i=0;i<3;i++)
available[i]=0;
cout<<"Enter the number of processess"<<endl;
cin>>n;
struct process *p = new struct process[n];
for(i=0;i<n;i++)
{
	cout<<"Enter name of"<<i<<"process"<<endl;
	cin>>p[i].pname;
	cout<<"Enter max for"<<i<<"process"<<endl;
	cin>>p[i].max[0]>>p[i].max[1]>>p[i].max[2];
	cout<<"Enter allocated for"<<i<<"process"<<endl;
	cin>>p[i].allocated[0]>>p[i].allocated[1]>>p[i].allocated[2];
	p[i].need[0]=p[i].max[0]-p[i].allocated[0];
	p[i].need[1]=p[i].max[1]-p[i].allocated[1];
	p[i].need[2]=p[i].max[2]-p[i].allocated[2];
	p[i].isProcessed=false;
}
available[0]=total[0];
available[1]=total[1];
available[2]=total[2];
for(i=0;i<n;i++)
{
available[0]-=p[i].allocated[0];
available[1]-=p[i].allocated[1];
available[2]-=p[i].allocated[2];
}
i=0;
select=-1;
while(i<n)
{
	for(j=0;j<n;j++)
	if(p[j].need[0]<available[0] && p[j].need[1]<available[1] && p[j].need[2]<available[2] && p[j].isProcessed==false)
	{
		select=j;
		flag=true;
		break;
	}
	if(flag)
	{
		flag=false;
		sequence.append(p[select].pname);
		sequence.append(",");
		p[select].isProcessed=true;
		available[0]+=p[select].need[0];
		available[1]+=p[select].need[1];
		available[2]+=p[select].need[2];
		i++;
	}
	else{
		cout<<"No safe sequence";
		return 1;
	}
}
cout<<"safe sequence is"<<sequence;
return 1;
}

