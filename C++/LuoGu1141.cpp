#include<bits/stdc++.h>
using namespace std;
int f[1000005],h[1000005],n;//f[i]表示i节点的父节点,
//h[i]表示i节点及其子节点的连通块数
int st[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
char maap[1005][1005];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);   //查
}
void unionn(int x,int y)//并
{
	int r1=find(x),r2=find(y);
	if(r1!=r2)h[r1]+=h[r2],f[r2]=f[r1];
}
int dfs(int fi,int fj)
{
	if(f[fi*n+fj]!=-1)return find(fi*n+fj);
	f[fi*n+fj]=fi*n+fj,h[fi*n+fj]=1;//构造映射
	for(int k=0; k<4; k++)
	{
		int i=fi+st[k][0],j=fj+st[k][1];
		if(i>=0&&i<n&&j>=0&&j<n&&maap[fi][fj]!=maap[i][j])unionn(fi*n+fj,dfs(i,j));
	}
	return find(fi*n+fj);
}
int main()
{
	int ans[100010];
	int t;
	scanf("%d%d",&n,&t);
	memset(f,-1,4*n*n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",maap[i]);
	}
	int i,j;
	int cnnt=t;
	while(cnnt--)
	{
		scanf("%d%d",&i,&j);
		ans[cnnt]=h[dfs(i-1,j-1)];
		//printf("%d\n",h[dfs(i-1,j-1)]);
	}
	while(t--)
	{
		cout<<ans[t]<<endl;
	}
	return 0;
}
