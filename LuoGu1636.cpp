#include <bits/stdc++.h>
#define ri register int
using namespace std;
int read()
{
	int num=0;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		num=10*num+c-48;
		c=getchar();
	}
	return num;
}
int cd[2003];//out lines
//non_direction,so also in lines
int m,n;
int cnt=0;
int main()
{
	n=read();
	m=read();
	for(ri i=1;i<=2*m;i++)//fascinating operation
	{
		cd[read()]++;
	}
	for(ri i=1;i<=n;i++)
	{
		if(cd[i]%2==1)
		{
			cnt++;
		}
	}
	if(cnt>0)
	{
		cout<<ceil(cnt/2.0);
	}
	else
	{
		return printf("1")&0;
	}
}
