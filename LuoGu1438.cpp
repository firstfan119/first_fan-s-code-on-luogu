#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define lowbit(x) (x&(-x))
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
int m;
int a[100005];
int val[100005][2];
void single_add(int pos,int k,int d)
{
	int x=pos;
	while(x<=n)
	{
		val[x][0]+=k;
		val[x][1]+=d;
		k+=d*lowbit(x);
		x+=lowbit(x);
	}
}
int interval_sum(int pos)
{
	int x=pos;
	int res=0;
	while(x)
	{
		res+=val[x][0]+(pos-x)*val[x][1];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=n; i++)
	{
		a[i]=read();
	}
	for(ri i=1; i<=m; i++)
	{
		int opt=read();
		switch(opt)
		{
			case 1:
			{
				int l=read();
				int r=read();
				int u=read();
				int v=read();
				single_add(l,u,v);
				single_add(r+1,-u-(r+1-l)*v,-v);
				break;
			}
			default:
			{
				int qst=read();
				printf("%d\n",a[qst]+interval_sum(qst));
				break;
			}
		}
	}
}
/*
5 2
1 2 3 4 5
1 2 4 1 2
2 3
out:
6
*/
