#include <bits/stdc++.h>
using namespace std;
#define ri register int
int pile;
const int maxn=105;
int card[maxn];
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=num*10+c-48;
		c=getchar();
	}
	return num;
}
int main()
{
	pile=read();
	int cnt=0;
	int aver=0;
	for(ri i=1;i<=pile;i++)
	{
		card[i]=read();
		aver+=card[i];
	}
	aver/=pile;
	int cha[maxn];
	for(ri i=1;i<=pile;i++)
	{
		cha[i]=card[i]-aver;
	}
	for(ri i=1;i<=pile;i++)
	{
		if(cha[i])
		{
			cha[i+1]+=cha[i];
			cnt++;
		}
	}
	cout<<cnt;
}
