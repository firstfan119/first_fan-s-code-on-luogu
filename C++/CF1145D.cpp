#include<bits/stdc++.h>
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
int main ()
{
	int n=read();
	int m;
	int mn=20031125;
	for(ri i=1; i<=n; i++)
	{
		if(i==3)
		{
			m=read();
			mn=min(mn,m);
			continue;
		}
		mn=min(mn,read());
	}
	return 0&printf("%d",(mn^m)+2);
}
