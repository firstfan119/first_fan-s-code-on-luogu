#include<bits/stdc++.h>
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

const int maxn=500000;
int n,m;
int a1[50],a2[50];
int p,q;
int q1[maxn],q2[maxn],len1=0,len2=0;
int calc()
{
	for(int i=0; i<(1<<p); i++)
	{
		int t=0;
		for(int j=1; j<=p; j++)
		{
			if(i>>(j-1)&1)
			{
				t=(t+a1[j])%m;
			}
		}
		q1[++len1]=t;
	}
	for(int i=0; i<(1<<q); i++)
	{
		int t=0;
		for(int j=1; j<=q; j++)
		{
			if(i>>(j-1)&1)
			{
				t=(t+a2[j])%m;

			}
		}
		q2[++len2]=t;
	}
	sort(q1+1,q1+1+len1);
	sort(q2+1,q2+1+len2);
	int i=1,j=len2;
	int ans=0;
	for(int i=1; i<=len1; i++)
	{
		while(q1[i]+q2[j]>=m&&j>0)
		{
			j--;
		}
		if(j<=0)
		{
			break;
		}
		ans=max(q1[i]+q2[j],ans);
	}
	ans=max(ans,q1[p]+q2[q]);
	printf("%d\n",ans);
	return 20031125;
}
int main()
{
	n=read();
	m=read();
	p=n/2;
	q=n-p;
	for(int i=1; i<=p; i++)
	{
		a1[i]=read();
	}
	for(int i=1; i<=q; i++)
	{
		a2[i]=read();
	}
	return 0&calc();
}
