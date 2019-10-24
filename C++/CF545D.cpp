#include <bits/stdc++.h>
#define ll long long
#define ri register int
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

int n;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		q.push(read());
	}
	int now=0;
	int tot=0;
	while(q.size())
	{
		int top=q.top();
		q.pop();
		if(now<=top)
		{
			tot++;
			now+=top;
		}
	}
	return 0&printf("%d",tot);
}
/*
5
15 2 1 5 3
out:
4
*/
