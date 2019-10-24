#include<bits/stdc++.h>
#define ri register int
using namespace std;
int read()
{
	register int num=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);//learnt from yls
		c=getchar();
	}
	return num*flg;
}
int main()
{
	ri n;
	cin>>n;
	string s[17]= {"0","2(0)","2","2(2)","2(2+2(0))","2(2(2))","2(2(2)+2(0))","2(2(2)+2)","2(2(2)+2+2(0))","2(2(2+2(0)))","2(2(2+2(0))+1)","2(2(2+2(0))+2)","2(2(2+2(0))+2+2(0))","2(2(2+2(0))+2(2))","2(2(2+2(0))+2(2)+2(0))","2(2(2+2(0))+2(2)+2)","2(2(2+2(0))+2(2)+2+2(0))"};
	bool temp=0;
	for(ri i=15; i>=0; i--)
	{
		if(pow(2,i)<=n)
		{
			n-=pow(2,i);
			if(temp)cout<<'+';
			cout<<s[i+1];
			temp=1;
		}
	}
}
