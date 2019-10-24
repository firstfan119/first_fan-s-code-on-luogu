#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
int buc[666];//bucket

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

int main()
{
	int F=read();
	int I=read();
	int T=read();
	for(int i=1; i<=F; i++)
	{
		for(int j=1; j<=I; j++)
		{
			char c;
			scanf(" %c",&c);
			if(c=='Y')
			{
				buc[j]++;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=I; i++)
	{
		if(buc[i]>=T)
		{
			ans++;
		}
	}
	return 0&printf("%d",ans);
}
