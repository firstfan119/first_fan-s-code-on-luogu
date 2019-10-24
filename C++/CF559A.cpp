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
	int a1=read();
	int a2=read();
	int a3=read();
	int a4=read();
	int a5=read();
	int a6=read();
	return 0&printf("%d",(a1+a2+a3)*(a1+a2+a3)-a1*a1-a3*a3-a5*a5);
}
