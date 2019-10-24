#include<bits/stdc++.h>
#define db double
#define ri register int
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

int lcm(int x,int y)
{
	return x*y/__gcd(x,y);
}

int n,sum;

int m[25],r[25];

int main()
{
	n=read();
	int last=1;
	for(ri i=1;i<=16;i++)
    {
    	last=lcm(last,i);
    }
	for(int i=1; i<=n; i++)
	{
		m[i]=read();
	}
	for(int i=1; i<=n; i++)
	{
		r[i]=read();
	}
	for(int i=1; i<=last; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i%m[j]==r[j])
			{
				sum++;
				break;
			}
		}
	}
	return 0&printf("%.6lf",(db)sum/last);
}
