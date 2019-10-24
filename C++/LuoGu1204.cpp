#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct events
{
	int sec;
	bool state;//true for start and false for end.
} ev[10005];
int st=0;
int n;
bool cmp(const events &a,const events &b)
{
	if(a.sec!=b.sec)
		return a.sec<b.sec;
	return a.state;
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&ev[2*i-1].sec);
		ev[2*i-1].state=true;
		scanf("%d",&ev[2*i].sec);
		ev[2*i].state=false;
	}
	sort(ev+1,ev+2*n+1,cmp);
	int ans[3]={0};
	int last=ev[1].sec;
	st++;
	
	for(int i=2; i<=2*n; i++)
	{
		if(ev[i].state==true)
		{
			if(st==0)
			{
				ans[2]=max(ans[2],ev[i].sec-last);
				
				last=ev[i].sec;
			}
			st++;
		}
		else
		{
			st--;
			if(st==0)
			{
				ans[1]=max(ans[1],ev[i].sec-last);
				
				last=ev[i].sec;
			}
		}
	}
	cout<<ans[1]<<" "<<ans[2]<<endl;
	return 0;
}
