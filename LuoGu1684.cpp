#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

ll read()
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

const int maxn=6666;
ll num[maxn];
ll f[maxn];
ll n;
int ch[6];
bool check(ll l,ll r)
{
	int digit=0;
	memset(ch,0,sizeof(ch));
	ch[4]=num[r];
	for(int i=l; i<r; i++)
	{
		digit++;
		ch[digit]=num[i];
		for(int j=l; j<r; j++)
		{
			if(i==j)
			{
				continue;
			}
			digit++;
			ch[digit]=num[j];
			for(int k=l; k<r; k++)
			{
				if(k==j||k==i)
				{
					continue;
				}
				digit++;
				ch[digit]=num[k];
				if(ch[1]==ch[2]&&ch[3]==ch[4])
				{
					return true;
				}
				if(ch[1]==ch[4]&&ch[2]==ch[3])
				{
					return true;
				}
				if(ch[1]==ch[3]&&ch[2]==ch[4])
				{
					return true;
				}
				digit--;
			}
			digit--;
		}
		digit--;
	}
	return false;
}
int main()
{
	n=read();
	for(int i=1; i<=n; i++)
	{
		num[i]=read();
	}
	f[0]=0;
	ll lst=1;
	for(int i=1; i<=n; i++)
	{
		//cout<<"yep";
		if(i-lst+1>=4)
		{
			if(check(lst,i))
			{
				f[i]=max(f[i],f[lst-1]+1);
				lst=i+1;
			}
			else
			{
				f[i]=f[i-1];
			}
		}
		else
		{
			f[i]=f[i-1];
		}
	}
	return 0&printf("%lld",f[n]);
}
