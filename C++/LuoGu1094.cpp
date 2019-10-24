#include <bits/stdc++.h>
using namespace std;
#define ri register int
int n;
int group=0;
int limit;
int s[1000007];
int main()
{
	scanf("%d",&limit);
	scanf("%d",&n);
	for(ri i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+1,s+n+1);
	int *head=s+1;
	int *end=s+n;
	while(head<=end)
	{
		if(*head+*end<=limit)
		{
			group++;
			head++;
			end--;
		}
		else
		{
			group++;
			end--;
		}
	}
	printf("%d",group);
}
