#include <bits/stdc++.h>
using namespace std;
int t,ax,ay,bx,by;
inline int abs(int a){return a<0?-a:a;}
int gcd(int x,int y){return y?(x%y?gcd(y,x%y):y):-1;}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&ax,&ay,&bx,&by);
        if(gcd(abs(ax-bx),abs(ay-by))==1)printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
