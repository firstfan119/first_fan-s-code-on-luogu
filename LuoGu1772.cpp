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

const int maxn=2e3+7;
struct edge
{
	int to;
	int nex;
	int val;
} e[maxn];

int cnt=0;
int head[maxn];
void add(int u,int v,int val)
{
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	e[cnt].val=val;
	head[u]=cnt;
}


int n,m;
int dis[maxn];
int vis[maxn];
bool no[maxn];// cannot be used.
void spfa()
{
	fill(dis+1,dis+n+1,20031125);
	fill(vis+1,vis+n+1,0);
	deque<int> q;
	q.push_front(1);
	dis[1]=0;
	vis[1]=true;
	while(q.size())
	{
		int top=q.front();
		q.pop_front();
		vis[top]=false;
		for(ri i=head[top];i;i=e[i].nex)
		{
			int to=e[i].to;
			if(dis[to]>dis[top]+e[i].val&&!no[to])
			{
				dis[to]=dis[top]+e[i].val;
				if(!vis[to])
				{
					vis[to]=true;
					if(q.size()&&dis[to]<dis[q.front()])
					{
						q.push_front(to);
					}
					else
					{
						q.push_back(to);
					}
				}
			}
		}
	}
}

int f[maxn];
bool brk[maxn][maxn];//the i th node break on j
int main()
{
	int day=read();//天数
	n=read();//点数
	int w=read();//修航线花费
	m=read();//路数
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		int val=read();
		add(u,v,val);
		add(v,u,val);
	}
	int information=read();//就用两次，长点无所谓
	for(ri i=1;i<=information;i++)
	{
		int u=read();
		int l=read();
		int r=read();
		for(ri j=l;j<=r;j++)
		{
			brk[j][u]=true;
		}
	}
	fill(f,f+maxn+1,20031125);
	f[0]=-w;
	for(ri i=1;i<=day;i++)
	{
		fill(no+1,no+n+1,0);
		for(ri j=i;j>=1;j--)
		{
			for(ri k=1;k<=n;k++)
			{
				if(brk[j][k])
				{
					no[k]=true;
				}
			}
			spfa();
			int len=dis[n];
			if(len>=20030119)
			{
				break;
			}
			f[i]=min(f[i],f[j-1]+(i-j+1)*len+w);
		}
	}
	return 0&printf("%d",f[day]);
}
/*
  5 5 10 8
  1 2 1
  1 3 3
  1 4 2
  2 3 2
  2 4 4
  3 4 1
  3 5 2
  4 5 2
  4
  2 2 3
  3 1 1
  3 3 3
  4 4 5
out:
32
*/
