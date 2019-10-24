#include <iostream>
using namespace std;
int k,cnt=0;
int main()
{
	cin>>k;
	for(int i=10000;i<=30000;i++)
	{
		int a=i/100;
		int b=(i-i/10000*10000)/10;
		int c=i-i/1000*1000;
		if((a%k==0&&b%k==0)&&c%k==0)
		{
			cout<<i<<endl;
			cnt++;
		}
	}
	if(!cnt)
	{
		cout<<"No"<<endl;
	}
}
