#include<bits/stdc++.h>
#define ll long long
#define ri register int
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

const int mod=1e8;

ll n,m;
struct mat
{
	int row;
	int col;
	int u[5][5];
};
mat mul(mat x,mat y)
{
	mat t;
	memset(&t,0,sizeof(t));
	for(int i=0; i<x.row; i++)
	{
		for(int j=0; j<y.col; j++)
		{
			for(int k=0; k<x.col; k++)
			{
				t.u[i][j]=(t.u[i][j]+x.u[i][k]*y.u[k][j])%mod;
			}
		}
	}
	t.row=x.row;
	t.col=y.col;
	return t;
}

int ans=0;
void solve(ll ind)
{
	mat t;
	mat res;
	memset(&t,0,sizeof(t));
	memset(&res,0,sizeof(res));
	t.row=t.col=2;
	t.u[0][0]=t.u[0][1]=t.u[1][0]=1;
	//	|1 1|
	//	|1 0|->¹¹Ôì¾ØÕó
	res.row=1;
	res.col=2;
	res.u[0][0]=res.u[0][1]=1;
	while(ind)
	{
		if(ind&1)
		{
			res=mul(res,t);
		}
		t=mul(t,t);
		ind>>=1;
	}
	ans=res.u[0][0];
}
int main()
{
	n=read();
	m=read();
	n=__gcd(n,m);
	if(n<=2)
	{
		return 0&printf("%d",1);
	}
	solve(n-2);
	return 0&printf("%d",ans);
}
