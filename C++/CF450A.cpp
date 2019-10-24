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

int main()
{
	int n=read();
	int m=read();
	int cur=0;
	int res=0;
	for(ri i=1;i<=n;i++)
	{
		int need=read();
		int tmp=(need/m)+((need%m)>0);
		if(tmp>=cur)
		{
			cur=tmp;
			res=i;
		}
	}
	return 0&printf("%d",res);
}
