#include <bits/stdc++.h>
using namespace std;
int num[100];
int lim;
int ans=20031125;
int want;
void dfs(int t,int now,int step)
{
	if(t==lim)
	{
		if(now==want&&step<ans)
		{
			ans=step;
		}
		return;
	}
	for(int j=t+1; j<=lim; j++)
	{
		int sum=0;
		for(int i=t+1; i<=j; i++)
		{
			sum+=num[i]*pow(10,j-i);
		}
		dfs(j,now+sum,step+1);
	}
	return;
}
int main()
{
	char ch[500];
	cin>>ch;
	lim=0;
	while(ch[lim]!='\0')
	{
		num[lim]=(int)(ch[lim]-(int)'0');
		lim++;
	}
	lim--;
	scanf("%d",&want);
	dfs(-1,0,0);
	ans--;
	if(ans>=2003)
	{
		cout<<-1;
	}
	else
	{
		cout<<ans<<endl;
	}
}
/*
99999
45
out:
3
*/
