#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define lowbit(x) (x&(-x))
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

int ans=0;
int n;
int lim;

const int maxn=1125;
int f[maxn];
char maap[maxn][maxn];
char s[maxn];

void dfs(int x,int l,int r,int tot)
{
	if(x>n)
	{
		ans++;
		return ;
	}
	int t=lim&~(l|r|tot|f[x]);
	while(t)
	{
		int p=lowbit(t);
		dfs(x+1,(l|p)>>1,(r|p)<<1,tot|p);
		t-=p;
	}
}

int main()
{
	n=read();
	lim=(1<<n)-1;
	for(ri i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(ri j=1;j<=n;j++)
		{
			if(s[j]=='.')
			{
				f[i]+=(1<<(j-1));
			}
		}
	}
	dfs(1,0,0,0);
	return 0&printf("%d",ans);
}
