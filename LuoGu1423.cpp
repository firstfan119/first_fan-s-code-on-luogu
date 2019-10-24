#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double destination,distance=0,step;
	cin>>destination;
	for(step=0;distance<=destination;++step,distance+=2*pow(0.98,step-1));
	cout<<step;
	return 0;
}
