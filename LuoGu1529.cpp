#include <bits/stdc++.h>
#define ri register int
#define maxn 20031125
#define inf maxn
using namespace std;
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c>'9'||c<'0')
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
int cnt=0;
int head[maxn];
struct edge
{
	int to;
	int nex;
	int val;
	void add(int u,int v,int val,edge e[])
	{
		e[++cnt].to=v;
		e[cnt].val=val;
		e[cnt].nex=head[u];
		head[u]=cnt;
	}
}e[maxn];

int m;
int dis[maxn];
int vis[maxn];
void spfa()
{
	for(ri i=0;i<=144;i++)
	{
		dis[i]=inf;
	}
	queue<int> q;
	q.push('Z');
	vis['Z']=true;
	dis['Z']=0;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		vis[top]=false;//你是谁啊，我不认识你
		for(ri i=head[top];i;i=e[i].nex)
		{
			int to=e[i].to;
			if(dis[to]>dis[top]+e[i].val)
			{
				dis[to]=dis[top]+e[i].val;
				if(!vis[to])
				{
					vis[to]=true;
					q.push(to);
				}
			}
		}
	}
}
int main()
{
	m=read();
	for(ri i=1;i<=m;i++)
	{
		char fr;
		char to;
		cin>>fr>>to;
		int val=read();
		e[i].add((int)fr,(int)to,val,e);
		e[i].add((int)to,(int)fr,val,e);
	}
	spfa();
	char ans='A';
	for(char i='B';i<='Y';i++)
	{
		if(dis[(int)i]<dis[(int)ans])
		{
			ans=i;
		}
	}
	cout<<ans<<' '<<dis[(int)ans];
}
