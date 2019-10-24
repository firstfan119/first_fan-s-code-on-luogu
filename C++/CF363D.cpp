#include<cstdio>
#include<vector>
#include<algorithm>

int check(const std::vector<int> &bgt,const std::vector<int> &cost,int money,int cnt)
{

	int n=bgt.size();
	int m=cost.size();
	if(cnt >m || cnt > n)
	{
		return -1;
	}

	int extra=0;
	int bgtSum=0;
	int tot=0;

	for(int p=0; p<cnt; p++)
	{
		tot +=cost[p];
		bgtSum +=(cost[p]<bgt[n-cnt+p])?cost[p]:bgt[n-cnt+p];
		extra +=(cost[p]<bgt[n-cnt+p])?0:(cost[p]-bgt[n-cnt+p]);
	}

	if(extra >money)
	{
		return -1;
	}
	if(tot<money)
	{
		return 0;
	}
	return (tot-money);
}


int main()
{

	int n,m,a;
	scanf("%ld%ld%ld",&n,&m,&a);

	std::vector<int> b(n,0);
	for(int p=0; p<n; p++)
	{
		scanf("%ld",&b[p]);
	}
	sort(b.begin(),b.end());

	std::vector<int> c(m,0);
	for(int p=0; p<m; p++)
	{
		scanf("%ld",&c[p]);
	}
	sort(c.begin(),c.end());

	int l(1),r((m<n)?m:n);
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		ans=check(b,c,a,mid);
		if(ans<0)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}

	ans=check(b,c,a,r);
	printf("%ld %ld\n",r,ans);

	return 0;
}
