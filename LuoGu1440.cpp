#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct _queue
{
	int val;
	int id;
} q[maxn];
int head=0,tail=0;
////q[i][0]��ʾֵ�� q[i][1]��ʾ��ԭ��˳���λ��
int main()
{
	int n=read();
	int m=read();
	printf("0\n");
	scanf("%d", &q[tail].val);
	tail++;
	for(int i=1; i<n; i++)
	{
		if(i-q[head].id>m) head++;
		printf("%d\n", q[head].val); //�������Ԫ�أ���С��
		int x=read();
		while(tail>head&&x<q[tail-1].val)
			tail--;
		q[tail].val=x;
		q[tail].id=i; //��ǰ��������
		tail++;
	}
	return 0;
}
