#include <bits/stdc++.h>
#define ri register int
#define db double
using namespace std;
const int maxn=1e3+5;
db ans=20031125.0;
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
	while(c<='9'&&c>='0')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
struct air_port
{
	int id;
	int x,y;
};
struct city
{
	air_port apt[5];//airport
	int fw;//freeway
}ct[maxn];
int quest;

int n,t,fr,to;

int cnt=0;

db dis[maxn][maxn];

db calc(air_port a,air_port b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
db len[5][5];//勾股♂求边
void _4th(city& ci)//find the 4th airport.
{
	len[1][2]=calc(ci.apt[1],ci.apt[2]);
	len[1][3]=calc(ci.apt[1],ci.apt[3]);
	len[2][3]=calc(ci.apt[2],ci.apt[3]);

	if(len[1][2]>len[1][3]&&len[1][2]>len[2][3])
	{
		ci.apt[4].x=ci.apt[1].x+ci.apt[2].x-ci.apt[3].x;
		ci.apt[4].y=ci.apt[1].y+ci.apt[2].y-ci.apt[3].y;
		return;
	}
	if(len[1][3]>len[1][2]&&len[1][3]>len[2][3])
	{
		ci.apt[4].x=ci.apt[1].x+ci.apt[3].x-ci.apt[2].x;
		ci.apt[4].y=ci.apt[1].y+ci.apt[3].y-ci.apt[2].y;
		return;
	}
	ci.apt[4].x=ci.apt[3].x+ci.apt[2].x-ci.apt[1].x;
	ci.apt[4].y=ci.apt[3].y+ci.apt[2].y-ci.apt[1].y;
	return;
}
void init()
{
	memset(dis,20031125/20030119,sizeof(dis));
	n=read();
	t=read();
	fr=read();
	to=read();
	for(ri i=1; i<=n; i++)
	{
		for(int j=1; j<=3; j++)
		{
			ct[i].apt[j].x=read();
			ct[i].apt[j].y=read();
		}
		ct[i].fw=read();
		_4th(ct[i]);
		for(ri j=1; j<=4; j++)
		{
			ct[i].apt[j].id=++cnt;
		}
	}
}
void self_connect()
{
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=4; j++)
		{
			air_port now1=ct[i].apt[j];
			for(ri k=j+1; k<=4; k++)
			{
				air_port now2=ct[i].apt[k];
				dis[now1.id][now2.id]=1.0*calc(now1,now2)*(db)ct[i].fw;
				dis[now2.id][now1.id]=dis[now1.id][now2.id];
			}
			for(ri k=i+1; k<=n; k++)
			{
				for(ri l=1; l<=4; l++)
				{
					air_port now2=ct[k].apt[l];
					dis[now1.id][now2.id]=1.0*calc(now1,now2)*(db)t;
					dis[now2.id][now1.id]=dis[now1.id][now2.id];
				}
			}
		}
	}
}
void floyd()
{
	for(ri k=1; k<=cnt; k++)
	{
		for(ri i=1; i<=cnt; i++)
		{
			for(ri j=1; j<=cnt; j++)
			{
				if(i!=j)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
}
db solve()
{
	init();
	self_connect();
	//城市内连线
	floyd();
	for(ri i=1; i<=4; i++)
	{
		for(ri j=1; j<=4; j++)
		{
			ans=min(ans,dis[ct[fr].apt[i].id][ct[to].apt[j].id]);
		}
	}
	return ans;
}
int main()
{
	quest=read();
	while(quest--)
	{
		printf("%.1f\n",solve());
	}
	return 0;
}
