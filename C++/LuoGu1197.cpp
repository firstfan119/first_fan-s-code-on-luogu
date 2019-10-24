#include <bits/stdc++.h>
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

const int maxn=1e6+7;
int f[maxn];
vector<int> e[maxn];
//ÁÚ½Ó±í´æ±ß
bool brk[maxn];//break or not

int opr[maxn];//operation

int ans[maxn];//the block after operation

int n,m,k;

int cnt=0;

int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}
inline void connect(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv)
	{
		cnt--;
		f[fu]=fv;
	}
}

int main()
{
	n=read();
	m=read();
	for(ri i=0; i<=n; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		int u=read(),v=read();
		e[u].push_back(v) ;
		e[v].push_back(u) ;
	}
	scanf("%d",&k);
	cnt=n-k;
	for(ri i=1; i<=k; i++)
	{
		opr[i]=read();
		brk[opr[i]]=true;
	}
	for(ri i=0; i<n; i++)
	{
		if(brk[i])
		{
			continue;
		}
		for(ri j=0; j<(signed)e[i].size(); j++)
		{
			if(brk[e[i][j]])
			{
				continue;
			}
			connect(i,e[i][j]);
		}

	}
	for(ri i=k; i>=1; i--)
	{
		ans[i]=cnt++;
		brk[opr[i]]=0;
		for(ri j=0; j<(signed)e[opr[i]].size(); j++)
		{
			if(!brk[e[opr[i]][j]])
			{
				connect(opr[i],e[opr[i]][j]);
			}
		}
	}
	printf("%d\n",(ans[0]=cnt));
	for(ri i=1; i<=k; i++)
	{
		printf("%d\n",ans[i]);
	}
}
/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7
out:
1
1
1
2
3
3
*/
