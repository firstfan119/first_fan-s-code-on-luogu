#include <iostream>
using namespace std;
int s[3],m[3],l[3];
int main()
{
	int bre(int,int);
	int a,b,c;
	for(a=192;a<=329;a++)
	{
		b=2*a;c=3*a;
		bre(a,0);bre(b,1);bre(c,2);
		if(s[0]==s[1]||s[1]==s[2]||s[0]==s[2])
		continue;
		if(m[0]==m[1]||m[1]==m[2]||m[0]==m[2])
		continue;
		if(l[0]==l[1]||l[1]==l[2]||l[0]==l[2])
		continue;
		
		if(s[0]==m[0]||s[0]==m[1]||s[0]==m[2])
		continue;
		if(s[0]==l[0]||s[0]==l[1]||s[0]==l[2])
		continue;
		if(m[0]==l[0]||m[0]==l[1]||m[0]==l[2])
		continue;
		
		if(s[1]==m[0]||s[1]==m[1]||s[1]==m[2])
		continue;
		if(s[1]==l[0]||s[1]==l[1]||s[1]==l[2])
		continue;
		if(m[1]==l[0]||m[1]==l[1]||m[1]==l[2])
		continue;
		
		if(s[2]==m[0]||s[2]==m[1]||s[2]==m[2])
		continue;
		if(s[2]==l[0]||s[2]==l[1]||s[2]==l[2])
		continue;
		if(m[2]==l[0]||m[2]==l[1]||m[2]==l[2])
		continue;
		if(s[1]&&s[2]&&s[0]&&m[0]&&m[1]&&m[2]&&l[0]&&l[0]&&l[0])
		cout<<a<<" "<<b<<" "<<c<<endl;
		
	}
	return 0;
}

int bre(int a,int num)
{
	l[num]=a/100;
	m[num]=(a-a/100*100)/10;
	s[num]=a%10;
	return 0;
}
