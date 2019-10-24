#include<bits/stdc++.h>
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

const int maxn=125;

struct node
{
	int v[4];
} o[maxn];

int V[4];
int f[maxn][maxn];
int t[maxn][maxn];

int main()
{
	int n=read();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=3;j++)
		{
			o[i].v[j]=read();
		}
	}
	V[1]=read();
	V[2]=read();
	for(ri k=1; k<=n; k++)
	{
		for(ri i=V[1]; i>=o[k].v[1]; i--)
		{
			for(ri j=V[2]; j>=o[k].v[2]; j--)
			{
				if (f[i][j]<f[i-o[k].v[1]][j-o[k].v[2]]+1)
				{
					f[i][j]=f[i-o[k].v[1]][j-o[k].v[2]]+1;
					t[i][j]=t[i-o[k].v[1]][j-o[k].v[2]]+o[k].v[3];
				}
				if (f[i][j]==f[i-o[k].v[1]][j-o[k].v[2]]+1)
				{
					t[i][j]=min(t[i][j],t[i-o[k].v[1]][j-o[k].v[2]]+o[k].v[3]);
				}
			}
		}
	}
	return 0&printf("%d",t[V[1]][V[2]]);
}
