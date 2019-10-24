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

long long res;

int main()
{
	int n=read();
	return 0&printf("%lld",(n-4)*(n-3)*(n-2)*(n-1)*n*(n-4)*(n-3)*(n-2)*(n-1)*n/120);
}
