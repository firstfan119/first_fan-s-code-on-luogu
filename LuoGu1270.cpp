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
//����չ�����ȵ������ԣ�����һ������
//��������dp+����

const int maxn=1e4+7;
int lim;
int f[maxn][maxn];//��iλ�ã���ʣjʱ������͵ȡ��ֵ

int val[maxn];
int tim[maxn];

void solve(int nd)
{
	int t=read()*2;//�����������߽�ȥ��Ҫ�߳�����
	int num=read();
	if(num)//չ��
	{
		for(ri i=1;i<=num;i++)
		{
			for(ri j=lim;j>=5+t;j--)
			{
				f[nd][j]=max(f[nd][j],f[nd][j-5]+1);
				//������
			}
		}
	}
	else if(num==0)//����
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
	lim=read()-1;//�������ſڱ�ץ
	solve(1);
	return 0&printf("%d",f[1][lim]);
}
//�ٺ٣������ѵĽ��򵥵�
