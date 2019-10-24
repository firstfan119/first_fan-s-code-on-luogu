#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
inline int read()
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

#define lowbit(x) (x&(-x))
const int maxn=5e4+5;

int n,m;
int t[maxn];
bool vis[maxn];

inline void single_add(int x,int val)
{
	while(x<=n)
	{
		t[x]+=val;
		x+=lowbit(x);
	}
}
inline int interval_sum(int x)
{
	int res=0;
	while(x)
	{
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
inline int b_s(int x,bool l_or_r)
{
	if(l_or_r==0)
	{
		int l=0;
		int r=x;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(interval_sum(x)-interval_sum(mid)>=1)
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		return l;
	}
	else
	{
		int l=x;
		int r=n+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(interval_sum(mid)-interval_sum(x)>=1)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		return l;
	}
}
int main()
{
	n=read();
	m=read();
	stack<int> stk;
	for(ri i=1; i<=m; i++)
	{
		char s[1125];
		scanf("%s",s+1);
		if(s[1]=='D')
		{
			int x=read();
			single_add(x,1);
			stk.push(x);
			vis[x]=true;
		}
		if(s[1]=='R')
		{
			vis[stk.top()]=false;
			single_add(stk.top(),-1);
			stk.pop();
		}
		if(s[1]=='Q')
		{
			int x=read();
			int len=b_s(x,1)-b_s(x,0)-1;
			if(vis[x])
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n",len);
			}
		}
	}
}
/*
7 9
D 3
D 6
D 5
Q 4
Q 5
R
Q 4
R
Q 4
out:
1
0
2
4
*/
