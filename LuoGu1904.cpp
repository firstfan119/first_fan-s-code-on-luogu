#include<bits/stdc++.h>
#define pyh 20031125
using namespace std;
int h[pyh],_right=-pyh,_left=pyh;

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

int main()
{
	int l,H,r;
	while(cin>>l>>H>>r)
	{
		_left=min(_left,l);
		_right=max(_right,r);
		for(int i=l; i<r; i++)
		{
			h[i]=max(h[i],H);
		}
	}
	for(int i=_left; i<_right; i++)
	{
		if(h[i]!=h[i-1])
		{
			printf("%d %d ",i,h[i]);
		}
	}
	return 0&printf("%d %d\n",_right,0);
}
