#include <bits/stdc++.h>
#define ri register int
#define db double
#define calc(a,b) sqrt((pos_x[a]-pos_x[b])*(pos_x[a]-pos_x[b])+(pos_y[a]-pos_y[b])*(pos_y[a]-pos_y[b]))
using namespace std;
int n;
db ans=20031125;
bool vis[20];
db pos_x[20];
db pos_y[20];

int dfs(int now,db dis,int cnt)
{
	if(cnt==n&&dis<ans)
		ans=dis;
	if(dis>ans)
		return 0;
	for(ri i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(i,dis+calc(now,i),cnt+1);
			vis[i]=false;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(ri i=1; i<=n; i++)
	{
		scanf("%lf%lf",&pos_y[i],&pos_x[i]);
	}
	return 0&dfs(0,0,0)&printf("%.2f",ans);
}
