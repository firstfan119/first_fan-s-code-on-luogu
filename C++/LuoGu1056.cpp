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
	}//对输入的数据处理，计算分割各个位置可以获得的值，min是为了取两个坐标的最小（反正差值是1）以方便累计

	sort(a+1,a+1001,comp);
	sort(b+1,b+1001,comp);
	for(int z=1; z<=k; z++)
		as[z]=a[z].i;
	for(int z=1; z<=l; z++)
		bs[z]=b[z].i;//对x，y轴的两个结构体的值排序并转移到记录位置的数组
	sort(as+1,as+k+1);
	sort(bs+1,bs+l+1);
	for(int z=1; z<=k; z++)
		cout<<as[z]<<" ";
	cout<<endl;
	for(int z=1; z<=l; z++)
		cout<<bs[z]<<" ";
	cout<<endl;//对两个记录位置的数组进行升序排序然后输出
	return 0;
}
bool comp(seq i,seq j)
{
	return i.val>j.val;
}
