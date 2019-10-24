#include <bits/stdc++.h>
#define ri register int
#define ll long long
#define db double
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

struct node
{
	int x;
	int y;
	int r;
} nd[3];

int direx[]= {-1,0,0,1};
int direy[]= {0,1,-1,0};

db nd_tmp[3];

db calc(db x,db y)
{
	for(ri i=0; i<3; i++)
	{
		nd_tmp[i]=sqrt(pow(x-nd[i].x,2)+pow(y-nd[i].y,2))/nd[i].r;
	}
	db res=0.0;
	for(ri i=0; i<3; i++)
	{
		res+=pow(nd_tmp[i]-nd_tmp[(i+1)%3],2);
	}
	return res;
}

int main()
{
	db x=0.0;
	db y=0.0;
	for(ri i=0; i<3; i++)
	{
		nd[i].x=read();
		nd[i].y=read();
		nd[i].r=read();
		x+=nd[i].x;
		y+=nd[i].y;
	}
	x/=3.0;
	y/=3.0;
	db step=1.0;

	db err=calc(x,y);
	db res_x=-1;
	db res_y=-1;
	while (step>1e-6)
	{
		int t=-1;
		for(ri i=0; i<4; i++)
		{
			db nx=x+direx[i]*step;
			db ny=y+direy[i]*step;
			db temp_err=calc(nx,ny);
			if (temp_err<err)
			{
				err=temp_err;
				t=i;
				res_x=nx;
				res_y=ny;
			}
		}
		if (t==-1)
		{
			step/=2;
		}
		else
		{
			x+=direx[t]*step;
			y+=direy[t]*step;
		}
	}
	if (err<1e-6)
	{
		printf("%.5lf %.5lf\n",res_x,res_y);
	}
}
/*
0 0 10
60 0 10
30 30 10
out:
30.00000 0.00000
*/
