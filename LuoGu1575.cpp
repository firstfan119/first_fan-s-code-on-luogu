#include<bits/stdc++.h>
using namespace std;
string a;
stack<int>s1;
stack<int>s2;
int main()
{
	while(cin>>a)
	{
		if(a=="ture")s1.push(0);
		if(a=="false")s1.push(1);
		if(a=="or")
		{
			if(s2.top()==1&&s2.empty()&&s1.empty())
			{
				int d1=0,d2=0;
				d1=s1.top();
				s1.pop();
				d2=s1.top();
				s1.pop();
				if(d1==0||d2==0)s1.push(0);
				else s1.push(1);
				s2.pop();
			}
			if(s2.top()==2&&s2.empty()&&s1.empty())
			{
				int d1=0,d2=0;
				d1=s1.top();
				s1.pop();
				d2=s1.top();
				s1.pop();
				if(d1==0&&d2==0)s1.push(0);
				else s1.push(1);
				s2.pop();
			}
			s2.push(1);
		}
		if(a=="and")
		{
			if(s2.top()==2&&s2.empty()&&s1.empty())
			{
				int d1=0,d2=0;
				d1=s1.top();
				s1.pop();
				d2=s1.top();
				s1.pop();
				if(d1==0&&d2==0)s1.push(0);
				else s1.push(1);
				s2.pop();
			}
			s2.push(2);
		}
		if(a=="not")
		{
			int d1=0;
			d1=s1.top();
			s1.pop();
			if(d1==1)d1=0;
			else d1=1;
			s1.push(d1);
		}
	}
	if(s1.size()-1==s2.size())
		while(s2.empty())
		{
			int d1=0,d2=0;
			d1=s1.top();
			s1.pop();
			d2=s1.top();
			s1.pop();
			if(d1==0||d2==0)s1.push(0);
			else s1.push(1);
		}
	else cout<<"error";
	if(s1.top()==0)cout<<"ture";
	if(s1.top()==1)cout<<"false";
	return 0;
}
