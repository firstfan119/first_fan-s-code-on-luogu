#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int direx[]= {-1,0,1,0};
int direy[]= {0,-1,0,1};
int maap[105][105];
void dfs(int x,int y)
{
	maap[x][y]=0;//标记为没有
	for (int i=0; i<4; i++) {
		int x_now=x+direx[i];
		int y_now=y+direy[i];
		if (maap[x_now][y_now]&&x_now>=1&&y_now>=1&&x_now<=n&&y_now<=m)
		{
			dfs(x+direx[i],y+direy[i]);
		}
	}//如果有才搜
}//搜索
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) {
			scanf("%1d",&maap[i][j]);
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (maap[i][j])
			{
				cnt++;
				dfs(i,j);
			}
		}//找
	}
	printf("%d",cnt);//输出
	return 0;
}
