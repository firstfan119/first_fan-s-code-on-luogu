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

int n;

void dfs(const int &l1,const int &l2,const int &r1,const int &r2)
{
	if(l2>n||r2>n)
	{
		return ;
	}
	dfs(l1,l2,l1+r1,l2+r2);
	if(l2+r2<=n)
	{
		printf("%d/%d\n",l1+r1,l2+r2);
	}
	dfs(l1+r1,l2+r2,r1,r2);
}

int main()
{
	n=read();
	printf("0/1\n");
	dfs(0,1,1,1);
	printf("1/1\n");
}
