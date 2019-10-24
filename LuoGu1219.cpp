#include <bits/stdc++.h>
using namespace std;
int cnt=0;
bool line[30];
bool diagnal1[30];
bool diagnal2[30];
bool put[30][30];
int n;
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(put[i][j])
			{
				cout<<j<<" ";
				break;
			}
		}
	}
	cout<<endl;
}
void dfs(int row)
{
	if(row>n)
	{
		if(cnt<3)
		{
			print();
		}
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!line[i]&&!diagnal1[i-row+n+1]&&!diagnal2[i+row+n+1])
		{
			line[i]=true;
			diagnal1[i-row+n+1]=true;
			diagnal2[i+row+n+1]=true;
			put[row][i]=true;
			dfs(row+1);
			line[i]=false;
			diagnal1[i-row+n+1]=false;
			diagnal2[i+row+n+1]=false;
			put[row][i]=false;
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt;
}
