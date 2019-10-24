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
	return flg*num;
}

const int maxn=1e6+7;
struct main_object
{
	int cost;
	int val;
}o[maxn];//main object

int c[maxn][3];
int w[maxn][3];
int tot[maxn];//tot[i]->how many sons does i has.
int f[maxn];
int main()
{
	int n=read();
	int m=read();
	for(int i=1; i<=m; i++)
	{
		int val=read();
		int im=read();//importance.
		int fa=read();
		if(!fa)//main
		{
			o[i].cost=val;
			o[i].val=val*im;
		}
		else
		{
			tot[fa]++;
			c[fa][tot[fa]]=val;
			w[fa][tot[fa]]=val*im;
		}
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=n; j>=o[i].cost; j--)
		{
			f[j]=max(f[j],f[j-o[i].cost]+o[i].val);
			if(j>=o[i].cost+c[i][1])
			{
				f[j]=max(f[j],f[j-o[i].cost-c[i][1]]+o[i].val+w[i][1]);
			}
			if(j>=o[i].cost+c[i][2])
			{
				f[j]=max(f[j],f[j-o[i].cost-c[i][2]]+o[i].val+w[i][2]);
			}
			if(j>=o[i].cost+c[i][1]+c[i][2])
			{
				f[j]=max(f[j],f[j-o[i].cost-c[i][1]-c[i][2]]+o[i].val+w[i][1]+w[i][2]);
			}
		}
	}
	return 0&printf("%d",f[n]);
}
