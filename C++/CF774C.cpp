#include <bits/stdc++.h>
#define ri register int
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

int main()
{
	int n=read();
	if(n%2==1)
	{
		n-=3;
		putchar('7');
	}
	n>>=1;
	for(ri i=1;i<=n;i++)
	{
		putchar('1');
	}
	return 0;
}//�������ֻ���ִ���ʵ�1��7�����֣�nΪżʱ��ȫ�����1���Ϊ��ʱ�����7��ѡ�
