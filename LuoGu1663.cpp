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

const int maxn=5e5+5;
struct point
{
	int x,y;
} pt[maxn];

struct linene
{
	db slope,inter;
	void add(point a,point c)
	{
		slope=1.0*(c.y-a.y)/(c.x-a.x);
		inter=a.y-slope*a.x;
	}
} line[maxn];
int n;
bool check(db x)
{
	db l=0,r=1e9;
	for(ri i=1; i<n; i++)
	{
		if(line[i].slope==0)
		{
			if(line[i].inter>x) return 0;
			else continue;
		}
			
		db tmp=(x-line[i].inter)/line[i].slope;
		if(line[i].slope>0) r=min(r,tmp);
		else l=max(l,tmp);
	}
	return l<=r;
}
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		pt[i].x=read();
		pt[i].y=read();
		if(i>=2)
		{
			line[i].add(pt[i],pt[i-1]);
		}
	}
	db  l=0,r=1000000;
	db mid;
	db ans;
	int t=66;
	while(t--)
	{
		mid=(l+r)/2.0;
		if(check(mid))
		{
			ans=mid;
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	return 0&printf("%lf",ans);
}
