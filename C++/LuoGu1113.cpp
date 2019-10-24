#include <bits/stdc++.h>
#define ri register int
using namespace std;
int n,time_cow;
int t;
int ans[10005];
int res;
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
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		i=read();
		time_cow=read();
		int tmp=0;
		while((t=read()))
		{
			tmp=max(ans[t],tmp);
		}
		ans[i]=tmp+time_cow;
		res=max(ans[i],res);
	}
	return 0&printf("%d\n",res);
}//Õæ¡¤¶¾ÁöÑ¹Ëõ·¨
