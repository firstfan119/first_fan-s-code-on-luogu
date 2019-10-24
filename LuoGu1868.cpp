#include<bits/stdc++.h>
#define ll long long
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
int n;
int f[3000010];
vector<int>from[3000010];
int far=0;
int main()
{
	n=read();
	for(ri i=1;i<=n;i++)
	{
		int x=read();
		int y=read();
		far=max(max(far,x),y);
		from[y].push_back(x);
	}
	for(ri i=0;i<=far+1;i++)
	{
		f[i]=f[i-1];
		for(ri j=0;j<from[i].size();j++)
		{
			if(from[i][j]>=1)
			{
				f[i]=max(f[i],f[from[i][j]-1]+i-from[i][j]+1);
			}
			else
			{
				f[i]=max(f[i],i+1-from[i][j]+1);
			}
		}
	}
	return 0&printf("%d",f[far+1]);
}
