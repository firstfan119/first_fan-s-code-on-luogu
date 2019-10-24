#include<bits/stdc++.h>
#define ri register int
#define ll long long
char f[255];
char s[1005];
int main()
{
	memset(f,0,sizeof(f));
	f['A']='A';
	f['H']='H';
	f['I']='I';
	f['M']='M';
	f['O']='O';
	f['T']='T';
	f['U']='U';
	f['V']='V';
	f['W']='W';
	f['X']='X';
	f['Y']='Y';
	f['b']='d';
	f['d']='b';
	f['o']='o';
	f['p']='q';
	f['q']='p';
	f['v']='v';
	f['w']='w';
	f['x']='x';
	scanf("%s",s);
	for (ri i=0;i<=(signed)strlen(s)-i-1;i++)
	{
		if(f[s[i]]!=s[strlen(s)-i-1])
		{
			puts("NIE");
			return 0;
		}
	}
	puts("TAK");
}
