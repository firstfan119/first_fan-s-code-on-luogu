#include <iostream> 
using namespace std;
double a,s=10;//�����������Ǹ�ʲôfloor�ģ���ֻ���ø������ˡ���ʲô��ʲô����
int n,m=0,t=0,o=1,b;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        s-=a;
        if(s>10)s=10;//����ֵ����10�ͱ��10
        if(s<=0)break;//����
        t+=b;//�Ӿ���
    }
    while(t-o>=0)t-=o,m++,o*=2;//�۾���ӵȼ�
    cout<<m<<' '<<t;//���
    return 0;
}
