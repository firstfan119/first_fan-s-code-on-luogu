#include <iostream>
#include <sstream>
using namespace std;
long long num;
char s[10];
int record[10];
void count(char f[20])
{
	for(int i=0;i<20;i++)
	{
		switch (f[i])
		{
		case '0':record[0]++;break;
		case '1':record[1]++;break;
		case '2':record[2]++;break;
		case '3':record[3]++;break;
		case '4':record[4]++;break;
		case '5':record[5]++;break;
		case '6':record[6]++;break;
		case '7':record[7]++;break;
		case '8':record[8]++;break;
		case '9':record[9]++;break;
		}
	}
}
int main()
{
	cin>>num;
	for(;num>0;num--)
	{
		sprintf(s,"%lld",num);
		count(s);
	}
	for(int i=0;i<10;i++)
	cout<<record[i]<<endl;
}
