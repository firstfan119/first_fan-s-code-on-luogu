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

char ch[200][200]=
{
	"I am guilty.",
	"I am not guilty.",
	"Today is Monday.",
	"Today is Tuesday.",
	"Today is Wedaynesday.",
	"Today is Thursday.",
	"Today is Frid.",
	"Today is Saturday.",
	"Today is Sunday.",
};
char ch2[10][20]=
{
	"is guilty.",
	"is not guilty.",
};

const int maxn=1e3+2;
int sum,say[maxn][maxn];
int day[maxn][maxn];
int n,m,p;
char name[maxn][maxn],s[100005],ans[maxn];
int fal[maxn],tru[maxn];
void upd(int id)
{
	int len=strlen(s);
	int cnt=0;
	int cnt2=0;
	int lena;
	int man=0,man2=0;
	char t[30];
	char name2[300];
	memset(t,0,sizeof(t));
	memset(name2,0,sizeof(name2));
	for(ri i=0; i<len; i++)
	{
		if(s[i]==':')
		{
			lena=i-1;
			break;
		}
		else
		{
			name2[cnt2++]=s[i];
		}
	}
	for(ri i=1; i<=m; i++)
	{
		int lenb=strlen(name[i]);
		int flag=0;
		if(lenb!=lena+1)
		{
			continue;
		}
		else
		{
			if(!strcmp(name2,name[i]))
			{
				man=i;
				break;
			}
		}
	}
	if(!man)return;
	for(ri i=lena+3; i<len; i++)
	{
		if(s[i]!='\n')
		{
			t[cnt++]=s[i];
		}
	}
	int flg=0;
	for(ri i=0; i<=8; i++)
	{
		if(!strcmp(t,ch[i]))
		{
			flg=true;
			if(i==0)
			{
				say[man][man]=true;
			}
			else if(i==true)
			{
				say[man][man]=2;
			}
			else
			{
				day[man][i-1]=true;
			}
			break;
		}

	}
	if(!flg)
	{
		int lenx;
		char t2[300],coc=0,t3[20],tot=0;
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));

		for(ri i=0; i<strlen(t); i++)
		{
			if(t[i]==' ')
			{
				lenx=i-1;
				break;
			}
			else
			{
				t2[coc++]=t[i];
			}
		}
		for(ri i=1; i<=m; i++)
		{
			if(lenx+1!=strlen(name[i]))
			{
				continue;
			}
			else if(!strcmp(t2,name[i]))
			{
				man2=i;
				break;
			}
		}
		if(!man2)
		{
			return;
		}
		for(ri i=lenx+2; i<strlen(t); i++)
		{
			if(t[i]!='\n')
			{
				t3[tot++]=t[i];
			}
		}
		for(ri i=0; i<2; i++)
		{
			if(!strcmp(t3,ch2[i]))
			{
				if(i==0)
				{
					say[man][man2]=true;
				}
				else
				{
					say[man][man2]=2;
				}
				break;
			}
		}
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));

	}
	memset(t,0,sizeof(t));
	memset(name2,0,sizeof(name2));

}
int check(int peo,int today)
{
	memset(fal,0,sizeof(fal));
	int fake=0;
	int zero=0;
	int te=0;
	for(ri i=1; i<=m; i++)
	{
		int g=0,gg=0;
		if(say[i][peo]==2)
		{
			fal[i]=true;
		}
		if(say[i][peo]==true)
		{
			tru[i]=true;
		}
		if(fal[i])
		{
			continue;
		}
		for(ri j=1; j<=m; j++)
		{
			if(say[i][j]==true&&j!=peo)
			{
				fal[i]=true;
				break;
			}
		}
		for(ri j=1; j<=m; j++)
		{
			if(say[i][j]==2&&j!=peo)
			{
				tru[i]=true;
				break;
			}
		}
		if(fal[i])
		{
			continue;
		}
		for(ri j=1; j<=7; j++)
		{
			if(day[i][j]==true&&j!=today)
			{
				fal[i]=true;
				break;
			}
		}
		for(ri j=1; j<=m; j++)
		{
			if(say[i][j]==true||say[i][j]==2)
			{
				g=true;
				break;
			}
		}
		for(ri j=1; j<=7; j++)
		{
			if(day[i][j]==true)
			{
				gg=true;
				break;
			}
		}
		if(tru[i]==true&&fal[i]==true)
		{
			return 0;
		}
		if(gg|g==false)
		{
			zero++;
		}
	}
	for(ri i=1; i<=m; i++)
	{
		if(fal[i])fake++;
	}
	for(ri i=0; i<=zero; i++)
	{
		if(fake+i==n)
		{
			return 1;
		}
	}
	return 0;
}
int tot1=0,top=0;
int ans2[40];
int main()
{
	m=read();
	n=read();
	p=read();
	for(ri i=1; i<=m; i++)
	{
		scanf("%s",name[i]);
	}
	char ch=getchar();
	while(ch==10)
	{
		ch=getchar();
	}
	getchar();
	for(ri i=1; i<=p; i++)
	{
		gets(s);
		upd(i);
	}
	for(ri i=1; i<=m; i++)
	{
		for(ri j=1; j<=7; j++)
		{
			if(check(i,j))
			{
				if(tot1>1&&i!=ans2[top])
				{
					return 0&(int)printf("Cannot Determine");
				}
				if(i!=ans2[top])
				{
					tot1++;
					strcpy(ans,name[i]);
					top++;
					ans2[top]=i;
				}
			}
		}
	}
	if(!tot1)
	{
		printf("Impossible");
	}
	else
	{
		printf("%s",ans);
	}
}
