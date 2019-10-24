#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cnt=0;
	int m,n,k;
	int x,y;
	bool maap[1007][1007];
	cin>>n>>m>>k;
 for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		maap[x][y]=true;

		maap[x+1][y]=true;
		maap[x+2][y]=true;
		maap[x-1][y]=true;
		maap[x-2][y]=true;
		maap[x][y+1]=true;
		maap[x][y+2]=true;
		maap[x][y-1]=true;
		maap[x][y-2]=true;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		for(int i=x-2;i<=x+2;i++)
		{
			for(int j=y-2;j<=y+2;j++)
			{
				maap[i][j]=true;
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(!maap[i][j])
		{
			cnt++;
		}
	}cout<<cnt;
}
