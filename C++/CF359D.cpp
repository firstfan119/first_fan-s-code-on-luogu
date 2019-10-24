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

int n;
int v[maxn];
int len;
int tot;
int ans[maxn];
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		v[i]=read();
	}
	for(ri i=1; i<=n; i++)
	{
		int l=i,r=i;
		while(l>=1&&v[l]%v[i]==0)
		{
			l--;
		}
		l++;
		while(r<=n&&v[r]%v[i]==0)
		{
			r++;
		}
		r--;
		if (r-l>len)
		{
			len=r-l;
			tot=1;
			ans[tot]=l;
		}
		else if(r-l==len)
		{
			ans[++tot]=l;
		}
		i=r;
	}
	printf("%d %d\n",tot,len);
	for(ri i=1; i<=tot; i++)
	{
		printf("%d ",ans[i]);
	}
}

