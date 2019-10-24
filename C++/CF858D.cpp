#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}

int main()
{
	int n=read();
	vector<string> v(n);
	for(ri p=0; p<n; p++)
	{
		cin >> v[p];
	}
	map<string,set<string> > m;
	for(ri p=0; p<n; p++)
	{
		for(ri len=1; len <= v[p].size(); len++)
		{
			for(ri s=0; s <= v[p].size() - len; s++)
			{
				string key=v[p].substr(s,len);
				if(m.count(key) == 0)
				{
					set<string> t;
					m[key]=t;
				}
				m[key].insert(v[p]);
			}
		}
	}

	map<string,string> unique;
	for(int p=0; p<n; p++)
	{
		unique[v[p]]=v[p];
	}

	for(map<string,set<string> >::iterator it=m.begin(); it != m.end(); it++)
	{
		string cand=it->first;
		set<string> nums=it->second;
		if(nums.size() > 1)
		{
			continue;
		}
		string number=*nums.begin();
		if(cand.size()<unique[number].size())
		{
			unique[number]=cand;
		}
	}

	for(int p=0; p<n; p++)
	{
		cout << unique[v[p]] << endl;
	}

	return 0;
}
