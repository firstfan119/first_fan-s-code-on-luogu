#include <bits/stdc++.h>
#define ri register int
using namespace std;
int maap[10][10];
int vis[101];
int pri[600]= {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241};
bool buc[300];
int n;
void init_prime()
{
	for(ri i=1; pri[i]>0; i++)
	{
		buc[pri[i]]=true;
	}
}
/*
bool is_prime(int x)
{
	int q=sqrt(x+0.5);
	for(ri i=2; i<=q; i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
*/
bool is_prime(int x)
{
	return buc[x];
}
bool dfs(int now,int i,int j,int ok)
{
	if(now>n*n)
	{
		return true;
	}
	for(ri a=2; a<=n*n; a++)
	{
		if(vis[a]==0)
		{
			if((i!=0&&!is_prime(a+maap[i-1][j]))||(j!=0&&!is_prime(a+maap[i][j-1])))
			{
				continue;
			}
			vis[a]=1;
			maap[i][j]=a;
			int now_i,now_j;
			int flg=ok;
			if(ok)
			{
				now_i=i,now_j=j+1;
				if(now_j>=n)
				{
					now_j=1;
					now_i++;
				}
			}
			else
			{
				now_i=i,now_j=j;
				if(now_i==0)
				{
					if((now_j+1)>=n)
					{
						now_i=1,now_j=0;
					}
					else
					{
						now_j++;
					}
				}
				else
				{
					if((now_i+1)>=n)
					{
						now_i=1,now_j=1;
						flg=1;
					}
					else
					{
						now_i++;
					}
				}
			}

			if(dfs(now+1,now_i,now_j,flg))
			{
				return true;
			}
			else
			{
				vis[a]=0;
				maap[i][j]=0;
			}
		}
	}
	return false;
}
int main()
{
	init_prime();
	scanf("%d",&n);
	vis[1]=1;
	maap[0][0]=1;
	if(n!=1&&dfs(2,0,1,0))
	{
		for(ri i=0; i<n; i++)
		{
			for(ri j=0; j<n; j++)
			{
				printf("%d",maap[i][j]);
				if(j!=n-1)
				{
					putchar(' ');
				}
			}
			if(i!=n-1)
			{
				putchar('\n');
			}
		}
	}
	else
	{
		printf("NO");
	}
	return 0;
}
