#include<iostream>
#include<algorithm>
using namespace std;
struct seq
{
	int i,val;
} a[1010],b[1010];
int n,m,k,l,d,as[1010],bs[1010];
int x1,y1,x2,y2;
bool comp(seq,seq);
int main()
{
	cin>>n>>m>>k>>l>>d;
	for(int z=1; z<=1010; z++)
		a[z].i=b[z].i=z;
	for(int z=1; z<=d; z++)
	{
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2)
			b[min(y1,y2)].val++;
		if(y1==y2)
			a[min(x1,x2)].val++;
	}//����������ݴ�������ָ����λ�ÿ��Ի�õ�ֵ��min��Ϊ��ȡ�����������С��������ֵ��1���Է����ۼ�

	sort(a+1,a+1001,comp);
	sort(b+1,b+1001,comp);
	for(int z=1; z<=k; z++)
		as[z]=a[z].i;
	for(int z=1; z<=l; z++)
		bs[z]=b[z].i;//��x��y��������ṹ���ֵ����ת�Ƶ���¼λ�õ�����
	sort(as+1,as+k+1);
	sort(bs+1,bs+l+1);
	for(int z=1; z<=k; z++)
		cout<<as[z]<<" ";
	cout<<endl;
	for(int z=1; z<=l; z++)
		cout<<bs[z]<<" ";
	cout<<endl;//��������¼λ�õ����������������Ȼ�����
	return 0;
}
bool comp(seq i,seq j)
{
	return i.val>j.val;
}
