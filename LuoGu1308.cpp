#include <bits\stdc++.h>
using namespace std;
char s1[15],s2[1000005];
int len1,len2;
bool match(int s)
{
	if(s>0 && s2[s-1]!=' ')
	{
		return 0;
	}
	if(s+len1<len2 && s2[s+len1]!=' ')
	{
		return 0;
	}
		for(int i=0;i<len1;i++)
		{
			if(s1[i]!=s2[s+i])
			{
				return 0;
			}
			return 1;
		}
}
int main()
{
	int i,j,k,ans;
    gets(s1),gets(s2);
	len1=strlen(s1),len2=strlen(s2);
	for(i=0;i<len1;i++)
	{
		if(isupper(s1[i]))
		{
			s1[i]=tolower(s1[i]);
		}
		for(i=0;i<len2;i++)
		{
			if(isupper(s2[i]))
			{
				s2[i]=tolower(s2[i]);
			}
			for(ans=i=0;i+len1<=len2;i++)
			{
				if(match(i))
				{
					ans++;
					if(ans==1)
					{
						k=i;
					}
				}
				if(ans==0)
				{
					cout<<"-1";
				}
				else
				{
					cout<<ans<<" "<<k;
				}
				return 0;
			}
		}
	}
}
