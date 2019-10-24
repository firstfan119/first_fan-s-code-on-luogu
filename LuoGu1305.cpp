#include <bits/stdc++.h>
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

const int maxn=1125;
struct _node
{
	int ls;
	int rs;
} node[maxn];

inline void print(int now)
{
	if(now=='*')
	{
		return ;
	}
	cout<<char(now);
	print(node[now].ls);
	print(node[now].rs);
}

char r,u,v;
int main()
{
	int root;
	int n=read();
	for(int i=1; i<=n; i++)
	{
		cin>>r>>u>>v;
		if(i==1)
		{
			root=r;
		}
		node[(int)r].ls=u;
		node[(int)r].rs=v;
	}
	print(root);//root
}
