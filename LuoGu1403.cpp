#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}
int main()
{
	int n=read(),i,s=0;
	for(i=1; i<=n; i++) s+=n/i;
	return (printf("%d",s)) & 0;
}
