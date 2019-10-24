#include <bits/stdc++.h>
#define  ri register int
using namespace std;
int n,a[1030];
int read()
{
	a[0]=1;//我也不知道为什么放在这里，因为我喜欢吧……
	ri num=0;
	ri flg=1;
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
	n=read();
	for(ri i=0; i<1<<n; ++i)
	{
		for(ri j=1; j<(1<<n)-i; ++j)
		{
			putchar(' ');
		}
		for(ri j=i; j>=0; --j)
		{
			a[j]^=a[j-1];
		}
		if(!(i%2))
		{
			for(ri j=0; j<=i; ++j)
			{
				cout<<(a[j]?"/\\":"  ");
			}
		}
		else
		{
			for(ri j=0; j<=i; j+=2)
			{
				cout<<(a[j]?"/__\\":"    ");
			}
		}
		cout<<endl;
	}
}
