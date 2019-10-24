#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 210
int f[MAXN][MAXN];
int t[MAXN];
int k,m,n,u,v,w,q,r;
void read(int &n)
{
	char c;
	while((c=getchar())<48||c>57);
	n=c-48;
	while((c=getchar())>=48&&c<=57) n=n*10+c-48;
}
int main()
{
	read(n);
	read(m);
	memset(f,0x3f,sizeof(f));
	for(register int i=1; i<=n; i++) read(t[i]),f[i][i]=0;
	for(register int i=1; i<=m; i++)
	{
		read(u),read(v),read(w);
		u++,v++;
		f[v][u]=f[u][v]=w;
	}
	read(q);
	k=1;
	for(r=1; r<=q; r++)
	{
		read(u),read(v),read(w);
		u++,v++;
		for(; k<=n&&t[k]<=w; k++)
		{
			for(register int i=1; i<=n; i++)
			{
				for(register int j=1; j<=n; j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		if(f[u][v]!=f[0][0]&&t[u]<=w&&t[v]<=w)
		{
			printf("%d\n",f[u][v]);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
