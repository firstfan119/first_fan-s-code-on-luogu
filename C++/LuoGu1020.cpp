#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=300005,INF=0x7ffffff;
int a[maxn],dp[maxn];
int cmp1(int a,int b)
{
	return a>=b;
}
int cmp2(int a,int b)
{
	return a>b;
}
int main()
{
	int n=-1;
	while(cin>>a[++n]);//完成输入，初始化n为-1是为了方便输入完成之后n刚好是数据的个数
	fill(dp,dp+n,-INF);//由于一开始要求的是不升子序列，因此将dp数组初始化为-INF
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp,dp+n,a[i],cmp1)=a[i];//将第一个满足d(k)<a[i]的d(k)更新成a[i]
	}
	cout<<lower_bound(dp,dp+n,-INF,cmp2)-dp<<endl;//这个当然可以直接倒着依次搜索，写成这样纯属娱乐。。。原理可以参照下面那个
	fill(dp,dp+n,INF);//求最长上升子序列的时候将dp初始化为INF
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp,dp+n,a[i])=a[i];//将第一个满足d(k)>=a[i]的d(k)更新成a[i]
	}
	cout<<lower_bound(dp,dp+n,INF)-dp<<endl;//本来我们是需要查找最靠后的一个满足d(k)<INF的k值，然后输出k+1，但是我们发现，其实这样输出的就是第一个等于INF的k值，因此直接查找INF即可
	return 0;
}
