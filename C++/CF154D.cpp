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

int dire=1;//��¼�ŷ����Ƿ�ת
int main()
{
	int x1=read();
	int x2=read();
	int dis=x2-x1;
	int a=read();
	int b=read();
	if(a<=0&&b<=0)//����
	{
		swap(a,b);
		a=-a;
		b=-b;
		dis=-dis;
		dire=-dire;//����
	}
	if(a<=0)//���
	{
		if(a<=dis&&dis<=b)
		{
			puts("FIRST");
			return 0&printf("%d",x2);
		}
		else//�ײ���һ���Ƶ�
		{
			return 0&(int)puts("DRAW");
		}
	}
	//���������
	//1.�����;���
	//2.��ת�����
	if(dis<0)//��ԯ����
	{
		return 0&(int)puts("DRAW");
	}
	else if(dis%(a+b)==0)
	{
		return 0&(int)puts("SECOND");
	}
	else if(a<=dis%(a+b)&&dis%(a+b)<=b)//��ʤ
	{
		puts("FIRST");
		return 0&printf("%d",x2-dire*(dis/(a+b))*(a+b));//��������ϡ�
	}
	else//ƽ��
	{
		return 0&(int)puts("DRAW");
	}
}
