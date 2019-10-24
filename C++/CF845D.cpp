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

stack<ll>s;

int main()
{
	int n=read();
	int speed=0;
	int cnt=0;
	int over=0;
	int lim=0;
	while(n--)
	{
		int opt=read();
		switch(opt)
		{
			case 1:
			{
				speed=read();
				break;
			}//改变速度
			case 2:
			{
				cnt+=over;
				over=0;
				break;
			}//超车
			case 3:
			{
				lim=read();
				s.push(lim);
				break;
			}//限速
			case 4:
			{
				over=0;
				break;
			}//允许超车
			case 5:
			{
				stack<ll>Void;
				swap(Void,s);
				break;
			}//取消限速
			default://6
			{
				over++;
				break;
			}//禁止超车
		}
		while(s.size()&&s.top()<speed)
		{
			s.pop();
			cnt++;
		}
	}
	return 0&printf("%d",cnt);
}
