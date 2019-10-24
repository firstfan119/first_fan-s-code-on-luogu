#include <bits/stdc++.h>
using namespace std;
int num[10];
bool vis[10];
bool flag=false;
void print()
{
	for(int i=1; i<=9; i++)
	{
		printf("%d",num[i]);
		if(i%3==0) printf(" ");
	}
	printf("\n");
}
bool check()
{
	if(num[1]>=num[4]||num[4]>=num[7]||num[1]>=num[7]) return false;
	int a=100*num[1]+10*num[2]+num[3];
	int b=100*num[4]+10*num[5]+num[6];
	int c=100*num[7]+10*num[8]+num[9];
	cout<<a<<" "<<b<<" "<<c;
	if(b==2*a&&c==3*a)
	{
		flag=true;
	}
}
void dfs(int digit)
{
	if(digit==10)
	{
		check();
		if(flag=true)
		{
			print();
			flag=false;
		}
		return;
	}
	for(int i=1; i<=9; i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			num[digit]=i;
			dfs(digit+1);
			vis[i]=false;
		}
	}
}
int main()
{
	dfs(1);
}
