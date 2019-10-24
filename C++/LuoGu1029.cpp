#include <bits/stdc++.h>
using namespace std;
int m,n,ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=sqrt(m*n);i++)
    {
        if(0==(n*m)%i&&__gcd(i,(n*m)/i)==n)  ans++;
    }
    cout<<(ans<<1);//最后乘以二是因为只遍历了一半
    return 0;
}
