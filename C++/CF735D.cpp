#include<bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

bool isprime(int num)
{
	if(num==2||num==3)
	{
		return true;
	}
	if(num%6!=1&&num%6!=5)
	{
		return false;
	}
	for(ri i=5; i*i<=num; i+=6)
	{
		if(num%i==0||num%(i+2)==0)
		{
			return false;
		}
	}
	return true;
}

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
	int num=read();
	if(isprime(num))
	{
		return 0&printf("1");
		//�������������ô������Ӽ���1��ֻ��Ϊ���˰��
	}
	else if(isprime(num-2)||num%2==0)
	{
		return 0&printf("2");
		//������Ӻ�2,��Сֻ�ܲ�2����ô��С˰ǮΪ2
	}
	else
	{
		return 0&printf("3");
		//��Ȼ��һ���а취����С˰Ǯ����3
	}
}
