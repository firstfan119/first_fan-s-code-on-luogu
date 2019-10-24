#include <iostream>
#include <cmath>
using namespace std;
int n;
bool vis=false;
bool judge(int a)
{
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin>>n;
	for(int j=4;j<=n;j+=2)
	{
		vis=false;
		for(int p=2;p<n;p++)
		{
			for(int q=2;q<n;q++)
			{
				if(judge(p)&&judge(q)&&(p+q==j))
				{
					cout<<j<<"="<<p<<"+"<<q<<endl;
					vis=true;
					break;
				}
			}
			if(vis==true)
			{
				break;
			}
		}
	}
}
