#include <iostream>
using namespace std;
int main()
{
	int num[100000];
	int i=0,amount;
	do
	{
		cin>>num[i];
		i++;
	}while(num[i-1]);
	for(i=0;;i++)
	{
		if(!num[i])
		{
			amount=i;
			break;
		}
	}
	for(i=amount-1;i>=0;i--)
	{
		cout<<num[i]<<" ";
	}
}
