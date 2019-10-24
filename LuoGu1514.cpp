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


//̰�Ĳ��ԣ�
//1.ͬһ��ˮ���ǵ�һ����һ�����������䣨����ˮ�������֤��
//2.�޽��жϣ����һ���������ڵ����������ڴ˵أ������޽⡣
//�ж��޽⣬���������串�ǵ�̰������
//�ж��н⣬�����������ҵ�������ˮ����
const int maxn=1125;
int n,m;
int h[maxn][maxn];
bool f[maxn];//f[i]������i�Ƿ�ɹ��
bool vis[maxn][maxn];

struct segment//�������߶θ���
{
	int l;
	int r;
	friend bool operator<(segment one,segment two)
	{
		return one.l==two.l?one.r<two.r:one.l<two.l;
	}//̰��
}seg[100007],q[100007];


int direx[]={0,0,1,-1,0};
int direy[]={0,-1,0,0,1};
void dfs(int x,int y,int id)//��ǰ�����꣺x,y;������
{
	vis[x][y]=true;
	if(x==n)//�ɺ���
	{
		f[y]=true;//���Թ��
		seg[id].l=min(seg[id].l,y);
		seg[id].r=max(seg[id].r,y);//�����߶ζ˵�
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
	for(ri i=1;i<=m;i++)//�ж����޽�
	{
		unable+=(f[i]==0);
	}
	if(unable)//�޽�
	{
		puts("0");
		return 0&printf("%d\n",unable);
	}
	//�н�
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
