#include <bits/stdc++.h>
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
int main()
{
	int n,k;
	return 0&printf("%d",(n=read())+(k=read())-n%k);
}
