#include <bits/stdc++.h>
#define db double
#define powerr(x) ((x)*(x))
using namespace std;
const int N=1005;
const db t_max=1000,delta=0.993,t_min=1e-14;
db X[N],Y[N],W[N],ans=1e18,ansx=0,ansy=0;int n;
db gougu(db gou,db gu)
{
	db xian;
	for(int i=1;i<=n;i++)
	{
		xian+=sqrt( powerr(gou-X[i]) + powerr(gu-Y[i]) )*W[i];
	}
	return xian;
}
void solve()
{
    db t=t_max;
	db x=rand()*2-0x7fff;
	db y=rand()*2-0x7fff;
    while(t>t_min)
	{
        db tx=x+(rand()*2-0x7fff)*t;
        db ty=y+(rand()*2-0x7fff)*t;
        db tans=gougu(tx,ty);
		db det=tans-ans;
        if(det<0)
		{
            x=tx;y=ty;
            ansx=tx;ansy=ty;
            ans=tans;
        }
        else if(exp(-det/t)*0x7fff>rand())
		{
			x=tx;
			y=ty;
		}
        t*=delta;
    }
}
int main()
{
    srand(time(NULL));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>X[i]>>Y[i]>>W[i];
    int cnt=0;
    while (cnt<=5)
	{
		solve();
		cnt++;
	}
    printf("%.3lf %.3lf",ansx,ansy);
    return 0;
}

