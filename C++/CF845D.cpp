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
			}//�ı��ٶ�
			case 2:
			{
				cnt+=over;
				over=0;
				break;
			}//����
			case 3:
			{
				lim=read();
				s.push(lim);
				break;
			}//����
			case 4:
			{
				over=0;
				break;
			}//������
			case 5:
			{
				stack<ll>Void;
				swap(Void,s);
				break;
			}//ȡ������
			default://6
			{
				over++;
				break;
			}//��ֹ����
		}
		while(s.size()&&s.top()<speed)
		{
			s.pop();
			cnt++;
		}
	}
	return 0&printf("%d",cnt);
}
