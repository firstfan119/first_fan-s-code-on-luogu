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
    cout<<(ans<<1);//�����Զ�����Ϊֻ������һ��
    return 0;
}
