#include<bits/stdc++.h>
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

int n,h,res;
struct Jacj
{
	int f;
	int d;
	int t;
	int w;
} e[1125];
int main( )
{
	int n=read();
	int h=read()*12;
	for(ri i=1;i<=n;i++)
	{
		e[i].f=read();
	}
	for(ri i=1;i<=n;i++)
	{
		e[i].d=read();
	}
	for(ri i=1;i<=n-1;i++)
	{
		e[i].t=read();
	}
	
	int ans=0;
	int sum=0;
	int mx=0;
	for(ri j=1; j<=n; j++)
	{
		for(ri i=1; i<=j; i++)
		{
			e[i].w=e[i].f;
		}
		h-=e[j-1].t;
		res=h;
		sum=0;
		while((res--)>0)
		{
			mx=0;
			int pos;
			for(ri i=1; i<=j; i++)
			{
				if(mx<e[i].w)
				{
					pos=i;
					mx=e[i].w;
				}//upd max
			}
			sum+=mx;
			e[pos].w-=e[pos].d;
		}
		ans=max(ans,sum);
	}
	return 0&printf("%d",ans);
}
/*
2
1
10  1
2  5
2
out:
31
*/
