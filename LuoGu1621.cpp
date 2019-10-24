//就套个素数筛法也能是绿？
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

const int maxn=1e6+7;
int f[maxn];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

//接下来是无赖 5/6筛
int l,r;
bool ispri[maxn];

int init()
{
	memset(ispri,1,sizeof(ispri));
	int k=sqrt(r);
	ispri[0]=ispri[1]=0;
	for(ri i=2; i<=k; i++)
	{
		if(ispri[i])
		{
			for(ri j=2*i; j<maxn; j+=i)
			{
				ispri[j]=0;
			}
		}
	}
}

int top=0;
int pri[maxn];

int main()
{
	l=read();
	r=read();
	init();
	int lim=read();
	for(ri i=l; i<=r; i++)
	{
		f[i]=i;
	}
	for(ri i=lim; i<=r; i++)
	{
		if(ispri[i])
		{
			pri[++top]=i;
		}
	}
	for(ri i=1; i<=top; i++)
	{
		int num=0;
		while(num*pri[i]<l)
		{
			num++;
		}
		while((num+1)*pri[i]<=r)
		{
			int fu=find(pri[i]*num);
			int fv=find(pri[i]*(num+1));
			if(fu!=fv)
			{
				f[fv]=fu;
			}
			num++;
		}
	}
	int cnt=0;
	for(ri i=l; i<=r; i++)
	{
		if(f[i]==i)
		{
			cnt++;
		}
	}
	return 0&printf("%d",cnt);
}
