#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0;
int h[1000008];
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
	srand((time)(0));
	n=read();
	m=read();
	int l;
	int r;
	int mid;
	for(int i=1; i<=n; i++)
	{
		h[i]=read();
		r=max(r,h[i]);
	}
	while(l<=r)
	{
		mid=(l+r)/2;
		s=0;
		for(int i=1; i<=n; i++)
		{
			if(h[i]>mid)
			{
				s+=h[i]-mid;
			}
		}
		if(s<m)
		{
			r=mid-rand()%2;
		}
		else
		{
			l=mid+rand()%2;
		}
	}
	return 0&printf("%d",l-1);
}
