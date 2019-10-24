#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
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

int calc(db one,db two,db three)
{
	if((one+two>three)&&(one+three>two)&&(two+three>one))
	{
		db p=(one+two+three)/2;
		return trunc(sqrt(p*(p-one)*(p-two)*(p-three))*100);
	}//要的是面积的100倍
	else
	{
		return -1;
	}
}

const int maxn=45;
int n;
int l[maxn];
priority_queue<int,vector<int>,greater<int> >q;

int main()
{
	int ans=-1;
	n=read();
	for(ri i=1; i<=n; i++)
	{
		l[i]=read();
	}
	for(ri i=1; i<=10000; i++)
	{
		random_shuffle(l+1,l+n+1);
		for(ri j=1; j<=3; j++)
		{
			q.push(l[j]);
		}
		for(ri j=4; j<=n; j++)
		{
			int top=q.top();
			q.pop();
			top+=l[j];
			q.push(top);
		}
		int one=q.top();
		q.pop();
		int two=q.top();
		q.pop();
		int three=q.top();
		q.pop();
		ans=max(ans,calc(one,two,three));
	}
	return 0&printf("%d",ans);
}

