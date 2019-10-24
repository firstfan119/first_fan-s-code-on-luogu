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

const int maxn=1125;
char v[maxn];
int del;//删除
int len;//位数
int sav;//保留
int u[maxn];
queue<int> q;
int main()
{
	scanf("%s",v);
	len=strlen(v);
	del=read();
	sav=len-del;
	for(ri i=0; i<=len-1; i++)
	{
		u[i]=v[i]-'0';
	}
	int lst=-1;
	while(sav-q.size())
	{
		int mn=20031125;
		for(ri i=lst+1; i<=len-sav+q.size(); i++)
		{
			if(u[i]<mn)
			{
				mn=u[i];
				lst=i;
			}
		}
		q.push(u[lst]);
	}
	bool st=true;
	bool qwq=0;
	while(q.size())
	{
		if(!q.front()&&st)
		{
			q.pop();
			continue;
		}
		if(q.front()&&st)
		{
			st=false;
		}//前导0处理完毕
		printf("%d",q.front());
		qwq=1;
		q.pop();
	}
	if(!qwq)
	{
		return 0&(int)puts("0");
	}
}
