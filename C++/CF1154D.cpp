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
	int solar[2];//0->���� 1->����
	int n=read();
	solar[0]=solar[1]=read();//̫����
	solid[0]=solid[1]=read();//��̬���
	
	for(int i=1;i<=n;i++)
	{
		lit[i]=read();//��
	}
	for(int i=1;i<=n;i++)
	{
		if(lit[i])//�˴��й⣬��ѡ��̬���
		{
			if(solid[1]<solid[0])//��̬�������ù�
			{
				if(solar[1]!=0)//̫�����е�
				{
					solar[1]--;
					solid[1]++;
				}
				else if(solid[1]!=0)//��̬����е磬̫�����޵�
				{
					solid[1]--;
				}
			}
			else
			{
				solid[1]--;
			}
			ans++;//��һ��
			if(solar[1]==0&&solid[1]==0)
			{
				return 0&printf("%d",ans);
			}//�ľ�
		}
		else//�޹⣬����̫����
		{
			if(solid[1]!=0)
			{
				solid[1]--;
			}
			else if(solar[1]!=0)
			{
				solar[1]--;
			}//ģ��ĵ����
			ans++;
			if(solar[1]==0&&solid[1]==0)
			{
				return 0&printf("%d",ans);
			}//�ľ�
		}
	}
	return 0&printf("%d",n);
}
