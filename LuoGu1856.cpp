#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
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
struct segment_tree
{
	int l;
	int r;
	int cnt;
	int cov;//covered
	int len;//覆盖y方向的总长
	int lcov;
	bool rcov;//左右结点是否被覆盖
} seg[maxn];

struct line
{
	int y1;
	int y2;
	int x;
	int flg;
	friend bool operator <(line one,line two)
	{
		return one.x==two.x?one.flg>two.flg:one.x<two.x;
	}//排序特别重要！还有第二关键字！！
} e[maxn];

void build(int nd,int l,int r)
{
	seg[nd].l=l;
	seg[nd].r=r;
	seg[nd].cnt=0;
	if(r-1==l)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(ls(nd),l,mid);
	build(rs(nd),mid,r);
}

vector<int> vec;

void updlen(int nd)
{
	if(seg[nd].cov>0)
	{
		seg[nd].len=vec[seg[nd].r]-vec[seg[nd].l];
		seg[nd].lcov=seg[nd].rcov=1;
		seg[nd].cnt=1;
		return ;
	}
	if(seg[nd].l==seg[nd].r-1)
	{
		seg[nd].cov=seg[nd].lcov=seg[nd].rcov=0;
		seg[nd].cnt=seg[nd].len=0;
		return;
	}
	seg[nd].lcov=seg[ls(nd)].lcov;
	seg[nd].rcov=seg[rs(nd)].rcov;
	seg[nd].len=seg[ls(nd)].len+seg[rs(nd)].len;
	seg[nd].cnt=seg[ls(nd)].cnt+seg[rs(nd)].cnt-(seg[ls(nd)].rcov&seg[rs(nd)].lcov);
}

void upd(int nd,line str)
{
	if(str.y1<=vec[seg[nd].l]&&str.y2>=vec[seg[nd].r])
	{
		seg[nd].cov+=str.flg;
		updlen(nd);
		return ;
	}
	if(seg[nd].l==seg[nd].r-1)
	{
		return ;
	}
	int mid=(seg[nd].l+seg[nd].r)>>1;
	if(str.y1<=vec[mid])
	{
		upd(ls(nd),str);
	}
	if(str.y2>vec[mid])
	{
		upd(rs(nd),str);
	}
	updlen(nd);
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int cnt=0;
		for(ri i=0; i<n; i++)
		{
			int u1=read();
			int v1=read();
			int u2=read();
			int v2=read();
			e[cnt].x=u1;
			e[cnt].y1=v1;
			e[cnt].y2=v2;
			e[cnt].flg=1;
			cnt++;
			e[cnt].x=u2;
			e[cnt].y1=v1;
			e[cnt].y2=v2;
			e[cnt].flg=-1;
			cnt++;
			vec.push_back(v1);
			vec.push_back(v2);
		}
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		sort(e,e+cnt);
		build(1,0,vec.size()-1);
		int ans=0;
		int last=0;
		int li=0;
		for(ri i=0; i<cnt; i++)
		{
			upd(1,e[i]);
			if(i>=1)
			{
				ans+=li*2*(e[i].x-e[i-1].x);
			}
			ans+=abs(seg[1].len-last);
			last=seg[1].len;
			li=seg[1].cnt;
		}
		printf("%d\n",ans);
	}
}
