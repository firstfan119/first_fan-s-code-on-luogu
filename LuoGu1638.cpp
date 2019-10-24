#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,M=2e3+10;
int aen=0x7fffffff;
int a,b;
int pos[M];
int pic[N],l=1,cnt=0;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(pos,-1,sizeof(pos));
	for(int i=1; i<=n; i++)
	{
		cin>>pic[i];
		if(pos[pic[i]]==-1)
		{
			cnt++; // 如果没有出现，统计+1
		}
		pos[pic[i]]=i; // 更新位置
		while(l!=i && l<pos[pic[l]])
		{
			l++; // 更新左端点
		}
		if(cnt==m && i-l+1<aen)
		{
			aen=i-l+1;
			a=l;
			b=i;
		}
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}
