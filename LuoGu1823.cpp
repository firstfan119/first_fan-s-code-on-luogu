#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

inline int read()
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

struct person
{
	int h;
	//height
	int same;
	//the number of people which can be seen
	//and have the same height as this person's.
};

stack<person> stk;//����ջ

int n;
ll cnt=0;
int main()
{
	n=read();
	for(ri i=1; i<=n; i++)
	{
		int h=read();

		person man=(person)
		{
			h,1
		};//��ǰ�����ڶ�����������������Լ�һ����
		while(!stk.empty()&&stk.top().h<=h)//�����ݼ�ջ�������������εݼ���
		{
			cnt+=stk.top().same;//ǰ���ж���������һ����
			if(stk.top().h==h)
			{
				man.same+=stk.top().same;
			}
			stk.pop();
		}
		if(!stk.empty())
		{
			cnt++;//the first person in the queue
		}
		stk.push(man);
	}
	return 0&printf("%lld",cnt);
}
