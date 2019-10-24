#include <bits/stdc++.h>
using namespace std;

int m,n;
int a[101][101]= {{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1},{0,1,2}}; //预处理6种可能情况

int main()
{
	scanf("%d%d",&n,&m);
	n%=6;
	printf("%d",a[n][m]);
	return 0;
}
