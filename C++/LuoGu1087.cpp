#include <bits/stdc++.h>
char ch[1025];
void build(int l, int r)//½¨Ê÷¶øÒÑ
{
	int mid = (l+r)/2;
	if (l!=r)
	{
		build(l, mid);
		build(mid+1,r);
	}
	int i,a=0,b=0;
	for (i=l; i<=r; i++)
	{
		if (ch[i]=='0')
		{
			a=true;
		}
		else
		{
			b=true;
		}
	}


	if (a&&b)
	{
		printf("F");
	}
	else if (a)
	{
		printf("B");
	}
	else
	{
		printf("I");
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", ch+1);
	build(1, 1<<n);
	return 0;
}
