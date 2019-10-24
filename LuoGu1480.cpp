#include <bits/stdc++.h>
#define ri register int
#pragma GCC optimize("O3")
using namespace std;
string a1,b1;
int a[100001],b[100001],res[100001],t[100001];
int cmp(int arr_1[],int arr_2[])
{
	if (arr_1[0]>arr_2[0]) return 1;
	if (arr_1[0]<arr_2[0]) return -1;
	for(ri i=arr_1[0]; i>0; i--)
	{
		if (arr_1[i]>arr_2[i]) return 1;
		if (arr_1[i]<arr_2[i]) return -1;
	}
	return 0;
}
void copyarray(int arr_1[],int arr_2[],int l)
{
	for(ri i=1; i<=arr_1[0]; i++) arr_2[i+l-1]=arr_1[i];
	arr_2[0]=arr_1[0]+l-1;
}
int main()
{
	cin>>a1>>b1;
	a[0]=a1.size();
	b[0]=b1.size();
	res[0]=a[0]-b[0]+1;
	for(ri i=1; i<=a[0]; i++)
	{
		a[i]=a1[a[0]-i]-48;
	}
	for(ri i=1; i<=b[0]; i++)
	{
		b[i]=b1[b[0]-i]-48;
	}
	for(ri i=res[0]; i>0; i--)
	{
		memset(t,0,sizeof(t));
		copyarray(b,t,i);
		while (cmp(a,t)>=0)
		{
			res[i]++;
			if (!cmp(a,t))
			{
				a[0]=0;
				continue;
			}
			for(ri i=1; i<=a[0]; i++)
			{
				if (a[i]<t[i])
				{
					a[i+1]--;
					a[i]+=10;
				}
				a[i]-=t[i];
			}
			while (a[0]>0&&!a[a[0]])
			{
				a[0]--;
			}
		}
	}
	while (res[0]>0&&!res[res[0]])
	{
		res[0]--;
	}
	if (!res[0])
	{
		cout<<0<<endl;
	}
	else
	{
		for(ri i=res[0]; i>0; i--)
		{
			cout<<res[i];
		}
	}
}
