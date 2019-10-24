#include<bits/stdc++.h>
#define ri register int
using namespace std;
bool lit[300000];
int ans=0;
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
	int solid[2];
	int solar[2];//0->满电 1->现在
	int n=read();
	solar[0]=solar[1]=read();//太阳能
	solid[0]=solid[1]=read();//固态电池
	
	for(int i=1;i<=n;i++)
	{
		lit[i]=read();//光
	}
	for(int i=1;i<=n;i++)
	{
		if(lit[i])//此处有光，优选固态电池
		{
			if(solid[1]<solid[0])//固态不满（用过
			{
				if(solar[1]!=0)//太阳能有电
				{
					solar[1]--;
					solid[1]++;
				}
				else if(solid[1]!=0)//固态电池有电，太阳能无电
				{
					solid[1]--;
				}
			}
			else
			{
				solid[1]--;
			}
			ans++;//走一步
			if(solar[1]==0&&solid[1]==0)
			{
				return 0&printf("%d",ans);
			}//耗尽
		}
		else//无光，优先太阳能
		{
			if(solid[1]!=0)
			{
				solid[1]--;
			}
			else if(solar[1]!=0)
			{
				solar[1]--;
			}//模拟耗电过程
			ans++;
			if(solar[1]==0&&solid[1]==0)
			{
				return 0&printf("%d",ans);
			}//耗尽
		}
	}
	return 0&printf("%d",n);
}
