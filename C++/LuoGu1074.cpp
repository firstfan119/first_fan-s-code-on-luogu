#include <bits/stdc++.h>
#define ri register int
#pragma GCC optimize("O3")
#define ll long long
using namespace std;

inline int read()
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

const int ff[10][10]=
{
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6}
};

int v[25][25];
int ans=0;

inline int id(int x,int y)
{
	return (x-1)/3*3+(y+2)/3;
}//所在块

/*
int calc(int x,int y)
{
	return 10-max(abs(x-5),abs(y-5));
}//所在位分值
*/

bool r[10][10];//row
bool c[10][10];//column
bool b[10][10];//block

bool success=0;

inline void dfs(int cur)
{
	int mn=20031125;

	int nx=0;
	int ny=0;

	int cnt=0;
	int best=0;
	for(ri i=1; i<=9; i++)
	{
		for(ri j=1; j<=9; j++)
		{
			if(!v[i][j])
			{
				cnt=0;
				int upper=0;
				for(ri k=1; k<=9; k++)
				{
					if(r[i][k]&&c[j][k]&&b[id(i,j)][k])
					{
						cnt++;
						upper=k;//不断找最高
					}
				}
				best+=upper*ff[i][j];//乐观计算
				if(cnt<mn)
				{
					mn=cnt;
					nx=i;
					ny=j;
				}
			}
		}
	}
	if(best+cur<=ans)
	{
		return ;
	}//最优性剪枝
	if(best==0)
	{
		success=true;
		ans=max(ans,cur);
		return ;
	}//放满了，成功
	if(cnt==0)
	{
		return ;
	}//找不到合法情况，失败

	int blk=id(nx,ny);
	int val=ff[nx][ny];

	for(ri i=1; i<=9; i++)
	{
		if(r[nx][i]&&c[ny][i]&&b[blk][i])
		{
			r[nx][i]=false;
			c[ny][i]=false;
			b[blk][i]=false;
			v[nx][ny]=i;
			dfs(cur+i*val);
			v[nx][ny]=0;
			r[nx][i]=true;
			c[ny][i]=true;
			b[blk][i]=true;
		}
	}
}

int main()
{
	for(ri i=1; i<=9; i++)
	{
		for(ri j=1; j<=9; j++)
		{
			v[i][j]=read();
			ans+=v[i][j]*ff[i][j];
			r[i][j]=c[i][j]=b[i][j]=true;
		}
	}
	for(ri i=1; i<=9; i++)
	{
		for(ri j=1; j<=9; j++)
		{
			if(v[i][j])
			{
				if(r[i][v[i][j]]&&c[j][v[i][j]]&&b[id(i,j)][v[i][j]])
				{
					r[i][v[i][j]]=false;
					c[j][v[i][j]]=false;
					b[id(i,j)][v[i][j]]=false;
				}
				else
				{
					return 0&(int)puts("-1");
				}
			}
		}
	}
	dfs(ans);
	if(success)
	{
		printf("%d",ans);
	}
	else
	{
		return 0&(int)puts("-1");
	}
	return 0;
}
