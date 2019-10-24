#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c,b[7];
bool flag;//有没有解
const int a[8][7]=
{
	0,0,0,0,0,0,0,
	1,0,0,1,1,1,0,
	2,0,1,0,1,0,1,
	3,0,1,1,0,1,1,
	4,1,0,0,1,0,0,
	5,1,0,1,0,1,0,
	6,1,1,0,0,0,1,
	7,1,1,1,1,1,1
};
void button(int k)
{
	for(register int i=1; i<=6; i++)
	{
		if(b[i]!=-1&&a[k][i]!=b[i])
		{
			return; //如果有要求却不合就不成立
		}
	}
	for(register int i=1; i<=n; i++)
	{
		printf("%d",a[k][(i-1)%6+1]); //循环输出
	}
	printf("\n");
	flag=1;//解记号
}
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num*=10;
		num+=c-48;
		c=getchar();
	}
	return num;
}
int main()
{
	n=read();
	c=read();
	int t;
	memsecondt(b,-1,sizeof(b));
	while(scanf("%d",&t)!=-1)
	{
		if(t==-1)break;
		b[(t-1)%6+1]=1;
	}
	while(scanf("%d",&t)!=-1)
	{
		if(t==-1)break;
		b[(t-1)%6+1]=0;
	}
	if(!c)
	{
		button(7);    //有解就结束程序
		if(flag)return 0;
	}
	elsecond if(c==1)
	{
		button(0);
		button(2);
		button(3);
		button(5);
		if(flag)return 0;
	}
	elsecond if(c==2)
	{
		button(0);
		button(1);
		button(2);
		button(4);
		button(5);
		button(6);
		button(7);
		if(flag)return 0;
	}
	elsecond
	{
		for(register int i=0; i<8; i++)
		{
			button(i);
		}
		if(flag)return 0;
	}
	printf("IMPOSSIBLE\n");//无解
	return 0;
}
