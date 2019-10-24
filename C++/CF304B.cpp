#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define calc(y,m,d) (m<3?(365*(y-1)+(y-1)/4-(y-1)/100+(y-1)/400+(153*(m+12)-457)/5+d-306):365*y+y/4-y/100+y/400+(153*m-457)/5+d-306)

int main()
{
	int y,m,d;
	scanf("%d:%d:%d",&y,&m,&d);
	ll fr=calc(y,m,d);
	scanf("%d:%d:%d",&y,&m,&d);
	ll to=calc(y,m,d);
	return 0&printf("%lld\n",abs(to-fr));
}
