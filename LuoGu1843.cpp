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
	return flg*num;
}

priority_queue <int> q;
int ans=0;
int main()
{
	int n=read();
	int nat=read();//natural
	int mac=read();//machine(use mac to dry clothes 2333
	for(ri i=1;i<=n;i++)
	{
		q.push(read());
	}
	while(q.top()>ans*nat)
	{
		while(q.top()<=0)
		{
			q.pop();
		}
		int top=q.top();
		q.pop();
		top-=mac;
		q.push(top);
		ans++;
	}
	return 0&printf("%d",ans);
}
