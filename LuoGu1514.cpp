#include <bits/stdc++.h>
#define ll long long
#define ri register int
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


//贪心策略：
//1.同一流水覆盖的一定是一个完整的区间（利用水流交叉可证）
//2.无解判断：如果一个旱地相邻的三处均低于此地，本题无解。
//判断无解，随后就是区间覆盖的贪心问题
//判断有解，随后就是深搜找到最少蓄水厂数
const int maxn=1125;
int n,m;
int h[maxn][maxn];
bool f[maxn];//f[i]：城市i是否可灌溉
bool vis[maxn][maxn];

struct segment//用来求线段覆盖
{
	int l;
	int r;
	friend bool operator<(segment one,segment two)
	{
		return one.l==two.l?one.r<two.r:one.l<two.l;
	}//贪心
}seg[100007],q[100007];


int direx[]={0,0,1,-1,0};
int direy[]={0,-1,0,0,1};
void dfs(int x,int y,int id)//当前块坐标：x,y;区间编号
{
	vis[x][y]=true;
	if(x==n)//干旱区
	{
		f[y]=true;//可以灌溉
		seg[id].l=min(seg[id].l,y);
		seg[id].r=max(seg[id].r,y);//更新线段端点
	}
	for(ri i=1;i<=4;i++)
	{
		int nx=direx[i]+x;
		int ny=direy[i]+y;
		if(h[x][y]>h[nx][ny]&&!vis[nx][ny]&&nx>=1&&ny>=1&&nx<=n&&ny<=m)
		{
			dfs(nx,ny,id);
		}
	}
}

int main()
{
	n=read();
	m=read();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			h[i][j]=read();
		}
	}
	for(ri i=1;i<=m;i++)
	{
		seg[i].l=20031125;
	}
	for(ri i=1;i<=m;i++)
	{
		if (h[1][i-1]<=h[1][i]&&h[1][i+1]<=h[1][i])
		{
			dfs(1,i,i);
		}
		memset(vis,0,sizeof(vis));
	}
	int unable=0;
	for(ri i=1;i<=m;i++)//判断有无解
	{
		unable+=(f[i]==0);
	}
	if(unable)//无解
	{
		puts("0");
		return 0&printf("%d\n",unable);
	}
	//有解
	puts("1");
	int top=0;
	for(ri i=1;i<=m;i++)
	{
		if(seg[i].l!=20031125&&seg[i].r!=0)
		{
			q[++top].l=seg[i].l;
			q[top].r=seg[i].r;
		}
	}
	int cur=1;
	int ans=0;
	int it=1;
	while(cur<=m)
	{
		int _new=0;
		while(q[it].l<=cur)
		{
			_new=max(_new,q[it].r);
			it++;
		}
		cur=_new+1;
		ans++;
	}
	return 0&printf("%d",ans);
}
