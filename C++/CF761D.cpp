#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct obj
{
	int pos,rank,low,up;
};
bool objCompare(obj a,obj b)
{
	return a.rank<b.rank;
}

int main()
{

	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	vector<int> a(n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	vector<obj> c(n);
	for(int i=0; i<n; i++)
	{
		int u;
		scanf("%d",&u);
		c[i].pos=i;
		c[i].rank=u - 1;
		c[i].low=l - a[i];
		c[i].up=r - a[i];
	}

	sort(c.begin(),c.end(),objCompare);
	int lst(-2e9);
	bool success(true);
	vector<int> v(n);
	for(int i=0; i<n; i++)
	{
		int w=c[i].pos;
		if(lst<c[i].low)
		{
			v[w]=c[i].low;
		}
		else if(lst<c[i].up)
		{
			v[w]=lst + 1;
		}
		else
		{
			success=false;
			break;
		}
		lst=v[w];
	}

	if(!success)
	{
		puts("-1");
		return 0;
	}
	vector<int> b(n);
	for(int i=0; i<n; i++)
	{
		b[i]=v[i] + a[i];
	}
	for(int i=0; i<n; i++)
	{
		printf("%d ",b[i]);
	}
}
