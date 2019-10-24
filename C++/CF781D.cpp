#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long lol;
template<typename T>
inline void gg(T &res)
{
	res=0;
	T fh=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')fh=-1,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	res*=fh;
}
inline int gi()
{
	int x;
	gg(x);
	return x;
}
inline lol gl()
{
	lol x;
	gg(x);
	return x;
}
const int N=510;
const int K=63;
const lol INF=1e18;
bitset <N> g[2][K][N],p,c;
lol mi[K];
int main()
{
	int n=gi(),m=gi();
	mi[0]=1;
	for(int i=1; i<K; i++)mi[i]=mi[i-1]<<1;
	for(int i=1; i<=m; i++)
	{
		int u=gi(),v=gi(),t=gi();
		g[t][0][u][v]=1;
	}
	for(int k=1; k<K; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				if(g[0][k-1][i][j])g[0][k][i]|=g[1][k-1][j];
				if(g[1][k-1][i][j])g[1][k][i]|=g[0][k-1][j];
			}
	p[1]=1;
	lol ans=0;
	bool f=0;
	for(int k=K-1; k>=0; k--)
	{
		c.reset();
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(p[i]&&g[f][k][i][j])c[j]=1;
		if(c.any())
		{
			p=c;
			ans+=mi[k];
			f^=1;
		}
	}
	printf("%lld",ans>INF?-1:ans);
	return 0;
}
