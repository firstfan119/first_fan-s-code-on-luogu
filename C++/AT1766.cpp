#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

int main()
{
	char c=getchar();
	for(ri i=1;i<=3;i++)
	{
		if(c!=getchar())
		{
			return 0&(int)puts("DIFFERENT");
		}
	}
	return 0&(int)puts("SAME");
}
