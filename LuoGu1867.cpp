#include <iostream> 
using namespace std;
double a,s=10;//由于忘记了那个什么floor的，就只能用浮点数了。（什么跟什么啊）
int n,m=0,t=0,o=1,b;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        s-=a;
        if(s>10)s=10;//生命值大于10就变成10
        if(s<=0)break;//死了
        t+=b;//加经验
    }
    while(t-o>=0)t-=o,m++,o*=2;//扣经验加等级
    cout<<m<<' '<<t;//输出
    return 0;
}
