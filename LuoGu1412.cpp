#include <bits/stdc++.h>
#define ri register int
#define max(x,y) (x>y?x:y)
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

#define db double

const int maxn=20031125;
int ty[maxn];//type
int val[maxn];
int main()
{
	int n=read();
	db k,c;
	{
		scanf("%lf%lf",&k,&c);
	}
	int w=read();
	k=1.0-0.01*k;
	c=1.0+0.01*c;
	db ans=0;
	for(ri i=1;i<=n;i++)
	{
		ty[i]=read();
		val[i]=read();
	}
	for(ri i=n;i>=1;i--)
	{
		if(ty[i]==1)
		{
			ans=max(ans,ans*k+val[i]);
		}
		else
		{
			ans=max(ans,ans*c-val[i]);
		}
	}
	printf("%.2lf",ans*w);
}
