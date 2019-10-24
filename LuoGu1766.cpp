#include <bits/stdc++.h>
#define ri register int
#define ll long long
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

const int maxn=1e6+7;

struct point
{
	int x;
	int y;
};

struct edge
{
	point u;
	point v;
	db slp;//slope;
	db itc;//Intercept
} e[maxn];

int main()
{
	int n=read();
	int cur=read();
	for(ri i=1; i<=n; i++)
	{
		e[i].u.x=read();
		e[i].u.y=read();
		e[i].v.x=read();
		e[i].v.y=read();
		//ÎÒ ÊÇ ¶¾ Áö
		e[i].slp=1.0*(e[i].v.y-e[i].u.y)/(e[i].v.x-e[i].u.x);
		e[i].itc=e[i].u.y-e[i].u.x*e[i].slp;
	}
	int h=20031125;
	while(1)
	{
		int flg=0;
		int mx=-20031125;
		for(ri i=1; i<=n; i++)
		{
			int l=min(e[i].u.x,e[i].v.x);
			int r=max(e[i].u.x,e[i].v.x);
			if(cur<r&&cur>l)
			{
				db ls=1.0*cur*e[i].slp+e[i].itc;
				if(ls>h)
				{
					continue;
				}
				if(mx<ls)
				{
					mx=ls;
					flg=i;
				}
			}
		}
		if(!flg)
		{
			return 0&printf("%d",cur);
		}
		if(e[flg].u.y<e[flg].v.y)
		{
			cur=e[flg].u.x;
		}
		else
		{
			cur=e[flg].v.x;
		}
		h=min(1.0*e[flg].u.y,1.0*e[flg].v.y);
	}
}
