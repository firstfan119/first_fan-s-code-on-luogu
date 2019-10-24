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
int direx[4]= {-1,0,1,0};
int direy[4]= {0,1,0,-1};
char maap[15][15];
int x,y,X,Y;
int a=0;
int b=0;
int ans=0;
int main()
{
	memset(maap,'*',sizeof(maap));
	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=10; j++)
		{
			cin>>maap[i][j];
			if(maap[i][j]=='F')
			{
				x=i;
				y=j;
			}
			if(maap[i][j]=='C')
			{
				X=i;
				Y=j;
			}
		}
	}
	while(x!=X||y!=Y)
	{
		ans++;
		if(maap[x+direx[a]][y+direy[a]]=='*')
		{
			a=(a+1)%4;
		}
		else
		{
			x=x+direx[a];
			y=y+direy[a];
		}
		if(maap[X+direx[b]][Y+direy[b]]=='*')
		{
			b=(b+1)%4;
		}
		else
		{
			X=X+direx[b];
			Y=Y+direy[b];
		}
		if(ans>19260817)
		{
			return 0&puts("0");
		}
	}
	return 0&printf("%d",ans);
}
