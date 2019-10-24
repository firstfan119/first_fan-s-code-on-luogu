#include <iostream>
using namespace std;
int main() 
{
    int k,n=0;
    cin>>k;
    for(double res=0;res<=k;)
    {
    	n++;
    	res+=1.0/n;
	}
    cout<<n;
    return 0;
}
