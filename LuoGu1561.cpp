#include <bits/stdc++.h>
#define ri register int
using namespace std;
int cow;
struct speed
{
	int up;
	int down;
}c[1000007];
int main()
{
	int min_up=20031125;
	int min_down=20031125;
	scanf("%d",&cow);
	int sum_up=0;
	int sum_down=0;
	for(ri i=1;i<=cow;i++)
	{
		scanf("%d%d",&c[i].up,&c[i].down);
		sum_up+=c[i].up;
		sum_down+=c[i].down;
		min_up=min(min_up,c[i].up);
		min_down=min(min_down,c[i].down);
	}
	printf("%d",max(min_up+sum_down,min_down+sum_up));
}
