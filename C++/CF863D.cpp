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
int v[maxn];
int t[maxn];
int l[maxn];
int r[maxn];

int main()
{
	int n=read();
	int q=read();
	int m=read();
	for(ri i=1;i<=n;i++)
	{
		v[i]=read();
	}
	for(ri i=1;i<=q;i++)
	{
		t[i]=read();
		l[i]=read();
		r[i]=read();
	}
	while(m--)
	{
		int f=read();
		for(ri i=q;i>=1;i--)
		{
			if(f<l[i]||r[i]<f)
			{
				continue;
			}
			if(t[i]==1)
			{
				f=(f==l[i])?r[i]:(f-1);
			}
			else
			{
				f=l[i]+r[i]-f;
			}
		}
		printf("%d ",v[f]);
	}
	return 0;
}
