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

const int maxn=1e7+1000;
int f[maxn];
int vis[maxn];
int a[maxn];
int pos[102];

int main()
{
	read();//用得着吗？
	//用不着！
	int s=read();
	int t=read();
	int stone=read();
	for(ri i=1; i<=stone; i++)
	{
		pos[i]=read();
	}
	sort(pos+1,pos+stone+1);
	int tot=0;
	for(ri i=1;i<=stone;i++)
	{
		if(pos[i]-pos[i-1]>2520)
		{
			tot+=(pos[i]-pos[i-1])-(pos[i]-pos[i-1])%2520;
		}
		vis[pos[i]-tot]=1;
	}//状压！很重要！
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(ri i=1; i<=252000; i++)
	{
		for(ri j=t; j>=s; j--)
		{
			if(i>=j)
			{
				f[i]=min(f[i],f[i-j]+vis[i]);
			}
		}
	}
	return 0&printf("%d",f[252000]);
}
