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

const int maxn=20031125;
ll f[maxn][5];
int main()
{
	f[0][0]=1;
	for(ri i=1; i<=666; i++)//背包，物品体积i*i
	{
		for(ri j=i*i; j<=32769; j++)
		{
			for(ri k=1; k<=4; k++)
			{
				f[j][k]+=f[j-i*i][k-1];
			}
		}
	}
	int t=read();
	while(t--)
	{
		int num=read();
		printf("%lld\n",f[num][1]+f[num][2]+f[num][3]+f[num][4]);
	}
}
