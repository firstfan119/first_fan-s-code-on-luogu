#include <bits/stdc++.h>
#define ll long long
#define ri register int
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
int ans=9;
int f()
{
	while(n>=10)
	{
		n++;
		while(n%10==0)
		{
			n/=10;
		}
		ans++;
	}//f
	return ans;
}

int main()
{
	n=read();
	return 0&printf("%d",f());
}
