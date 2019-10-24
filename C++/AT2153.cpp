#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	return 0&(int)printf("%s",((s[0]==s[s.length()-1])^(s.length()%2))?"First":"Second");
}
