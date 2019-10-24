#include<bits/stdc++.h>
#define end '@'
using namespace std;
int num[1001];
int top=0;
void push(int s)
{
	num[++top]=s;
}
void pop(char p)
{
	int s1;
	switch(p)
	{
		case '+':
			s1=num[top-1]+num[top];
			break;
		case '-':
			s1=num[top-1]-num[top];
			break;
		case '*':
			s1=num[top-1]*num[top];
			break;
		case '/':
			s1=num[top-1]/num[top];
			break;
	}
	top-=2;
	push(s1);
}
int main()
{
	char p;
	int s=0;
	while(1)
	{
		p=getchar();
		if(p==end)
			break;
		else if(p>='0'&&p<='9')
		{
			s*=10;
			s+=p-'0'+0;
		}
		else if(p=='.')
		{
			push(s);
			s=0;
		}
		else
			pop(p);
	}
	printf("%d",num[top]);
	return 0;
}
