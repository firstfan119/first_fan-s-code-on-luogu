#include <bits/stdc++.h>
#define ll long long
#define ri register int
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

const int maxn=1e4+5;
int num[1001];
int opt[1001];
int mn[1001];

int Stk[1001];
int Top;
int stk[1001];
int top;

bool vis[1001][1001];
int n;
void dfs(int x,int y)
{
	opt[x]=y;
	for(ri i=1; i<=n; i++)
	{
		if(vis[i][x])
		{
			if(opt[i]==y)
			{
				printf("0");
				exit(0);
			}
			else if(opt[i]==0)
			{
				dfs(i,y^1);
			}
		}
	}
}
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		num[i]=read();
	}
	mn[n+1]=n+1;
	for(ri i=n; i; i--)
	{
		mn[i]=min(mn[i+1],num[i]);
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=i+1; j<=n; j++)
		{
			if(num[i]<num[j]&&num[i]>mn[j])vis[i][j]=vis[j][i]=1;
		}
	}
	for(ri i=1; i<=n; i++)
	{
		if(opt[i]==0)
		{
			dfs(i,2);
		}
	}
	int l=1;
	int cur=1;
	num[0]=n+1;
	while(cur<=n)
	{
		if(opt[l]==2&&num[Stk[Top]]>num[l])
		{
			printf("a ");
			Stk[++Top]=l++;
		}
		else if(cur==num[Stk[Top]])
		{
			printf("b ");
			Top--;
			cur++;
		}
		else if(opt[l]==3&&num[stk[top]]>num[l])
		{
			printf("c ");
			stk[++top]=l++;
		}
		else if(cur==num[stk[top]])
		{
			printf("d ");
			top--;
			cur++;
		}
	}
}
