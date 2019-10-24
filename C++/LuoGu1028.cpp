#include <bits/stdc++.h>
using namespace std;
int n , res[1005] , sum[1005] ;
int main() {
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++ )
    {
    	sum[i] = sum[i-1] + ( res[i] = sum[i>>1] + 1 ) ;
	}
    printf("%d",res[n]) ;
}
