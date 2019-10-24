#include <iostream>
using namespace std;
int main()
{
	int cute[1000];
	int count[1000];
	for(int h=0;h<1000;h++)
	{
		count[h]=0;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>cute[i];
	}
	for(int j=0;j<n;j++)
	{
		for(int m=0;m<j;m++)
		{
			if(cute[m]<cute[j])
			count[j]++;
		}
	}
	for(int k=0;k<n;k++)
	{
		cout<<count[k]<<" ";
	}
}
