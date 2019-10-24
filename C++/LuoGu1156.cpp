#include <bits/stdc++.h>
using namespace std;
int tranum,sthet,dp[110][1010][110];
//  垃圾数目，起步位置，吔屎方案
struct trash
{
	int apr,lif,het;
	//appear time,life value,height value;
} rub[110];
//trash=rubbish
int appearance(trash &x,trash &y)
{
	return x.apr<y.apr;
}//谁先出现就找谁
int dfs(int tranow,int time_left,int now_het)
//使用了几个垃圾，还能活多久，现在累了多高
{
	if (tranow>tranum||time_left<rub[tranow].apr) return 19260817;
	//1)垃圾都用完了，失败;2)时间等不到下一个垃圾了
	if (now_het+rub[tranow].het>=sthet)
	{
		return rub[tranow].apr;
		//牛成功，返回最后一个被丢进去的垃圾的时间
	}
	if (dp[tranow][time_left][now_het])
	{
		return dp[tranow][time_left][now_het];
	}
	dp[tranow][time_left][now_het]=min( dfs(tranow+1,time_left+rub[tranow].lif,now_het) , dfs(tranow+1,time_left,now_het+rub[tranow].het));
	//状态转移：吃了它长生命，不吃它长高度
	return dp[tranow][time_left][now_het];
}
int main()
{
	scanf("%d%d",&sthet,&tranum);
	for (int i=1; i<=tranum; ++i)
	{
		scanf("%d%d%d",&rub[i].apr,&rub[i].lif,&rub[i].het);
	}
	sort(rub+1,rub+tranum+1,appearance);
	//按垃圾出现顺序排列
	if (dfs(1,10,0)!=19260817)
	{
		printf("%d\n",dp[1][10][0]);
	}
	else
	{
		int res=10;
		for (int i=1; i<=tranum; ++i)
			//查看有没有垃圾，能救他多久
		{
			if (res<rub[i].apr)
			{
				break;
				//吔屎自杀
			}
			else
			{
				res+=rub[i].lif;
				//等待吔屎自杀
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
