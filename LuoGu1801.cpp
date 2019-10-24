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

int a[200005];
int main()
{
	priority_queue<int>down;//大根堆在下
	priority_queue<int,vector<int>,greater<int> >up;//小根堆在上
	//保证大根堆堆顶为小根堆堆底
	int n=read();
	int m=read();
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
	}
	int last=1;
	for(ri i=1; i<=m; i++)
	{
		int pos=read();
		for(ri j=last; j<=pos; j++)
		{
			down.push(a[j]);
			if(down.size()==i)//大根堆内只剩i个元素，根即序列第i大。
			{
				up.push(down.top());
				down.pop();
			}//从上次的断点位置开始到询问位置,
			//将下面的堆顶取到上面的堆顶.
		}
		last=pos+1;//断点记录
		printf("%d\n",up.top());//取出

		down.push(up.top());
		up.pop();
		//将上面的堆顶取到下面的堆顶.
	}
}
