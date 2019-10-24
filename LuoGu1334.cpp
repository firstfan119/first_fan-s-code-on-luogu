#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
int n;
priority_queue <int,vector<int>,greater<int> > q;
int want;
#define ll long long
ll ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&want);
		q.push(want);
	}
	int last=0;
	for(int i=1;i<n;i++)
	{
		last=ans;
		ans+=q.top();
		q.pop();
		ans+=q.top();
		q.pop();
		q.push(ans-last);
	}
	cout<<ans;
}
