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
int f[maxn];

int find(int x)
{
	return f[x]==x?x:(f[x]=find(f[x]));
}

int r[maxn];

int main()
{
	int n=read();
	int q=read();
	for(ri i=1;i<=n;i++)
	{
		f[i]=i;
		r[i]=i+1;
	}
	while(q--)
	{
		int opt=read();
		int u=read();
		int v=read();
		int fu=find(u);
		int fv=find(v);
		if(opt==1)
		{
			f[fu]=find(fv);
		}
		else if(opt==2)
		{
			while(u<v)
			{
				fu=find(u);
				fv=find(v);
				f[fu]=fv;
				int tmp=r[u];
				r[u]=r[v];
				u=tmp;
			}
		}
		else if(opt==3)
		{
			if(fu!=fv)
			{
				puts("NO");
			}
			else
			{
				puts("YES");
			}
		}
	}
}
