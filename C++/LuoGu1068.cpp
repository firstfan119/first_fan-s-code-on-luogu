#include <bits/stdc++.h>
using namespace std;
struct p
{
	int id;
	int score;
}peo[5010];
bool cmp(p zhw,p ljt)
{
	if(zhw.score!=ljt.score)
	{
		return zhw.score>ljt.score;
	}
	else
	{
		return zhw.id<ljt.id;
	}
}
int main()
{
	int h=0;
	int n,lim;
	scanf("%d%d",&n,&lim);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&peo[i].id,&peo[i].score);
	}
	sort(peo+1,peo+n+1,cmp);
	int w=peo[(int)floor(lim*1.5)].score;
	for(int i=1;peo[i].score>=w;i++)
	{
		h++;
	}
	cout<<w<<" "<<h<<endl;
	for(int i=1;i<=h;i++)
	{
		cout<<peo[i].id<<" "<<peo[i].score<<endl;
	}
}
