//��Ĳ��鼯�������ô��ˡ�
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

const int maxn=1125;
int f[maxn];
int find(int x)
{
	return f[x]==x?x:(f[x]=find(f[x]));
}

bool enm[maxn][maxn];//�����Һ�����С

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=n; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		char opt;
		cin>>opt;
		int u=read();
		int v=read();
		int fu=find(u);
		int fv=find(v);
		switch(opt)
		{
			case 'F':
			{
				f[fu]=fv;
				break;
			}//friends
			case 'E':
			{
				enm[u][v]=enm[v][u]=true;
				for(ri j=1;j<=n;j++)//�е㱩��
				{
					if(enm[u][j])
					{
						f[find(j)]=fv;
					}
					if(enm[v][j])
					{
						f[find(j)]=fu;
					}
				}
				break;
			}
		}
	}
	int cnt=0;
	for(ri i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			cnt++;
		}
	}
	return 0&printf("%d",cnt);
}
