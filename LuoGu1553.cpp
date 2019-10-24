#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    char dot=0;
    int cnt=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
		 cnt++;
        else
        {
            dot=s[i];
            break;
        }
    }
    int x=cnt;
    cnt--;
    while(s[cnt]=='0'&&cnt>0)
	cnt--;
    for(int i=cnt;i>=0;i--)
       cout<<s[i];
    if(dot==0)
	return 0;
    else
      if(dot=='%')
	  {
	  cout<<dot;
	  return 0;
	  }
      else
	  cout<<dot;
    int m=s.size()-1;
    while(s[x+1]=='0'&&x<m-1)
	x++;
    while(s[m]=='0'&&m>x+1)
	m--;
    for(int i=m;i>x;i--)
	{
		cout<<s[i];
	}
    return 0;
}
