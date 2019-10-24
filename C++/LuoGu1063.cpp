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

const int maxn=1125;
int f[maxn][maxn];
int v[maxn];

int main()
{
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		v[i+n]=v[i]=read();
	}
	for(ri i=1; i<=2*n; i++)
	{
		for(ri j=i-1; j>0; j--)
		{
			for(ri k=j; k<i; k++)
			{
				f[j][i]=max(f[j][i],v[j]*v[k+1]*v[i+1]+f[j][k]+f[k+1][i]);
			}
		}
	}
	int ans=-1;
	for(ri i=1; i<=n; i++)
	{
		ans=max(ans,f[i][i+n-1]);
	}
	return 0&printf("%d",ans);
}
