#include <bits/stdc++.h>
#define ri register int
#define db double
using namespace std;
const int maxn=2003;
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
int vis[maxn],head[maxn];
int n,m;
db dis[maxn];

struct edge
{
    int nex;
	int to;
    db val;
}e[maxn];

struct node
{
 db x;
 db y;
}_n[maxn];

db calc(int u,int v)
{
    return sqrt((db)(_n[u].x-_n[v].x)*(_n[u].x-_n[v].x)+(_n[u].y-_n[v].y)*(_n[u].y-_n[v].y));
}

int cnt=0;
void add(int u,int v)
{
	db val=calc(u,v);
    e[++cnt].nex=head[u];
    e[cnt].val=val;
    e[cnt].to=v;
    head[u]=cnt;

	e[++cnt].nex=head[v];
    e[cnt].val=val;
    e[cnt].to=u;
    head[v]=cnt;
}

int st;
int ed;
int spfa()
{
	st=read();
	ed=read();
    queue<int> q;
    for(ri i=1;i<=n;i++)
    {
        vis[i]=false;
        dis[i]=20031125.0;
    }
    q.push(st);
    vis[st]=true;
    dis[st]=false;
    while (!q.empty())
    {
        int top=q.front();
        q.pop();
        vis[top]=false;
        for(ri i=head[top];i;i=e[i].nex)
        {
            int to=e[i].to;
            if (dis[to]>dis[top]+e[i].val)
            {
                dis[to]=dis[top]+e[i].val;
                if (!vis[to])
                {
                    vis[to]=true;
                    q.push(to);
                }
            }
        }
    }
    bool success=true;
    return success;
}

int main()
{
	n=read();
    for(ri i=1;i<=n;i++)
    {
		_n[i].x=read();
		_n[i].y=read();
	}
	m=read();
    for(ri i=1;i<=m;i++)
    {
    	add(read(),read());
    }
	spfa();
	printf("%.2lf\n",dis[ed]);
    return 0;
    //nmd居然还有负坐标！！！
}
