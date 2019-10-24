#include<bits/stdc++.h>
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int main()
{
	int x,y,z,q,w,e;
	bool flag=false;
	scanf("%d%d%d",&x,&y,&z);
	do
	{
		q=a[1]*100+a[2]*10+a[3];
		w=a[4]*100+a[5]*10+a[6];
		e=a[7]*100+a[8]*10+a[9];
		if(q*y*z==w*x*z&&w*x*z==e*x*y&&q*y*z==e*x*y)
		{
			printf("%d %d %d\n",q,w,e);
			flag=true;
		}
	}
	while(next_permutation(a+1,a+10));
	if(!flag)
	{
		printf("No!!!");
	}
	return 0;
}
