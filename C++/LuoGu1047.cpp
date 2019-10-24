#include <iostream>
using namespace std;
int main()
{
	int flag[100000];
	int tree_amount,area_amount;
	int remain_tree=0;
	cin>>tree_amount>>area_amount;
	for(int i=0;i<area_amount;i++)
	{
		int start,end;
		cin>>start>>end;
		for(int j=start;j<=end;j++)
		{
			flag[j]=1;
		}
	}
	for(int k=0;k<=tree_amount;k++)
	{
		if(!flag[k])
		{
			remain_tree++;
		}
	}
	cout<<remain_tree;	
}
