#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
int a[10001];  //��¼��ѡ����
int n,k,sum,tot;  //totalΪ�ܷ�����
void print()  //��ӡ���������ո���ϰ�ߣ�
{
    printf("%d",tot);
}
bool isprime(int x)  //�����ж�
{
    for(register int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}
inline void dfs(int step,int sum,int cnt)
{
    if(step==n+1||cnt==k)  //����Ѿ����е���n+1�Σ��������Ѿ�ѡ��k����
    {
        if(isprime(sum) && cnt==k)  //���sumΪһ���������Ѿ�ѡ��k����
            tot++;  //�ܷ�����+1
        return;  //����
    }
    dfs(step+1,sum+a[step],cnt+1);  //����������ѡ����һ����
    dfs(step+1,sum,cnt);  //����ö�ٲ�ѡ����һ���������
    return;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(register int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1,0,0);  //�ӵڸ�����ʼ��
    print();  //����ӡ���
    return 0;
}
