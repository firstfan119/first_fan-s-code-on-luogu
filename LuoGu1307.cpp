#include <iostream>
using namespace std;
int n,res;
int main()
{
    cin >> n;
    while(n)
	{
        res*=10;
		res+=n%10;
        n/=10;
    }
    cout <<res<< endl;
}
