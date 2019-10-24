#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int s;
    cin>>s;
    for(int i=s;i;i++)
	{
        int a=0,b=0;
        int z=sqrt(i);
        for(int j=2;j<z;j++)
            if(i%j==0)
                a+=j+i/j;
        if(i%z==0)
            a+=z;
        a++;
        int p=sqrt(a);
        for(int j=2;j<p;j++)
            if(a%j==0)
                b+=j+a/j;
        b++;
        if(b==i&&i!=a)
		{
		           cout<<i<<' '<<a;
            return 0;
        }
    }
}
