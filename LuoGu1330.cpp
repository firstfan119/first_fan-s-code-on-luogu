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
int f[maxn];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

int siz[maxn];
int enm[maxn];
//异色点
bool vis[maxn];
int ans=0;

int main()
{
	int n=read();
	int m=read();
	for(ri i=1;i<=n;i++)
	{
		f[i]=i;
		siz[i]=1;
	}
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		int fu=find(u);
		int fv=find(v);
		if(fu!=fv)
		{
			if(enm[u])
			{
				int fe=find(enm[u]);
				if(fe!=fv)
				{
					f[fv]=fe;
					siz[fe]+=siz[fv];
				}
			}
			if(enm[v])
			{
				int fe=find(enm[v]);
				if(fe!=fu)
				{
					f[fu]=fe;
					siz[fe]+=siz[fu];
				}
			}
			enm[u]=fv;
			enm[v]=fu;
		}
		else
		{
			return 0&(int)printf("Impossible");
		}
	}
	for(ri i=1;i<=n;i++)
	{
		int fi=find(i);
		int fe=find(enm[i]);
		if(!vis[fi])
		{
			vis[fi]=true;
			vis[fe]=true;
			ans+=min(siz[fi],siz[fe]);
			//敌我两方选一方，站队
		}
	}
	return 0&printf("%d",ans);
}
/*
3 2
1 2
2 3
out:
1
*/
