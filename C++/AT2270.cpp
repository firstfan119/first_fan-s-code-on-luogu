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

const int maxn=1125;
int a[maxn];

int main()
{
	int n=read();
	int sum=0;
	for(ri i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	int m=read();
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		printf("%d\n",sum+v-a[u]);
	}
}
/*
3
2 1 4
2
1 1
2 3
out:
6
9
*/
