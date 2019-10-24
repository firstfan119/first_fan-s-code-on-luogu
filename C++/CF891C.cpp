#include <bits/stdc++.h>
#include <vector>
#include <utility>
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

struct edge
{
	int id;
	int fr;
	int to;
	int val;
} e[666666],qst[666666];

bool operator<(edge a,edge b){return a.val<b.val;}
bool cmp(edge a,edge b){return a.id<b.id;}

int n,m,q,k;
int f[666666];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

bool solve()
{
	k=read();
	for(ri i=1; i<=k; i++)
	{
		qst[i]=e[read()];
	}
	sort(qst+1,qst+k+1);
	for(ri i=1,j=1; i<=k;i=++j)//注意！！这里是i=++j!!
	//不能直接写i++,j++(j更新过)
	{
		while(j<k&&qst[j+1].val==qst[i].val)
		{
			j++;
		}
		for(ri l=i; l<=j; l++)
		{
			f[qst[l].fr]=qst[l].fr;
			f[qst[l].to]=qst[l].to;
		}
		for(ri l=i; l<=j; l++)
		{
			int fu=find(qst[l].fr);
			int fv=find(qst[l].to);
			if(fu==fv)
			{
				return false;
			}
			else
			{
				f[find(fu)]=find(fv);
			}
		}
	}
	return true;
}

int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=n; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		e[i].fr=read();
		e[i].to=read();
		e[i].val=read();
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	for(ri i=1,j=1; i<=m;i=++j)
	{
		while(j<m&&e[j+1].val==e[i].val)
		{
			j++;
		}
		for(ri l=i; l<=j; l++)
		{
			e[l].fr=find(e[l].fr);
			e[l].to=find(e[l].to);
		}
		for(ri l=i; l<=j; l++)
		{
			int fu=find(e[l].fr);
			int fv=find(e[l].to);
			if(fu==fv)
			{
				continue;
			}
			else
			{
				f[find(fu)]=find(fv);
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	q=read();
	while(q--)
	{
		puts(solve()?"YES":"NO");
	}
}
/*
5 7
1 2 2
1 3 2
2 3 1
2 4 1
3 4 1
3 5 2
4 5 2
4
2 3 4
3 3 4 5
2 1 7
2 1 2
out:
YES
NO
YES
NO

*/
