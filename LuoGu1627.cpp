#include<bits/stdc++.h>
#define ri register int
#define ll long long
#pragma GCC optimize("O3")
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
int val[maxn];
int pre[maxn];
int pos;
int main()
{
	int n=read();
	int tar=read();
	for(ri i=1; i<=n; i++)
	{
		val[i]=read();
		if(val[i]==tar)
		{
			val[i]=0;
			pos=i;
			continue;
		}
		if(val[i]>tar)
		{
			val[i]=1;
		}
		else
		{
			val[i]=-1;
		}
	}
	for(ri i=1; i<=n; i++)
	{
		pre[i]=pre[i-1]+val[i];
	}
	int ans=0;
	int l;
	for(ri i=1; i<=pos; i++)
	{
		if((pos-i)%2==1)
		{
			l=pos+1;
		}
		else
		{
			l=pos;
		}
		for(ri j=l; j<=n; j+=2)
		{
			if(pre[j]==pre[i-1])
			{
				ans++;
			}
		}
	}
	return 0&printf("%d",ans);
}
/*
7 4
5 7 2 4 3 1 6
out:
4
*/
