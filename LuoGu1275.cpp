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

const int maxn=125;
int st[maxn][maxn];
int ed[maxn][maxn];
int cur[maxn][maxn];
bool checked[maxn];
int main()
{
	int T=read();
	while(T--)
	{
		bool success=false;
		int n=read();
		int m=read();
		for(ri i=1; i<=n; i++)
		{
			for(ri j=1; j<=m; j++)
			{
				st[i][j]=read();
			}
		}
		for(ri i=1; i<=n; i++)
		{
			for(ri j=1; j<=m; j++)
			{
				ed[i][j]=read();
			}
		}
		for(ri it=1; it<=m; it++)//枚举列数
		{
			memset(checked,0,sizeof(checked));
			for(ri i=1; i<=n; i++)
			{
				for(ri j=1; j<=m; j++)
				{
					cur[i][j]=st[i][j];
				}
			}//初始化

			for(ri i=1; i<=n; i++)
			{
				if(cur[i][it]!=ed[i][1])
					//比较当前这列和目标状态的第一列的同行的数;
					//如果不相同,把初始行翻转
				{
					for(ri j=1; j<=m; j++)
					{
						cur[i][j]^=1;
					}//该行翻转
				}
			}

			checked[1]=true;
			int num=1;
			//接下来检查对应
			for(ri i=1; i<=m; i++)
			{
				if(i!=it)
				{
					for(ri j=2; j<=m; j++)
					{
						if(!checked[j])
						{
							for(ri k=1; k<=n; k++)
							{
								if(ed[k][j]!=cur[k][i])
								{
									goto qwq;
								}//不符，跳
							}
							checked[j]=true;
							num++;
						}
qwq:
						;
					}
				}
			}
			if(num==m)
			{
				cout<<"YES"<<endl;
				success=true;
				break;
			}
		}
		if(!success)
		{
			cout<<"NO"<<endl;
		}
	}
}
