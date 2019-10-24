#include <bits\stdc++.h>
using namespace std;
int main()
{
	long long n,a[100005],temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n-j-1;k++)
		{
			if(a[k]>a[k+1])
			{
				temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	for(int m=0;m<n;m++)
	{
		cout<<a[m]<<" ";
	}
}
