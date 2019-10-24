#include<cstdio>
#define yls int n,now,sum,maxx; scanf("%d%d",&n,&maxx); sum=maxx; for(int i=1; i<n; i++){scanf("%d",&now);if(sum<0){sum=0;}sum+=now;if(sum>maxx){maxx=sum;}}
#define tql printf("%d",maxx);
int main()
{
	yls tql;
}
