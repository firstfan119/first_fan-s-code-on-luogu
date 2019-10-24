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

int f[125];
int main()
{
	int n=read();
	f[0]=1;
	f[1]=1;
	for(ri i=2;i<=n;i++)
	{
		for(ri j=0;j<i;j++)
		{
			f[i]+=f[j]*f[i-j-1];
		}
	}
	return 0&printf("%d",f[n]);
}
