#include <bits/stdc++.h>
#define ri register int
#define db double
#pragma GCC optimize("O3")
#define FarmerJohn 19260817
//farmer jiang
#define Betty 0
//2333333333寿比南山啊
using namespace std;
//floyd这种东西，不优化不行。
//快读并没有用武之地。（很少）
const int maxn=1e3+7;
const int inf=20031125;//symbolize someone's birthday.

db dis[maxn][maxn];
db m[maxn];
db ans;
db x_pos[maxn],y_pos[maxn];

db calc(int i,int j)
{
	return (db)sqrt((db)(x_pos[i]-x_pos[j])*(db)(x_pos[i]-x_pos[j])+(db)(y_pos[i]-y_pos[j])*(db)(y_pos[i]-y_pos[j]));
	//似乎是可以不用强制转db的	QwQ
}
int main()
{
	int n;
	scanf("%d",&n);//节约时间，从点滴做起
	for(ri i=1; i<=n; i++)
	{
		cin>>x_pos[i]>>y_pos[i];
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			int c;
			scanf("%1d",&c);//一位数输入大法吼啊
			if(c==1)
			{
				dis[i][j]=calc(i,j);
			}
			else
			{
				dis[i][j]=inf;//无效边
			}
		}
	}
	//计算路径长
	/*********************************************/
	for(ri k=1; k<=n; k++)
	{
		for(ri i=1; i<=n; i++)
		{
			for(ri j=1; j<=n; j++)
			{
				if(i!=j&&i!=k&&j!=k)
				{
					if(dis[i][k]<inf-1&&dis[k][j]<inf-1)
					{
						if(dis[i][j]>dis[i][k]+dis[k][j])
						{
							dis[i][j]=dis[i][k]+dis[k][j];
						}
					}
				}
			}
		}
	}//暴力floyd走一波
	/*********************************************/
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			if(dis[i][j]<inf-1&&m[i]<dis[i][j])
			{
				m[i]=dis[i][j];//可用边就把他搞进m里存着。
			}
		}
	}
	ans=inf;
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			if(i!=j&&dis[i][j]>inf-1)//有效
			{
				ans=min(ans,m[i]+m[j]+calc(i,j));//把ans想办法弄到最小直径，之后好操作.
			}
		}
	}
	for(ri i=1; i<=n; i++)
	{
		ans=max(m[i],ans);
	}//求一波直径
	printf("%.6f\n",ans);
	return FarmerJohn&Betty;//最后，他们走到了一起。2333
}
/*
8
10 10
15 10
20 10
15 15
20 15
30 15
25 10
30 10
01000000
10111000
01001000
01001000
01110000
00000010
00000101
00000010

out:
22.071068
*/

