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
struct node
{
	int val;
	int pos;
	friend bool operator < (node x,node y)
	{
		return x.val<y.val;
	}
};
const int maxn=20031125;
priority_queue<node> heap;
int n,m;
int ans=0;
int nex[maxn],pre[maxn];//linking_chart
bool vis[maxn];
int val[maxn];
int l,r;
void link(int x)
{
	vis[x]=true;
	nex[pre[x]]=nex[x];
	pre[nex[x]]=pre[x];//link
	pre[x]=nex[x]=0;//clear
}
int main()
{
	n=read();
	m=read();
	if(n<m*2)
	{
		return 0&printf("Error!\n");
	}
	for(ri i=1; i<=n; i++)
	{
		val[i]=read();
	}

	nex[1]=2;
	nex[n]=1;
	pre[1]=n;
	pre[n]=n-1;
	//special
	for(ri i=2; i<=n-1; i++)
	{
		nex[i]=i+1;
		pre[i]=i-1;
	}
	for(ri i=1; i<=n; i++)
	{
		heap.push((node)
		{
			val[i],i
		});
	}
	for(ri i=1;i<=m;i++)
	{
		while(vis[heap.top().pos])
		{
			heap.pop();
		}//emptied
		node top=heap.top();
		heap.pop();//pop&record the head of heap
		ans+=top.val;
		l=pre[top.pos];
		r=nex[top.pos];//get pre&nex
		val[top.pos]=val[l]+val[r]-val[top.pos];//update val
		link(l);
		link(r);//linking l&r
		heap.push((node){val[top.pos],top.pos
		});//combine two nodes to one
	}
	printf("%d",ans);
}
