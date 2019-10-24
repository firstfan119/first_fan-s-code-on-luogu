#include <bits/stdc++.h>
#define ri register int
#define ll long long
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

const int maxn=1e6+7;

#define ls(x) (t[x].l)
#define rs(x) (t[x].r)
struct SBT
{
	int val;
	int l;
	int r;
	int siz;
} t[maxn];

int rt=0;
int cnt=0;

void lrot(int &x)
{
	int y=rs(x);
	rs(x)=ls(y);
	ls(y)=x;
	t[y].siz=t[x].siz;
	t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
	x=y;
}

void rrot(int &x)
{
	int y=ls(x);
	ls(x)=rs(y);
	rs(y)=x;
	t[y].siz=t[x].siz;
	t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
	x=y;
}

void maintain(int &x,bool lr)
{
	if(!lr)
	{
		if(t[ls(ls(x))].siz>t[rs(x)].siz)
		{
			rrot(x);
		}
		else if(t[rs(ls(x))].siz>t[rs(x)].siz)
		{
			lrot(ls(x));
			rrot(x);
		}
		else
		{
			return ;
		}
	}
	else
	{
		if(t[rs(rs(x))].siz>t[ls(x)].siz)
		{
			lrot(x);
		}
		else if(t[ls(rs(x))].siz>t[ls(x)].siz)
		{
			rrot(rs(x));
			lrot(x);
		}
		else
		{
			return ;
		}
	}
	maintain(ls(x),0);
	maintain(rs(x),1);
	maintain(x,1);
	maintain(x,0);
}

void insert(int &x,int val)
{
	if(!x)
	{
		x=++cnt;
		t[x].val=val;
		t[x].siz=1;
		return ;
	}
	t[x].siz++;
	if(val<t[x].val)
	{
		insert(ls(x),val);
	}
	else
	{
		insert(rs(x),val);
	}
	maintain(x,val>=t[x].val);
}

int del(int &x,int val)
{
	t[x].siz--;
	int res=0;
	if(val==t[x].val||(val<t[x].val&&!ls(x))||(val>t[x].val&&!rs(x)))
	{
		res=t[x].val;
		if(!ls(x)||!rs(x))
		{
			x=ls(x)+rs(x);
		}
		else
		{
			t[x].val=del(ls(x),t[x].val+1);
		}
		return res;
	}
	if(val<t[x].val)
	{
		res=del(ls(x),val);
	}
	else
	{
		res=del(rs(x),val);
	}
	return res;
}

int rank(int &x,int val)
{
	if(!x)
	{
		return 1;
	}
	int res=0;
	if(val<=t[x].val)
	{
		res=rank(ls(x),val);
	}
	else
	{
		res=t[ls(x)].siz+rank(rs(x),val)+1;
	}
	return res;
}

int kth(int &x,int val)
{
	if(val==t[ls(x)].siz+1)
	{
		return t[x].val;
	}
	else if(val<=t[ls(x)].siz)
	{
		return kth(ls(x),val);
	}
	else
	{
		return kth(rs(x),val-t[ls(x)].siz-1);
	}
}

int pre(int &x,int val)
{
	if(!x)
	{
		return val;
	}
	int res=0;
	if(val<=t[x].val)
	{
		res=pre(ls(x),val);
	}
	else
	{
		res=pre(rs(x),val);
		if(res==val)
		{
			res=t[x].val;
		}
	}
	return res;
}

int suc(int &x,int val)
{
	if(!x)
	{
		return val;
	}
	int res=0;
	if(val>=t[x].val)
	{
		res=suc(rs(x),val);
	}
	else
	{
		res=suc(ls(x),val);
		if(res==val)
		{
			return t[x].val;
		}
	}
	return res;
}


int main()
{
	int n=read();
	int lim=read();
	int ans=0;
	int tot=0;
	int add=0;
	rt=0;
	int tt=0;
	t[0].siz=0;
	for(ri i=1; i<=n; i++)
	{
		string s;
		cin>>s;
		int k=read();
		if(s[0]=='I'&&k>=lim)
		{
			insert(rt,k-add);
			++tot;
		}
		if(s[0]=='A')
		{
			add+=k;
		}
		if(s[0]=='S')
		{
			int j;
			add-=k;
			while(tot&&(j=kth(rt,1))+add<lim)
			{
				del(rt,j);
				--tot;
				++ans;
			}
		}
		if(s[0]=='F')
		{
			if(k>tot)
			{
				puts("-1");
			}
			else
			{
				printf("%d\n",kth(rt,tot-k+1)+add);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
