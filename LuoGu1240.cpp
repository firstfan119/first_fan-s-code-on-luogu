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
int f[maxn][maxn];
int len[maxn];

int main()
{
	int n=read();
	int m=read();
	if(m>2*n-1)
	{
		return 0&printf("0");
	}
	for(ri i=1; i<=n-1; i++)
	{
		len[2*i-1]=len[2*i]=2*i-1;
	}
	len[2*n-1]=2*n-1;
	for(ri i=0; i<=2*n-1; i++)
	{
		f[i][0]=1;
	}
	for(ri i=1; i<=2*n-1; i++)
	{
		for(ri j=1; j<=len[i]; j++)
		{
			f[i][j]=f[i-1][j]+f[i-1][j-1]*(len[i]-j+1);
			f[i][j]%=504;
		}
	}
	return 0&printf("%d",f[2*n-1][m]);
}
