#include <bits/stdc++.h>
using namespace std;
int numlist[20];
bool used[15];
int n;
void dfs(int now_place)
{
	if(now_place==n)
	//ÌîÂú
	{
		for(int i=0;i<n;i++)
		{
			printf("%5d",numlist[i]);
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			numlist[now_place]=i;
			used[i]=true;
			dfs(now_place+1);
			used[i]=false;
		}
	}
}
int main()
{
	cin>>n;
	dfs(0);
}

