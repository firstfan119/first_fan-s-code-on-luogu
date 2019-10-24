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
char str[maxn];
int main()
{
	scanf("%s",str);
	int tot=strlen(str);
	int stone=0;
	for(ri i=0; i<tot;i++)
	{
		if(str[i]=='g')
		{
			stone++;//对面出石头的数量
		}
	}
	int towel=tot>>1;//没法，只能硬核翻译了
	int win=min(towel,stone);
	int lose=min(tot-towel,tot-stone);
	return 0&printf("%d",win-lose);
}
