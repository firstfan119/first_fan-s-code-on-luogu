#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
char str[maxn];
int main()
{
	scanf("%s",str);
	putchar(str[0]);
	printf("%d",strlen(str)-2);
	putchar(str[strlen(str)-1]);
}
