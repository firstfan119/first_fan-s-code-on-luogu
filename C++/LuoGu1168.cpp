//写个vector应该没人打我吧……
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

int u_b(int *arr,int size,int key)
{
	int l=0;
	int r=size-1;
	int mid, pos=0;

	while(l<r)
	{
		int mid=(l+r)/2;
		if(arr[mid]>key)
		{
			r=mid;
			pos=r;
		}
		else
		{
			l=mid+1;
			pos=l;
		}
	}
	return pos;
}//为了代码礼仪，还是手打一个在这里。

vector<int>v;
int main()
{
	int n=read();
	for(ri i=1,x; i<=n; i++)
	{
		int val=read();
		v.insert(upper_bound(v.begin(),v.end(),val),val);
		if(i%2)
		{
			printf("%d\n",v[(i-1)>>1]);
		}
	}
}
/*
7
1 3 5 7 9 11 6
out:
1
3
5
6
*/
