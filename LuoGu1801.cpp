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
	priority_queue<int>down;//���������
	priority_queue<int,vector<int>,greater<int> >up;//С��������
	//��֤����ѶѶ�ΪС���Ѷѵ�
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
			if(down.size()==i)//�������ֻʣi��Ԫ�أ��������е�i��
			{
				up.push(down.top());
				down.pop();
			}//���ϴεĶϵ�λ�ÿ�ʼ��ѯ��λ��,
			//������ĶѶ�ȡ������ĶѶ�.
		}
		last=pos+1;//�ϵ��¼
		printf("%d\n",up.top());//ȡ��

		down.push(up.top());
		up.pop();
		//������ĶѶ�ȡ������ĶѶ�.
	}
}
