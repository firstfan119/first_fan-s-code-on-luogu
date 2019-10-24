#include <iostream>
using namespace std;
int main()
{
	int height[10],tao,count=0;
	for(int i=0;i<10;i++)
	{
		cin>>height[i];
	}
	cin>>tao;
	tao+=30;
	for(int j=0;j<10;j++)
	{
		if(tao>=height[j])
		{
			count++;
		}
	}
	cout<<count;
}
