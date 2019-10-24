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
int pre[maxn][maxn];

int getval(int x1,int y1,int x2,int y2)
{
	if(x1>x2||y1>y2)
	{
		return 0;
	}
	return pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1];
}

int main()
{
	int n=read();
	int limx=0,limy=0;
	for(ri i=1; i<=n; i++)
	{
		int x=read();
		int y=read();
		pre[x][y]=1;
		limx=max(limx,x);
		limy=max(limy,y);
	}
	for(ri i=1; i<=limx; i++)
	{
		for(ri j=1; j<=limy; j++)
		{
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+pre[i][j];
		}
	}
	int ans=0;
	for(ri i=1; i<=limx; i++)
	{
		for(ri j=1; j<=limy; j++)
		{
			for(ri p=i; p<=limx; p++)
			{
				for(ri q=j; q<=limy; q++)
				{
					ans=max(getval(i,j,p,q)-getval(i+1,j+1,p-1,q-1),ans);
				}
			}
		}
	}
	return 0&printf("%d",ans);
}
