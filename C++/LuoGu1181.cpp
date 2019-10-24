#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;
int n,lim;
int num[maxn];
ll bucket=0,cnt=1;
int main()
{
　　cin>>n>>lim;
　　for(int i=1; i<=n; i++)
　　{
　　　　cin>>num[i];
　　　　if(bucket+num[i]>lim)
　　　　{
		　　bucket=0;
		　　cnt++;
　　　　}
　　　　bucket+=num[i];
　　}
　　cout<<cnt;
}
