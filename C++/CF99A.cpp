#include<bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

int main()
{
	string s;
	gets(cin, s);
	int dot=s.find('.');
	string s1=s.substr(0,dot);//整数部分
	char fst=s[dot+1];//小数点后第一位
	if(s1[dot-1]=='9')
	{
		s1="GOTO Vasilisa.";
	}
	else if(fst-='5')
	{
		++s1[dot-1];
	}
	cout<<s1<<endl;
}
