#include <iostream>
using namespace std;
int main()
{
    long long n,distance=0;
    int x;
    cin>>x>>n;
    for(int i=0;i<n;i++)
    {
        if(x!=6&&x!=7)
        distance+= 250;
        if(x==7)
        x=1;
        else
        x++;
    }//模拟一周的运行 
    cout<<distance;
    return 0;
}
