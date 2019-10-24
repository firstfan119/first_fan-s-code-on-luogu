#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}

string s;
int f[1125][1125];
int ans=0;
int cnt=0;

int main()
{
	cin>>s;
	for(ri i=1; i<s.size(); i++)
	{
		if(s[i-1]>=s[i])
		{
			return 0&(int)puts("0");
		}
	}
	for(ri i=1; i<=26; i++)
	{
		f[i][1]=1;
	}
	for(ri j=2; j<=6; j++)
	{
		for(ri i=27-j; i>0; i--)
		{
			f[i][j]=f[i + 1][j-1] + f[i + 1][j];
		}
	}
	for(ri j=s.size()-1; j>=0; j--)
	{
		cnt++;
		for(ri i=1; i<=s[j]-'a' + 1; i++)
		{
			ans+=f[i][cnt];
		}
	}
	return 0&printf("%d",ans);
}
