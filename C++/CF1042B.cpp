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

const int maxn=1125;
int f[10]={0,20031125,20031125,20031125,20031125,20031125,20031125,20031125,20031125,20031125};
//LOL
char ch[10];
int k[maxn],c[maxn];
int main()
{
	int n=read();
	for(ri i=1;i<=n;i++)
	{
		c[i]=read();
		scanf("%s",ch);
		int len=strlen(ch);
		for(ri j=0;j<len;++j)
		{
			k[i]|=(1<<(ch[j]-'A'));
		}
	}//��A,B,C�ֱ�Ϊ001,010,100,Ҫ��״̬Ϊ111
	for(ri i=0;i<n;i++)
	{
		for(ri j=7;j>=0;j--)
		{
			f[j|k[i+1]]=min(f[j|k[i+1]],f[j]+c[i+1]);
		}
	}//״ѹ˼��
	return 0&printf("%d\n",f[7]==20031125?-1:f[7]);
}
