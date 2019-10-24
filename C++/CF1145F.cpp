#include<bits/stdc++.h>
#define ri unsigned register int
using namespace std;
int alp[26]= {1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1};
int flg=0;
int bent_flg=0;
char ch[6666666];
int main()
{
	scanf("%s",ch);
	for(ri i=0; i<strlen(ch); i++)
	{
		if(alp[ch[i]-'A']==1)
		{
			flg=1;//有直的
		}
		else
		{
			bent_flg=1;//有弯的
		}
	}
	return 0&(flg+bent_flg==1?printf("YES"):printf("NO"));
}
