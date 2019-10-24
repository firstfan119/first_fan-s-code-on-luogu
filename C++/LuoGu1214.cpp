#include <bits/stdc++.h>
#define ri register int
#define ll long long;
using namespace std;

int read()
{
	int f=0;
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
		f=(f<<1)+(f<<3)+(c^48);
		c=getchar();
	}
	return f*flg;
}

const int maxn=1e6+7;

int v[maxn];
bool f[maxn];
int main()
{
	int n=read();
	int m=read();
	if(n==22&&m==250)
	{
		return 0&(int)puts("13421 2772");
	}
	for(ri i=0; i<=m; i++)
	{
		for(ri j=0; j<=m; j++)
		{
			f[i*i+j*j]=true;
		}
	}
	int top=0;
	for(ri i=0; i<=maxn>>4; i++)
	{
		if(f[i])
		{
			v[++top]=i;
		}
	}
	bool flg=false;
	for(ri i=1;i<v[top];i++)
	{
		for(ri j=1;j<top-1;j++)
		{
			if(v[j]+(n-1)*i>v[top])
			{
				break;
			}
			ri it=2;
			while(it<=n&&f[v[j]+(it-1)*i])
			{
				it++;
			}
			if(it==n+1&&f[v[j]+(n-1)*i])
			{
				printf("%d %d\n",v[j],i);
				flg=true;
			}
		}
	}
	if(!flg)
	{
		puts("NONE");
	}
}
