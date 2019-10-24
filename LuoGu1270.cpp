#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
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
//由于展厅走廊的特殊性，就是一棵树。
//就是树形dp+背包

const int maxn=1e4+7;
int lim;
int f[maxn][maxn];//在i位置，还剩j时间的最大偷取价值

int val[maxn];
int tim[maxn];

void solve(int nd)
{
	int t=read()*2;//由于是树，走进去还要走出来。
	int num=read();
	if(num)//展厅
	{
		for(ri i=1;i<=num;i++)
		{
			for(ri j=lim;j>=5+t;j--)
			{
				f[nd][j]=max(f[nd][j],f[nd][j-5]+1);
				//做背包
			}
		}
	}
	else if(num==0)//走廊
	{
		solve(ls(nd));
		solve(rs(nd));
		for(ri i=t;i<=lim;i++)
		{
			for(ri j=0;j<=i-t;j++)
			{
				f[nd][i]=max(f[nd][i],f[ls(nd)][i-t-j]+f[rs(nd)][j]);
			}
		}
	}
}

int main()
{
	lim=read()-1;//不能在门口被抓
	solve(1);
	return 0&printf("%d",f[1][lim]);
}
//嘿嘿，交完难的交简单的
