#include <bits/stdc++.h>
#define ri register int
using namespace std;
int n;
priority_queue<int> q;
int main()
{
	scanf("%d",&n);
	int u;
	for(ri i=1;i<=n;i++)
	{
		scanf("%d",&u);
		q.push(u);
	}
	return 0&printf("%d",u^q.top());
}
