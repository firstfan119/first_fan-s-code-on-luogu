#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e7+7;
int res[maxn];
int we,th;
int main()
{
	char s;
	for(int i=1; cin>>s && s!='E'; i++)
	{
		if(s=='W')
		{
			res[i]=1;
		}
		else
		{
			res[i]=2;
		}
	}
	for(int i=1;; i++)
	{
		if(res[i]==1)
			we++;
		if(res[i]==2)
			th++;
		if(res[i]==0)
		{
			cout<<we<<":"<<th<<endl<<endl;
			break;
		}
		if(we-th>=2||th-we>=2)
		{
			if(we>=11||th>=11)
			{
				cout<<we<<":"<<th<<endl;
				we=0;
				th=0;
			}
		}
	}
	we=0;
	th=0;
	for(int i=1;; i++)
	{
		if(res[i]==1)
			we++;
		if(res[i]==2)
			th++;
		if(res[i]==0)
		{
			cout<<we<<":"<<th;
			break;
		}
		if(we-th>=2||th-we>=2)
		{
			if(we>=21||th>=21)
			{
				cout<<we<<":"<<th<<endl;
				we=0;
				th=0;
			}
		}
	}
	return 0;
}
