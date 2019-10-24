#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int maxn=1e5;

char s[maxn+2];
char t[maxn+2];
int ch[maxn+1][26];
int fail[maxn+1];

int main()
{
	scanf("%s %s",s+1,t+1);

	int n=strlen(s+1);
	int m=strlen(t+1);
	//其实此处可以加一个组合数优化
	//如全部都是问号就可以特判组合数过，当然离线可以O(1)
	//在线其实就是下面的dp过程。
	
	for(ri i=1; i<=m; i++)
	{
		ch[i-1][t[i]-'a']=i;
	}//trans
	for(ri i=1,k=0; i<=m; i++)
	{
		if(i>1)
		{
			while(k&&t[k+1]!=t[i])
			{
				k=fail[k];
			}
			if(t[k+1]==t[i])
			{
				fail[i]=++k;
			}
			else
			{
				fail[i]=0;
			}
		}
		for(ri j=0; j<26; j++)
		{
			if(!ch[i][j])
			{
				ch[i][j]=ch[fail[i]][j];
			}
		}
	}//类AC自动机匹配
	vector<vector<int> >f(n+1,vector<int>(m+1,-1));
	f[0][0]=0;
	for(ri i=0; i<n; i++)
	{
		for(ri j=0; j<=m; j++)
		{
			if(f[i][j]==-1)
			{
				continue;
			}
			for(ri c=s[i+1]=='?'?0:(s[i+1]-'a'); c <(s[i+1]=='?'?26:(s[i+1]-'a'+1)); c++)
			{
				f[i+1][ch[j][c]]=max(f[i+1][ch[j][c]],f[i][j] +(ch[j][c]==m));
			}//?可以匹配任意字符，dp
		}
	}
	priority_queue<int> q;
	for(ri i=0; i<=m; i++)
	{
		q.push(f[n][i]);
	}
	printf("%d\n",q.top());
}//取f[n][?]中的最大匹配数

/*
Sample:
glo?yto?e??an?
or
out:
3
(glory toreoran)

Sample:
??c?????
abcab
out:
2
(abcab abcab)
*/
