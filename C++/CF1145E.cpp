#include <bits/stdc++.h>
using namespace std;
int main()
{
	for (int __=21;__<=50;__++)
	{
		cout<<((min(__, 25)+__) % (2+__ %3)>0)<<endl;
	}
}
