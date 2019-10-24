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
struct dot
{
	int x;
	int y;
}s[maxn],e[maxn];//瘟疫，领主

int t[maxn];

int calc(dot one,dot two)
{
	return abs(one.x-two.x)+abs(one.y-two.y);
}

int main()
{
	int n=read();
	int m=read();
	int st=read();//瘟疫
	int ed=read();//领主
	for(ri i=1;i<=st;i++)
	{
		s[i].x=read();
		s[i].y=read();
	}
	for(ri i=1;i<=ed;i++)
	{
		e[i].x=read();
		e[i].y=read();
	}
	int cur=20031125;
	for(ri i=1;i<=ed;i++)
	{
		cur=20031125;
		for(ri j=1;j<=st;j++)
		{
			cur=min(cur,calc(e[i],s[j]));
		}
		printf("%d\n",cur);
	}
}
