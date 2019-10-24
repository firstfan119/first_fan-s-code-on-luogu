#include <bits/stdc++.h>
#define ri register int
#define ll long long;
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

int k[] = {15,14,12,13,8,9,10,11,0,1,2,3,4,5,6,7};
int main()
{
	return 0&printf("%d", k[read()]);
}
