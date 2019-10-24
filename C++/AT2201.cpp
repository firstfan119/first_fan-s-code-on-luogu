#include<bits/stdc++.h>
#define ri register int
using namespace std;
int main()
{
	string str;
	cin>>str;
	string tmp=str;
	reverse(tmp.begin(),tmp.end());
	for(int i=0; i<tmp.size(); i++)
	{
		switch(tmp[i])
		{
			case 'b':
			{
				tmp[i]='d';
				break;
			}
			case 'd':
			{
				tmp[i]='b';
				break;
			}
			case 'p':
			{
				tmp[i]='q';
				break;
			}
			case 'q':
			{
				tmp[i]='p';
				break;
			}
		}
	}
	return 0&(int)printf("%s",tmp==str?"Yes":"No");
}
