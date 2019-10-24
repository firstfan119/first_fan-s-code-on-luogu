#include <bits/stdc++.h>

using namespace std;

int direfr[6]= {0,0,1,1,2,2};
int direto[6]= {1,2,0,2,0,1};
int p[21];

int main()
{
	int a[3];
	scanf("%d %d %d",a,a+1,a+2);
	int x[3]= {0,0,a[2]};
	srand((time)(0));
	for (int i=0; i<25260817; i++)
	{
		int caozuo=rand()%6;
		int dv=a[direto[caozuo]]-x[direto[caozuo]];
		if (dv>x[direfr[caozuo]])
		{
			x[direto[caozuo]]+=x[direfr[caozuo]];
			x[direfr[caozuo]]=0;
		}
		else
		{
			x[direto[caozuo]]+=dv;
			x[direfr[caozuo]]-=dv;
		}
		if (!x[0]) //如果A是空的
		{
			p[x[2]]=1;//统计C桶现有牛奶体积
		}
	}
	for (int i=0; i<=a[2]; i++)
	{
		if (p[i]) printf("%d ",i);
	}
	return 0;
}
