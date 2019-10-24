#include<bits/stdc++.h>
#define d(i) (1<<(i))
using namespace std;

int n,N;
int f[100000][30];//(state,word_num)
string w[20];
int ans=-1;

int main()
{
	cin>>n;
	N=d(n)-1;
	for(int i=1; i<=n; i++)
	{
		cin>>w[i];
		f[1<<(i-1)][w[i][w[i].size()-1]-'A']=w[i].size();
	}
	for(int i=1; i<=(n>>2)+4; i++)//循环次数不必到n.
	{
		for(int j=1; j<=n; j++)
		{
			for(int s=0; s<=N; s++)
			{
				if(!(s & d(j-1)))
				{
					f[s + d(j-1)][w[j][w[j].size()-1]-'A']=max( f[s + d(j-1)] [w[j][w[j].size()-1]-'A'],(int)(f[s][w[j][0]-'A'] +w[j].size()));
					ans=max(ans,f[s + d(j-1)][w[j][w[j].size()-1]-'A']);
				}
			}
		}
	}
//state yasuo QwQ
	cout<<ans;
}
