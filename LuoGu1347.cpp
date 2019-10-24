#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=1e7+6;
int a,b,n,m,s,sum,cnt=0;
int head[maxn],rd[maxn],regis[maxn];
int in[maxn];
bool flg,ukn,vis[maxn];
queue<int>q;
char ch;
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return flg*num;
}
struct Edge
{
	int to;
	int nex;
} e[maxn];
void add(int x,int y)
{
	in[y]++;
	e[++cnt].to=y;
	e[cnt].nex=head[x];
	head[x]=cnt;
}
int topo()
{
	ukn=false;
	flg=false;
	sum=0;
	for(ri i=1; i<=26; i++)
	{
		rd[i]=in[i];
		if(!rd[i]&&vis[i])
		{
			if(!flg)
			{
				flg=true;
			}
			else ukn=true;
			q.push(i);
			regis[++sum]=i;
		}
	}
	if(q.empty())
	{
		return q.empty();
	}
	while(!q.empty())
	{
		int x=q.front();
		flg=false;
		q.pop();
		for(ri i=head[x]; i; i=e[i].nex)
		{
			rd[e[i].to]--;
			if(!rd[e[i].to])
			{
				q.push(e[i].to);
				if(!flg)
				{
					flg=true;
				}
				else
				{
					ukn=true;
				}
				regis[++sum]=e[i].to;
			}
		}
	}
	if(sum!=s)
	{
		return 1;
	}
	if(ukn)
	{
		return 2;
	}
	return 0;
}
int main()
{
	n=read(),m=read();
	for(ri i=1; i<=m; i++)
	{
		cin>>ch;
		a=ch-'@';
		if(!vis[a])
		{
			vis[a]=true;
			s++;
		}
		cin>>ch;
		cin>>ch;
		b=ch-'@';
		if(!vis[b])
		{
			vis[b]=true;
			s++;
		}
		add(a,b);
		if(topo()==1)
		{
			printf("Inconsistency found after %d relations.",i);
			return 0;
		}
		if(sum==n&&!topo())
		{
			printf("Sorted sequence determined after %d relations: ",i);
			for(int j=1; j<=n; j++)
			{
				printf("%c",regis[j]+'@');
			}
			printf(".");
			return 0;
		}
	}
	printf("Sorted sequence cannot be determined.");
	return 0;
}
