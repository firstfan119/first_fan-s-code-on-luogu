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

int v1[101];
int v2[101];
int f[101][101];
int main()
{
	srand((time)(0));
	int n=read();
	int m=read();
	for(int i=1; i<=n; i++)
	{
		v1[i]=read();
		v2[i]=read();
	}
	
	int l=1;
	int r=20000;
	//binary
	while(l<=r)
	{
		int mid=(l+r)>>1;
		for(ri i=0;i<=n;i++)
		{
			for(ri j=0;j<=m;j++)
			{
				f[i][j]=-0x7fffffff;
			}
		}//暴力
		f[0][0]=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<=m; j++)
			{
				for(int k=0; k<=mid/v1[i]&&k<=j; k++)
				{
					f[i][j]=max(f[i-1][j-k]+((mid-(v1[i]*k))/v2[i]),f[i][j]);
				}
			}
		}//dp检验
		if(f[n][m]>=m)
		{
			r=mid-rand()%2;
			srand(rand());
		}
		else
		{
			l=mid+rand()%2;
			srand(rand());
		}//永远用不来二分的我
	}
	return 0&printf("%d",l);
}
