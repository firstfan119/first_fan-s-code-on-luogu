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
int ans=0;
stack<int>s;//STL栈

int top=0;
int stk[maxn];
void print()
{
	cout<<"------------------------------"<<endl;
	while(s.size())
	{
		stk[++top]=s.top();
		s.pop();
	}
	for(ri i=top;i>=1;i--)
	{
		cout<<stk[top-i+1]<<endl;
		s.push(stk[i]);
	}
	top=0;
	cout<<"------------------------------"<<endl;
	
}

int main()
{
	int n=read();
	while (n--)//边读边做
	{
		int x=read();
		while (s.size())//维护一个单调递减栈
		{
			ans=max(ans,s.top()^x);
			if(s.top()>x)
			{
				break;
			}
			//如果新数比栈头小，则直接压栈
			//否则清空栈内比新数小的所有数
			s.pop();
			print();
		}
		s.push(x);//压栈
		print();
	}
	return 0&printf("%d",ans);
}
