#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10;
int n,m,dis[maxn][maxn],s1=maxn,ans;
char ru[maxn],a[maxn];
void out()
{
	for(int i=ans; i>=1; i--)
		printf("%c",a[i]);
	cout<<endl;
}
void find(int i)
{
	for(int j=1; j<='z'+5; j++)
		if(dis[i][j]>0)
		{
			dis[i][j]--;
			dis[j][i]--;
			find(j);
		}
	a[++ans]=i;
	return ;
}
int main()
{
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		string s;
		cin>>s;
		dis[s[0]][s[1]]++;
		dis[s[1]][s[0]]++;
		ru[s[0]]++;
		ru[s[1]]++;
	}
	int cnt=0,h=0;
	for(int i=1; i<='z'+5; i++)
		if(ru[i]&1)
		{
			cnt++;
			if(!h)h=i;
		}
	if(!h)
		for(int i=0; i<'z'+5; i++)
			if(ru[i])
			{
				h=i;
				break;
			}
	if(cnt&&cnt!=2)
	{
		cout<<"No Solution";
		return 0;
	}
	find(h);
	if(ans<m+1)
	{
		cout<<"No Solution";
		return 0;
	}
	out();
	return 0;
}

