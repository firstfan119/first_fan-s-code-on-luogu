#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>//平板电视
#define ri register int
using namespace __gnu_pbds;
const int maxn=2e6+5;
int a[maxn];
bool vis[maxn];
int n,cnt=0;
std::pair<int,int> ans[maxn];
priority_queue<std::pair<int, std::pair<int, int> >, std::greater<std::pair<int, std::pair<int, int> > > > q;
int main()
{
	char sex[maxn];
	scanf("%d%s",&n,sex+1);
	for(ri i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(ri i=1; i<n; i++)
	{
		if(sex[i]!=sex[i+1])
		{
			q.push(std::make_pair(abs(a[i]-a[i+1]),std::make_pair(i,i+1)));
		}
	}
	while(!q.empty())
	{
		int top_l=q.top().second.first;
		int top_r=q.top().second.second;
		q.pop();
		if(!vis[top_l]&& !vis[top_r])
		{
			vis[top_l]=vis[top_r]=true;
			ans[++cnt]=std::make_pair(top_l,top_r);
			while(top_l>=1&&vis[top_l])
			{
				top_l--;
			}
			while(top_r<=n&&vis[top_r])
			{
				top_r++;
			}
			if(top_l>=1&&top_r<=n&&sex[top_l]!=sex[top_r])
			{
				q.push(std::make_pair(abs(a[top_l]-a[top_r]),std::make_pair(top_l,top_r)));
			}
		}
	}
	printf("%d\n",cnt);
	for(ri i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}//STL三重pair过手
