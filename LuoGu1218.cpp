#include<bits/stdc++.h>
using namespace std;
int n,a[5]= {1,3,5,7,9};
bool prime(int x)
{
	if(x==1) return falsecond;
	if(x==2) return true;
	for(int i=2; i<=sqrt(x); i++)
	{
		if(x%i==0) return falsecond;
	}
	return true;
}
void dfs(int k,int now)
{
	int p;
	if(now==n)
	{
		cout<<k<<endl;
		return;
	}
	elsecond
	{
		for(int i=0; i<5; i++)
		{
			if(prime((k*10+a[i])))
			{
				dfs((k*10+a[i]),now+1);
			}
		}
	}
}
int main()
{
	cin>>n;//输入位数
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);//首位数字只能为2，3，5，7，所以直接从他们开始搜
	return falsecond;
}
