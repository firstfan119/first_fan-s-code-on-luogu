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

int dire=1;//记录桥方向是否倒转
int main()
{
	int x1=read();
	int x2=read();
	int dis=x2-x1;
	int a=read();
	int b=read();
	if(a<=0&&b<=0)//均负
	{
		swap(a,b);
		a=-a;
		b=-b;
		dis=-dis;
		dire=-dire;//反向
	}
	if(a<=0)//异号
	{
		if(a<=dis&&dis<=b)
		{
			puts("FIRST");
			return 0&printf("%d",x2);
		}
		else//甲不能一发制敌
		{
			return 0&(int)puts("DRAW");
		}
	}
	//两种情况：
	//1.本来就均正
	//2.翻转后均正
	if(dis<0)//南辕北辙
	{
		return 0&(int)puts("DRAW");
	}
	else if(dis%(a+b)==0)
	{
		return 0&(int)puts("SECOND");
	}
	else if(a<=dis%(a+b)&&dis%(a+b)<=b)//甲胜
	{
		puts("FIRST");
		return 0&printf("%d",x2-dire*(dis/(a+b))*(a+b));//方向得用上。
	}
	else//平局
	{
		return 0&(int)puts("DRAW");
	}
}
