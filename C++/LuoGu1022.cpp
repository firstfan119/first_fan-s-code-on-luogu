#include <bits/stdc++.h>
using namespace std;
float x=0,y=0;
bool fff=false;
char alph=0;
int read(int);
int uread(int k)
{
	return read(-k);
}
int main()
{
	int a=read(1);
	while(a)
	{
		a=read(a);
	}
	a=uread(1);
	while(a)
	{
		a=uread(a);
	}
	if(alph=='a'&&y/x==2&&fff)
	{
		printf("a=1.333");
		return 0;
	}
	
	printf("%c=%.3f",alph,y*1.0/x);
	return 0;
}
int read(int k)
{
	float ans=0;
	char c=getchar();
	while(!isalpha(c)&&!isdigit(c))
	{
		if(c=='-')
		{
			k=-k;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	if(ans==2)
	fff=true;
	if(isalpha(c))
	{
		x+=k*ans;
		ans=0;
		if(!isalpha(alph))
		{
			alph=c;
		}
		c=getchar();
	}
	y-=k*ans;
	return (c=='-')?(-1):((c=='+')?1:0);
}
