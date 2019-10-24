//double exp
#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int maxn=20031125;

char c[4][maxn];

int len[4];

int nex[4][maxn];

//KMP模式串匹配模板
void next(int id)
{
	int k=-1;
	nex[id][0]=-1;
	int j=0;
	while(j<len[id])
	{
		if(k==-1||c[id][k]==c[id][j])
		{
			k++;
			j++;
			nex[id][j]=k;
		}
		else
		{
			k=nex[id][k];
		}
	}
}

int kmp(int x,int y)
{
	int k=0;
	int j=0;
	while(j<len[y]&&k<len[x])
	{
		if(j==-1||c[x][k]==c[y][j])
		{
			j++;
			k++;
		}
		else
		{
			j=nex[y][j];
		}
	}
	return j;
}

int main()
{
	for(ri i=1;i<=3;i++)
	{
		scanf("%s",c[i]);
	}
	for(ri i=1;i<=3;i++)
	{
		len[i]=strlen(c[i]);
		next(i);
	}
	int ans=-20031125;
	//疯狂排列组合
	for(ri i=1;i<=3;i++)
	{
		for(ri j=1;j<=3;j++)
		{
			if(i==j)
			{
				continue;
			}
			for(ri k=1;k<=3;k++)
			{
				if(k==i||k==j)
				{
					continue;
				}
				int Len=kmp(i,j);//变量
				int LEN=Len;//存一个离线量
				if(len[j]==LEN)
				{
					Len+=kmp(i,k);
				}
				else
				{
					Len+=kmp(j,k);
				}
				ans=max(ans,Len);
			}
		}
	}
 return 0&printf("%d",len[1]+len[2]+len[3]-ans);
}
