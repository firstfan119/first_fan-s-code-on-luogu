#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
//�������˼�����
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

const int maxn=1e6+7;

int f[maxn];

struct object
{
	int u;
	int v;
	int w;
	friend bool operator<(object one,object two)
	{
		return one.w*two.v<one.v*two.w;
	}
} obj[maxn];

int main()
{
	int lim=read();
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		obj[i].u=read();
	}
	for(ri i=1;i<=n;i++)
	{
		obj[i].v=read();
	}
	for(ri i=1;i<=n;i++)
	{
		obj[i].w=read();
	}
	sort(obj+1,obj+n+1);
	int ans=0;
	for(ri i=1;i<=n;i++)
	{
		for(ri j=lim;j>=obj[i].w;j--)
		{
			f[j]=max(f[j],f[j-obj[i].w]+obj[i].u-j*obj[i].v);
			ans=max(ans,f[j]);
			//�Ҹ�һ������Ϊ���������
			//���Կ��԰ѹ�����ҲŪ��ȥ
			//��Ϊ������һ������ȴ𰸸��š�
		}
	}
	return 0&printf("%d",ans);
}

/*
74 1
502
2
47
out:
408
*/
