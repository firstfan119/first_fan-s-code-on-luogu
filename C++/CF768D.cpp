#include <bits/stdc++.h>
#define ri int
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

const int maxn=11250;
db f[maxn][2019];

int main()
{
	int n=read();
	int q=read();
	f[0][0]=1.0;
	for(ri i=1; i<=11000; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			f[i][j]+=f[i-1][j]*j/n;
			f[i][j]+=f[i-1][j-1]*(n-(j-1))/n;
		}
	}
	while(q--)
	{
		db p=read()/2000.0;
		for(ri i=1;i<=11000;i++)
		{
			if(f[i][n]>p)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}
