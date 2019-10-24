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

int main()
{
	int n=read();
	int d=read();
	int h=read();
	for(ri i=2; i<=h+1; i++)
	{
		f[i]=i-1;
	}//Á´
	f[h+2]=1;
	for(ri i=2; i<=d-h; i++)
	{
		f[i+h+1]=i+h;
	}
	if(d==1&&n!=2)
	{
		return 0&(int)puts("-1");
	}
	if(d>2*h||d<h||d+1>n)
	{
		return 0&(int)puts("-1");
	}
	for(ri i=d+2; i<=n; i++)
	{
		f[i]=h;
	}
	for(ri i=2; i<=n; i++)
	{
		printf("%d %d\n",i,f[i]);
	}
	return 0;
}
