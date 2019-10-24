#include<bits/stdc++.h>
using namespace std;
int a[50001],n,m,l,r,now,ans,cnt[50001],s[50001],w[50001][2];
struct ask
{
	int left;
	int right;
	int blockl;
	int blockr;
	int pre;
	int id;
} ask[500001];
void leftrun(int x)
{
	cnt[x]--;
	if(cnt[x]==0)ans--;
}
void rightrun(int x)
{
	cnt[x]++;
	if(cnt[x]==1)ans++;
}
void swaprun(int stp)
{
	if(w[now][0]>=ask[stp].left&&w[now][0]<=ask[stp].right)
	{
		if(--cnt[a[w[now][0]]]==0)ans--;
		if(++cnt[w[now][1]])ans++;
	}
	swap(a[w[now][0]],w[now][1]);
}
void md(int stp)
{
	while(l>ask[stp].left)rightrun(a[--l]);
	while(l<ask[stp].left)leftrun(a[l++]);
	while(r>ask[stp].right)leftrun(a[r--]);
	while(r<ask[stp].right)rightrun(a[++r]);
	while(now<ask[stp].pre)
	{
		now++;
		swaprun(stp);
	}
	while(now>ask[stp].pre)
	{
		swaprun(stp);
		now--;
	}
	s[ask[stp].id]=ans;
}
bool cmp(struct ask a,struct ask b)
{
	if(a.blockl==b.blockl)
	{
		if(a.blockr==b.blockr)
		{
			return a.pre<b.pre;
		}
		return a.right<b.right;
	}
	return a.left<b.left;
}
int main()
{
	char c;
	int cnum=0,qnum=0;
	scanf("%d %d",&n,&m);
	for(register int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(register int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%[QR]", &c);
		scanf("%d%d",&x,&y);
		//cout<<c<<endl;
		if(c=='Q')
		{
			//cout<<"*";
			ask[++qnum].left=x;
			ask[qnum].right=y;
			ask[qnum].blockl=ask[qnum].left/(int(pow(n,2/3)));
			ask[qnum].blockr=ask[qnum].right/(int(pow(n,2/3)));
			ask[qnum].id=qnum;
			ask[qnum].pre=cnum;
		}
		if(c=='R')
		{
			//cout<<"^";
			w[++cnum][0]=x;
			w[cnum][1]=y;
		}
	}
	sort(ask+1,ask+m+1,cmp);
	for(register int i=1; i<=qnum; i++)md(i);
	for(register int i=1; i<=qnum; i++)
	{
		printf("%d\n",s[i]);
	}
	return 0;
}
