#include <bits/stdc++.h>
#include <stdlib.h>
#define ri register int
#define ll long long
using namespace std;

const int maxn=12;
char x[maxn];
bool vis[maxn];

int main()
{
	scanf("%s",x);
	int len=strlen(x);
	int val=atoi(x);//巧用函数
	if (val==1)
	{
		return 0&printf("%d",1);
	}
	for(ri i=0; i<len; i++)
	{
		vis[x[i]-'0']=true;
	}
	int cnt=0;
	for(ri i=1; i<=sqrt(val); i++)
	{
		if (val%i==0)
		{
			memset(x,0,sizeof(x));
			sprintf(x,"%d",i);//巧用函数
			len=strlen(x);
			for(ri j=0; j<len; j++)
			{
				if (vis[x[j]-'0'])
				{
					cnt++;
					break;
				}
			}
			if (i*i!=val)
			{
				memset(x,0,sizeof(x));
				sprintf(x,"%d",val/i);
				len=strlen(x);
				for(ri j=0; j<len; j++)
				{
					if (vis[x[j]-'0'])
					{
						cnt++;
						break;
					}
				}
			}
		}
	}
	return 0&printf("%d",cnt);
}//简单模拟
