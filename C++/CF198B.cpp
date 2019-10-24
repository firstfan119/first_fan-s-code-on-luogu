#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}

const int maxn=1e6+7;
char maap[2][maxn];
bool vis[2][maxn];
int n;
int jmp;
bool success=false;

void dfs(int x,int y,int d)
{
	vis[x][y]=true;
	if(y+jmp>n||success)
	{
		success=1;
		return;
	}
	if(maap[1-x][y+jmp]=='-'&&!vis[1-x][y+jmp])
	{
		dfs(1-x,y+jmp,d+1);
	}
	if(success)
	{
		return;
	}
	if(y>d+2)
	{
		if(maap[x][y-1]=='-'&&!vis[x][y-1])
		{
			dfs(x,y-1,d+1);
		}
	}
	if(success)
	{
		return;
	}
	if(maap[x][y+1]=='-'&&!vis[x][y+1])
	{
		dfs(x,y+1,d+1);
	}
}

int main()
{
	n=read()-1;
	jmp=read();
	scanf("%s",maap[0]);
	scanf("%s",maap[1]);
	dfs(0,0,-1);
	return 0&(int)printf("%s",success?("YES"):("NO"));
}
/*
7 3
---X--X
-X--XX-
out:
YES
*/
