#include <iostream>
#include <algorithm>
using namespace std;
int n,d,a[100005],cnt=2,ans;
int main()
{
	cin>>n>>d;
    for(int i=1;i<=n;++i)
    {
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
    for(int i=1;i<n;++i)
	{
        while(cnt<=n&&a[cnt]-a[i]<=d)
        {
        	cnt++;
		}
        cnt--;
        ans+=cnt-i;
    }
    cout<<ans;
}
