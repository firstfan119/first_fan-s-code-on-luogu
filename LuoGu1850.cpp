#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
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

db f[2048][2048][2],k[2048];
int n,m,e,v,dis[320][320];
int c[2048],d[2048];

int main()
{
	n=read();
	m=read();
	v=read();
	e=read();
	for(ri i=1; i<=n; i++)
	{
		c[i]=read();
	}
	for(ri i=1; i<=n; i++)
	{
		d[i]=read();
	}
	for(ri i=1; i<=n; i++)
	{
		scanf("%lf",&k[i]);
	}
	memset(dis,0x3f,sizeof(dis));
	for(ri i=1; i<=e; i++)
	{
		int a=read();
		int b=read();
		int w=read();
		dis[a][b]=dis[b][a]=min(dis[a][b],w);
	}
	for(ri t=1; t<=v; t++)				//floyd
	{
		dis[t][t]=0;
		for(ri i=1; i<=v; i++)
		{
			for(ri j=1; j<=v; j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
			}
		}
	}

	for(ri i=0; i<=n; i++)
		for(ri j=0; j<=m; j++)
		{
			f[i][j][0]=f[i][j][1]=99999999999;
		}

	f[1][0][0]=f[1][1][1]=0;

	for(ri i=2; i<=n; i++)
	{
		f[i][0][0]=f[i-1][0][0]+dis[c[i-1]][c[i]];
		for(ri j=1; j<=min(i,m); j++)
		{
			f[i][j][0]=min(f[i-1][j][0]+(db)dis[c[i-1]][c[i]],f[i-1][j][1]+k[i-1]*(db)dis[d[i-1]][c[i]]+(1-k[i-1])*(db)dis[c[i-1]][c[i]]);
			f[i][j][1]=min(f[i-1][j-1][1]+k[i-1]*k[i]*(db)dis[d[i-1]][d[i]]+k[i-1]*(1-k[i])*(db)dis[d[i-1]][c[i]]+(1-k[i-1])*k[i]*(db)dis[c[i-1]][d[i]]+(1-k[i-1])*(1-k[i])*(db)dis[c[i-1]][c[i]],f[i-1][j-1][0]+k[i]*(db)dis[c[i-1]][d[i]]+(1-k[i])*(db)dis[c[i-1]][c[i]]);//ÒÚµã×ªÒÆ
		}
	}
	db q=f[n][0][0];
	for(ri i=1; i<=m; i++)
	{
		q=min(q,min(f[n][i][0],f[n][i][1]));
	}

	return 0&(int)printf("%.2lf",q);
}
