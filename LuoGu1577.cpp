#include <bits/stdc++.h>
using namespace std;
#define mn 100010
#define inf 1<<30
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
double d[mn];
int a[mn];
int n,m,minn,maxx;
inline bool judge(int x)
{
	int num=0;
	for(register int i=1;i<=n;i++)
	{
		num+=a[i]/x;
	}
	return num>=m;
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++) 
	{
		scanf("%lf",&d[i]);
		a[i]=int(d[i]*100);
	}
	int l=0,r=inf;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(mid==0)  break;//这里是个特判。至于为什么，作为思考题。（其实也不难理解）
		if(judge(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%.2f",r/100.0);
	return 0;
}
