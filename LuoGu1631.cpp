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
priority_queue<int> q;
int n;
int a[maxn],b[maxn];
int ans[maxn];

int main()
{
	int n=read();
	for (ri i=1; i<=n; i++)
	{
		a[i]=read();
	}
	for (ri i=1; i<=n; i++)
	{
		b[i]=read();
	}
	//��������
	for (ri i=1; i<=n; i++)
	{
		q.push(a[1]+b[i]);
	}
	//�ȴ���ף���֤�����ǶԵ�
	//��ʱ��߼ӱߵ��������ȶ���
	for (ri i=2; i<=n; i++)
	{
		for (ri j=1; j<=n; j++)
		{
			int val=a[i]+b[j];
			if (val<q.top())
			{
				q.push(val);
				q.pop();
			}
			else
			{
				break;
			}
		}
	}
	for (ri i=1; i<=n; i++)
	{
		ans[i]=q.top();
		q.pop();
	}
	for (ri i=n; i>=1; i--)
	{
		printf("%d ",ans[i]);
	}//Ҫ����priority_deque�ö�á�
}
