#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define int ll
using namespace std;

const long pri[66]= {0 ,2 ,3 ,5 ,7 ,11 ,13 ,17 ,19 ,23 ,
                   29 ,31 ,37 ,41 ,43 ,47 ,53 ,59 ,61 ,67 ,
                   71 ,73 ,79 ,83 ,89 ,97 ,101,103,107,109,
                   113,127,131,137,139,149,151,157,163,167,
                   173,179,181,191,193,197,199,211,223,227,
                   229,233,239,241,251,257,263,269,271,277,
                   281,283,293,307,311,313
                  };

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

void mul(ll a[1000],ll n)
{
	long i;
	for(ri i=1; i<=a[0]; i++)
	{
		a[i]=a[i]*n;
	}
	for(ri i=1; i<a[0]; i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]]>9)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]]%=10;
		a[0]++;
	}
	if(a[0]>101)
	{
		a[0]=101;
	}
}

signed main()
{
	ll h[200000],nn,mm,ans[1000];
	int n=read();
	int m=read();
	int tot=n+m;
	memset(h,0,sizeof(h));
	for(ri i=n+1; i<=tot; i++)
	{
		nn=i;
		for(ri j=1; j<=65; j++)
		{
			while(nn%pri[j] == 0)
			{
				h[pri[j]]++;
				nn/=pri[j];
				if(nn==1)
				{
					break;
				}
			}
			if(nn==1)
			{
				break;
			}
		}
		if(nn!=1)
		{
			h[nn]++;
		}
	}
	for(ri i=1; i<=m; i++)
	{
		mm=i;
		for(ri j=1; j<=65; j++)
		{
			while(mm%pri[j]==0)
			{
				h[pri[j]]--;
				mm/=pri[j];
				if(mm==1)
				{
					break;
				}
			}
			if(mm==1)
			{
				break;
			}
		}
		if(mm!=1)
		{
			h[mm]--;
		}
	}
	ans[0]=1;
	ans[1]=1;
	for(ri i=1; i<=100000; i++)
	{
		while(h[i]>0)
		{
			mul(ans,(ll)i);
			h[i]--;
		}
	}
	for(ri i=100; i>=1; i--)
	{
		printf("%ld",ans[i]);
		if(i%10==1)
		{
			printf("\n");
		}
	}
}
