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

const int maxn=1e6+7;
int val[maxn];
int main()
{
	int n=read();
	int state=0;
	for(ri i=1; i<=n; i++)
	{
		val[i]=read();
		state^=val[i];
	}
	if(!state)
	{
		return 0&(int)puts("lose");
	}
	for(ri i=1; i<=n; i++)
	{
		if((val[i]^state)<val[i])
		{
			printf("%d %d\n",(val[i]-(val[i]^state)),i);
			val[i]=val[i]^state;
			break;
		}
	}
	for(ri i=1; i<=n; i++)
	{
		printf("%d ",val[i]);
	}
}
/*
3
3 6 9
out:
4 3
3 6 5
*/
