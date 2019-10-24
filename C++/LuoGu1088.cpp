#include<bits/stdc++.h>
#define ri register int
using namespace std;
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
int main()
{
	int n=read();
	int m=read();
	int arr[n+1];
	for(ri i=1; i<=n; i++)
	{
		arr[i]=read();
	}
	for(ri i=1; i<=m; i++)
	{
		next_permutation(arr+1,arr+1+n);//这个一定要自己会写!（而且非暴力！）
	}
	cout<<arr[1];
	for(ri i=2; i<=n; i++)
	{
		cout<<' '<<arr[i];
	}
}
