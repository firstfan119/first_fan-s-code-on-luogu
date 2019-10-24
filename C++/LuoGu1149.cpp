#include <bits/stdc++.h>
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
int n,ans=0;
int alp[1125]= {6,2,5,5,4,5,6,3,7,6};
int num[4];
void dfs(int digit)
{
	for(ri i=0; i<=711; i++)
	{
		if(n-alp[i]>=0)
		{
			num[digit]=i;
			n=n-alp[i];
			if(digit==3)
			{
				if(num[1]+num[2]==num[3]&&n==0)
				{
					ans++;
				}
			}
			else
			{
				dfs(digit+1);
			}
			n+=alp[i];
		}
	}
}
int main()
{
	n=read()-4;
	for(ri i=10; i<=711; i++)
	{
		alp[i]=alp[i/10]+alp[i%10];
	}
	dfs(1);
	return 0&printf("%d",ans);
}
