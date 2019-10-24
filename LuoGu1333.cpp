#include <bits/stdc++.h>
#define ri register int
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
gp_hash_table<string,int>hash;
//从此手写hash是路人

const int maxn=1e6+7;

int tot=0;
int f[maxn];
int rd[maxn];
int find(int x)
{
	return f[x]==x?x:(f[x]=find(f[x]));
}
int cnct(int x,int y)
{
	rd[x]++;
	rd[y]++;
	int fu=find(x);
	int fv=find(y);
	if(fu==fv)
	{
		return 0;
	}
	f[fu]=fv;
	return 1;
}//connect

int main()
{
	for(ri i=1; i<=666666; i++)
	{
		f[i]=i;
	}
	string a,b;
	int ans=0;
	while(cin>>a>>b)
	{
		int posa=hash[a]?hash[a]:(hash[a]=++tot);
		int posb=hash[b]?hash[b]:(hash[b]=++tot);
		ans+=cnct(posa,posb);
	}
	if(ans<tot-1)
	{
		return 0&printf("Impossible");
	}
	int flg=0;
	for(ri i=1; i<=tot; i++)
	{
		if(rd[i]%2==1)
		{
			flg++;
		}
	}
//Euler's circle.
	if(flg>2)
	{
		return 0&printf("Impossible");
	}
	return 0&printf("Possible");
	printf("first_fan is handsome.");
}
