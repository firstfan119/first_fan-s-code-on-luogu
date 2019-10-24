#include <iostream>
#include <algorithm>
using namespace std;
int num[105];
int cnt1=1,cnt2=0;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	sort(num,num+n);
	for(int i=0;i<n;i++)
	{
		if(num[i]==num[i+1])
		{
			num[i]=1001;
			cnt2++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!i)
		{
			cout<<n-cnt2<<endl;
		}
		if(i==n-1)
		{
			cnt1=0;
		}
		if(num[i]<=1000)
		{
			cout<<num[i];
			if(cnt1)
			cout<<" ";
		}
	}
}
