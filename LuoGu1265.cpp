#include<bits/stdc++.h>
#define ll long long
#define ri register int
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

const int maxn=1e4+5;
int n,pos;
bool vis[maxn];
db ans=0;
db mn=20031125;
db dis[maxn];
struct node
{
	int x;
	int y;
} nd[maxn];

db calc(int one,int two)
{
	return sqrt(1.0*(nd[one].x-nd[two].x)*(nd[one].x-nd[two].x)+1.0*(nd[one].y-nd[two].y)*(nd[one].y-nd[two].y));
}

int main()
{
	n=read();
	fill(dis+2,dis+n+1,20031125);
	for(ri i=1; i<=n; i++)
	{
		nd[i].x=read();
		nd[i].y=read();
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			if(!vis[j]&&dis[j]<mn)
			{
				mn=dis[j];
				pos=j;
			}
		}
		ans+=mn;
		vis[pos]=true;
		mn=20031125;
		for(ri j=1; j<=n; j++)
		{
			dis[j]=min(dis[j],calc(pos,j));
		}
	}
	return 0&(int)printf("%.2lf",ans);
}
