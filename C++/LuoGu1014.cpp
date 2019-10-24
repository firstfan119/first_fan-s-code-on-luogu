#include <bits/stdc++.h>
using namespace std;
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=num*10+c-48;
		c=getchar();
	}
	return num;
}
int main()
{
	int n=read(), i=0, j=0;
	for(;j<n;)
	{
		i++;
		j+=i;
	}
	return 0 & ( i % 2? printf("%d/%d",j-n+1,i+n-j) : printf ("%d/%d" , i+n-j , j-n+1 ) );
}
