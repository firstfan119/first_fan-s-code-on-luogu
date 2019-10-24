/*
#include<bits/stdc++.h>
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
	return flg*num;
}
const int maxn=1e3+7;
long long f[maxn][maxn];
int n,m;
int main()
{
	n=read();
	for(int i=1; i<=n; i++)
	{
		f[i][0]=1;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			f[i][j]=f[i][j-1]+f[i-1][j];
		}
	}
	printf("%lld",f[n][n]);
	//catalan number can also solve this.
}
*/

#include <bits/stdc++.h>
using namespace std;
long long a[]={0,1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452};
int main()
{
	int n;
	cin>>n;
	cout<<a[n];
}//catalan chart.

