#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[100010];
int q1[1010],q2[1010],len;

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

bool check(int x)
{
	int p=0,t=1;
	for(int i=1; i<=n; i++)
	{
		if(a[i]>x)return false;
		if(p+a[i]<=x)
		{
			p+=a[i];
		}
		else
		{
			p=a[i],t++;
		}
	}
	return t<=m;
}
int main()
{
	n=read();
	m=read();
	if(!m)
	{
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
		s+=a[i];
	}
	int l=0,r=s;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	int p=0,last=n;
	for(int i=n; i>=1; i--)
	{
		if(p+a[i]<=r)
		{
			p+=a[i];
		}
		else
		{
			q1[++len]=i+1;
			q2[len]=last;
			last=i;
			p=a[i];
		}
	}
	q1[++len]=1;
	q2[len]=last;
	for(int i=len; i>=1; i--)
	{
		cout<<q1[i]<<" "<<q2[i]<<endl;
	}
	return 0;
}
