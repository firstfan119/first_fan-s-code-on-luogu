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
int v[maxn];

int main()
{
	srand(time(0));
	int T=read();
	while(T--)
	{
		int n=read();
		int m=read();
		bool success=false;
		for(ri i=1; i<=n; i++)
		{
			v[i]=read();
		}
		for(ri it=1; it<=300; it++)
		{
			int res=0;
			for(ri i=1; i<=n; i++) //·ûºÅÎ»Ëæ»ú
			{
				if(rand()%2)
				{
					res+=v[i];
				}
				else
				{
					res-=v[i];
				}
			}
			if(res%m==0)
			{
				success=true;
				goto nex;
			}
		}
nex:
		puts(success?"Divisible":"Not divisible");
	}
}
