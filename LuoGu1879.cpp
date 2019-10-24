#include <bits/stdc++.h>
using namespace std;
const int mod=1e8;
int f[13][2100];//方案数 
int judge[13];//最开始可以的
int legal[201];
bool jud(int x)
{
	//恰好错位那么就可以放下 
    return (x & (x>>1));
}
int main()
{
    int m,n; 
    scanf("%d%d",&m,&n);
    int x;
    int full=(1<<n)-1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            if(!x)
			{
				judge[i]=judge[i] | (1<<(n-j));
			}
        }
    }
    int cnt=0;
    for(int i=0;i<=full;i++)
    {
      if(jud(i))
	  {
	  	continue;
	  }
      legal[++cnt]=i;
    }
    int last,now;
    for(int i=1;i<=cnt;i++)
    {
        now=legal[i];
        if(legal[i] & judge[1])
		{
			continue;
		} 
        f[1][i]=1;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            last=legal[j];
            if(last & judge[i-1])
			{
				continue;
			}
            for(int k=1;k<=cnt;k++)
            {
                now=legal[k];
                if(now & judge[i])
				{
					continue;
				}
                if(now & last)
				{
					continue;
				}
                f[i][k]+=f[i-1][j];
                f[i][k]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++)
	{
		ans=(ans+f[m][i])%mod;
	} 
    return 0&printf("%d",ans);
}
