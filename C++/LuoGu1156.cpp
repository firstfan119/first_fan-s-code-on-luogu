#include <bits/stdc++.h>
using namespace std;
int tranum,sthet,dp[110][1010][110];
//  ������Ŀ����λ�ã���ʺ����
struct trash
{
	int apr,lif,het;
	//appear time,life value,height value;
} rub[110];
//trash=rubbish
int appearance(trash &x,trash &y)
{
	return x.apr<y.apr;
}//˭�ȳ��־���˭
int dfs(int tranow,int time_left,int now_het)
//ʹ���˼������������ܻ��ã��������˶��
{
	if (tranow>tranum||time_left<rub[tranow].apr) return 19260817;
	//1)�����������ˣ�ʧ��;2)ʱ��Ȳ�����һ��������
	if (now_het+rub[tranow].het>=sthet)
	{
		return rub[tranow].apr;
		//ţ�ɹ����������һ��������ȥ��������ʱ��
	}
	if (dp[tranow][time_left][now_het])
	{
		return dp[tranow][time_left][now_het];
	}
	dp[tranow][time_left][now_het]=min( dfs(tranow+1,time_left+rub[tranow].lif,now_het) , dfs(tranow+1,time_left,now_het+rub[tranow].het));
	//״̬ת�ƣ������������������������߶�
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
	//����������˳������
	if (dfs(1,10,0)!=19260817)
	{
		printf("%d\n",dp[1][10][0]);
	}
	else
	{
		int res=10;
		for (int i=1; i<=tranum; ++i)
			//�鿴��û���������ܾ������
		{
			if (res<rub[i].apr)
			{
				break;
				//��ʺ��ɱ
			}
			else
			{
				res+=rub[i].lif;
				//�ȴ���ʺ��ɱ
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
