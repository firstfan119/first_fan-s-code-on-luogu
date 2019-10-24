#include <iostream>
long long n,m;
long  long l,r;
using namespace std;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>l>>r;
		if(l<1||l>m||r<1||r>m)
		{
			cout<<"Crossing the line";
			return 0;
		}
		for(int j=l;j<=r;j++)
		{
			for(int h=3;h<r;h++)
			{
			}
		}
	}
}
