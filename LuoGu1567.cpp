#include <bits\stdc++.h>
using namespace std;
int main()
{
	int t[10000000];
	int N;
	int count=1,max=0;
	cin>>N;
	int i;
	for(i=0;i<N;i++)
	{
		cin>>t[i];
	}
	for(i=0;i<N;i++)
	{
		if(i)
		{
			if(t[i]>t[i-1])
			count++;
			if(t[i]<=t[i-1])
			{
				if(count>max)
				{
					max=count;
				}
				count=1;
			}
		}
	}
	cout<<max;
}
