#include <bits/stdc++.h>
#define ri register int
#define db double
#pragma GCC optimize("O3")
#define FarmerJohn 19260817
//farmer jiang
#define Betty 0
//2333333333�ٱ���ɽ��
using namespace std;
//floyd���ֶ��������Ż����С�
//�����û������֮�ء������٣�
const int maxn=1e3+7;
const int inf=20031125;//symbolize someone's birthday.

db dis[maxn][maxn];
db m[maxn];
db ans;
db x_pos[maxn],y_pos[maxn];

db calc(int i,int j)
{
	return (db)sqrt((db)(x_pos[i]-x_pos[j])*(db)(x_pos[i]-x_pos[j])+(db)(y_pos[i]-y_pos[j])*(db)(y_pos[i]-y_pos[j]));
	//�ƺ��ǿ��Բ���ǿ��תdb��	QwQ
}
int main()
{
	int n;
	scanf("%d",&n);//��Լʱ�䣬�ӵ������
	for(ri i=1; i<=n; i++)
	{
		cin>>x_pos[i]>>y_pos[i];
	}
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			int c;
			scanf("%1d",&c);//һλ������󷨺�
			if(c==1)
			{
				dis[i][j]=calc(i,j);
			}
			else
			{
				dis[i][j]=inf;//��Ч��
			}
		}
	}
	//����·����
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
	}//����floyd��һ��
	/*********************************************/
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			if(dis[i][j]<inf-1&&m[i]<dis[i][j])
			{
				m[i]=dis[i][j];//���ñ߾Ͱ������m����š�
			}
		}
	}
	ans=inf;
	for(ri i=1; i<=n; i++)
	{
		for(ri j=1; j<=n; j++)
		{
			if(i!=j&&dis[i][j]>inf-1)//��Ч
			{
				ans=min(ans,m[i]+m[j]+calc(i,j));//��ans��취Ū����Сֱ����֮��ò���.
			}
		}
	}
	for(ri i=1; i<=n; i++)
	{
		ans=max(m[i],ans);
	}//��һ��ֱ��
	printf("%.6f\n",ans);
	return FarmerJohn&Betty;//��������ߵ���һ��2333
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

