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

int maap[10];
int f[10];

bool flg;
void loop(int cur)
{
	if(cur>9)
	{
		if((f[1]+f[2]+f[4])%4==maap[1]&&(f[1]+f[2]+f[3]+f[5])%4==maap[2]&&(f[2]+f[3]+f[6])%4==maap[3]&&(f[1]+f[4]+f[5]+f[7])%4==maap[4]&&(f[1]+f[3]+f[5]+f[7]+f[9])%4==maap[5]&&(f[3]+f[5]+f[6]+f[9])%4==maap[6]&&(f[4]+f[7]+f[8])%4==maap[7]&&(f[5]+f[7]+f[8]+f[9])%4==maap[8]&&(f[6]+f[8]+f[9])%4==maap[9])
		{
			flg=true;
		}
		return;
	}
	for(f[cur]=0; f[cur]<=3; f[cur]++)
	{
		loop(cur+1);
		if(flg)
		{
			return;
		}
	}
}
int main()
{
	for(ri i=1; i<=9; i++)
	{
		maap[i]=(4-read()/3)%4;
	}
	loop(1);
	for(ri i=1; i<=9; i++)
	{
		for(ri j=1; j<=f[i]; j++)
		{
			printf("%d ",i);
		}
	}
}
