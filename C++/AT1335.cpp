#include<bits/stdc++.h>
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
	int a=read();
	int b=read();
	int c=read();
	int k=read();
	int s=read();
	int d=read();
	return 0&printf("%d\n",(s+d)>=k?((a-c)*s+(b-c)*d):(a*s+b*d));
}
