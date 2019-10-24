#include <bits/stdc++.h>
using namespace std;
int rong[100000];
int ci[100000];
int main()
{
    memset(rong,-1,100000*4);
    int m,n,l,r,sum=0,temp;
    cin>>m>>n;
    l=1;r=m;temp=m+1;
    for(int k=1;k<=n;k++)
    cin>>ci[k];

    for(int k=1;k<=n;k++)
        for(int a=l;a<=r;a++)
        {
            if(rong[a]==ci[k])
            break;
            if(a==r&&rong[r]!=ci[k])
            {
                sum++;
                rong[temp]=ci[k];
                temp++;
                l++;
                r++;
                
            }
        }
        cout<<sum;
        return 0;
}
