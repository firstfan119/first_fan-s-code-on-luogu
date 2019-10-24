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

const int maxn=1e6+7;
struct edge
{
	int fr;
	int to;
	int nex;
}e[maxn];

int head[maxn];
int cnt=0;
void add(int u,int v)
{
	e[++cnt].fr=u;
	e[++cnt].to=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}

int f[maxn];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

int main()
{
	int n=read();
	int m=read();
	int st=read();
	for(ri i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(ri i=1;i<=m;i++)
	{
		int u=read();
		int v=read();
		add(u,v);
		//add(v,u);
	}
	priority_queue<int,vector<int>,greater<int> >ans;
	for(ri i=n;i>=1;i--)
	{
		for(ri j=head[i];j;j=e[j].nex)
		{
			int to=e[j].to;
			int fu=find(i);
			int fv=find(to);
			if(fu!=fv)
			{
				f[fu]=fv;
			}
		}
		if(find(i)==find(st))
		{
			ans.push(i);
		}
	}
	while(ans.size())
	{
		printf("%d\n",ans.top());
		ans.pop();
	}
}

/*
#########################################&%&&$%||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&%$######################################################$
####################################%!$&$%!!||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&%$##################################################$
#################################&$&$|!!!|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$%%%%%%%%%$$%$##############################################$
#############################%!&&|!!!!|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$%%%%%%%%%$&@############################################$
##########################%!&$|!!!!||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%%%%%%%%%%&$&#########################################$
########################&$&|!!!!!|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$%%%%%%%%%%$&@#######################################$
#####################%|&%!!!!||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$%%%%%%%%%%$&|%####################################$
###################$%&|!!!!!|%%%%%%%%%%%%%%%%%%%%%%%|%$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%$$%%%%%%%%%%$&!%##################################$
#################$%&|!!!!!|%%%%%%%%%%%%%%%%%%%%%%%%||$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|||%%%%%%%%%%%$$%%%%%%%%%%%$&|%################################$
###############$%&|!!!!||%||%%%%%%%%%%%%%%%%%%%%%%||%$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|||%%%%%%%%%%%%$$%%%%%%%%%%%$&@###############################$
#############%|&|!!!!!|||||%%%%%%%%%%%%%%%%%%%%%%|||$$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|||%%%%%%%%%%%$$%%%%%%%%%%%%&$&#############################$
############@&%!!!!!|||!||%%%%%%%%%%%%%%%%%%%%%%|||$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|||%%%%%%%%%%%$$%%%%%%%%%%%%&|%###########################$
##########$%$!!!!!!||!!||%%%%%%%%%%%%%%%%%%%%%%%|!%$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%|%%%%%%%%$%%%%%%%%%%%%$&@##########################$
#########@&%!!!!!!||!!||%%%%%%%%%%%%%%%%%%%%%%%|!|$$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%$$%%%%%%%%%%%%&%$########################$
#######%|&|!!!!!!!!!!||%%%%%%%%%%%%%%%%%%%%%%%|!|%$$%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$||%%%%%%%%%%|%$$%%%%%%%%%%%%&$&#######################$
######$%$|!!!!!!!!!!||%%%%%%%%%%%%%%||%%%%%%%||!|$$$$%%%%|%%%%%%|||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%$$%%%%%%%%%|%$$@######################$
#####$%%!!!!!!!!!!!|%%%%%%%%%%%%%%%%||%%|%%%%|!|$$%%%%%%||%%%%%||||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%$$%%%%%%%%%%%%$%$####################$
####&$%!!!!!!!!!!!|%%%%%%%%%%%%%%%||||||||%%|!!|$$$$%%%%|||%%%%||||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%$$%%%%%%%%%%%%$!%###################$
####@%!!!!!!!!!!!|%%%%%%%%%%%%%%%%|||||!!!!!!!!%$%$$%%%%|||%%%%||!|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%%$%%%%%%%%%%%%$$@##################$
###@%!!!!!!!!!!!%%%%%%%%%%%%%%%%%|!!||!!!!!!!!|$$%$$%%%%|||%%%%||!|%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%%$$%%%%%%%%%%%$@##################$
##@%!!!!!!!|!!!%%%%%%%%%%%%%%%%%%|!||!!!!!!!!!%$$$$%%%%||||%%%%||!|||!||||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%||%%%%%%%%%%%%%$$%%%%%%%%%%%$&#################$
#@%!!!!|||%|!!|%%%%%%%%%%%%%%%%%||!||!!!!!!!!|$$%$%%%%%||||%%%%||!!||!!!!||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$||%%%%%%%%%%%%%$$%%%%%%%%%%%$&################$
@%!!!|||%%%|!|%%%%%%%%%%%%%%%%%%|!!||!!!!!!!!%$$%$%%%%%|!!|%%%%||!!||!!!!!||%%%%|||||||||||||||||||||||||%%%%%%%%%%%%$$||%%%%%%%%%%%%%$$%%%%%%%%%%|%&###############$
$!!!|%%%%%||!%$%%%%%%%%%%%%%%%%%|||||!!!!!!!|$$$%%%%%%%|!!|%%%%%|!!!||||!!!|%%%%|||||||||||||||||||||||||||||%%%%|%%%%$$||%%%%%%%%%%%%%$$%%%%%%%%%%%$&##############$
!!!|%%%%%%|!|$%%%%%%%%%%%%%%%%%||||%|!||!!!!|$$$$%%%%%%||!|%%%%%||!!||%||!!||%%||||||||||%||%%%%||||||||||||||||%%%%%%%$$||%%%%%%%%%%%%%$$%%%%%%%%%%%%&#############$
!!|%%%%%%|||%$%%%%%%%%%%%%%%%%%|||%%||||||!!%$$%$%%%%%%|!!|%%|%%||!||%%%%|||||||||||||||||||||%%||||||||||||||||||||%%%%$%||%%%%%%%%%%%%%$$%%%%%%%%%%%$&############$
!|%%%%%%%|||$%%%%%%%%%%%%%%%%%%%%%%%%%%%||!|%$$$$%%%%%%%|!||%|||%||||||||||||||||||||||||||%|||||||||||||||||||||||||%%%%$%||%%%%%%%%%%%%%$$%%%%%%%%%%%$&###########$
|%%%%%%%|||%$%%%%%%%%%%%%%%%%%%%%%%%%%%%|!!|$$%$%%%%%%%$%!!||%%|%%||||||||||||||||||||||||||||||||||||||||||||||||||||%%%%$%||%%%%%%%%%%%%%$$%%%%%%%%%%%$@##########$
|%%%%%%%%|%$%%%%%%%%%%%%$%%%%%%%%%%%%%%%|!!%$$%$%%|%%%%%%!!|%%|%||||||%%|||||||||||||||||||||||||||||||||||||||||||||||%%%$$%||%%%%%%%%%%%|%$%|%%%%%%%%%%$@#########$
%%%%%%%%%|%$%%%%%%%%%%%$$%%%%%%%%%%%%%%%|!!%$$%$%%%|%%%|||!||||||||||||||||||||||||||||||!||||||||||||||||||||||%%%||%||%%%$$|||%%|||%%%%%%|%$%%%%%%%%%%%%&@########$
%%%%%%%%%%$$%%%%%%%%%%%$$%%%%%%%%%%%%%%||!|%$%%$%%|||%%;!|!|||||||||||||||||||||||||||||||!|||||||||||||||||||||%$%|||||%%$%$%|||%%|%%%|%%%%%%$%|%%%%%%%%%$&########$
%%%%%%%%%%$%%%%%%%%%%%%$$%%%%%%%%%%%%%%||!|$$%%$%%|%|%|':|||||||||||||||||||||||||||||||||!||||||||||||||||||||||%$%|||||%%%%$%|||%%|%%%%%%%%%%%%%%%%%%%%%%$&#######$
%%%%%%%%%%$%%%%%%%%%%%%$$%%%%%%%%%%%%%%|!!|$$%%$%|%%%%!`'||!||||||||||||||||||||||||||||||!!||||||||||||||||||||||%$%||||%%%$%%|||||%%|%%%%%%%%%%%%%%%%%%%%%&%$#####$
%%%%%%%%%$$%%%%%%%%%%%%$$%%%%%%%%%%%%%%|!!|$$%%%%|||%%;``;|!||||||||||||||||||||||||||||||!!||||||||||||||||||||||%%|%%%||%%$%%%|||||%%%%%%%%%%%%%%%|%%%%%%%%&######$
%%%%%%%%%$$%%%%%%%%%%%%$$%%%%%%%%%%%%%%|!!%$$%%%%|||%%:..:|||||||||||||||||||||||||||||||||!!|||||||||||||||||||||%%%|%%%||%%%%%%||%%||%||%%%%%%%%%%%%%%%%%%%$@#####$
%%%%%%%%%$$%%%%%%%%%%%%$$%%%%%%%%%%%%||||!%$%%%%%|||%|'```;|||||||||||||||||||||||||||||||||!||||||||||||||||||||||%||%%%||%%%%%%%||||||||||%%%%%%%%%%%%|%%%%%&#####$
%%%%%%%%%$%%%%%%%%%%%%%$$%%%%%%%%%%%%|||!!%$%%%%%||%$!`.`.`!|||||||||||||||||||||||||||||||%|!|||||||||||||||||||||%%!|%%%||%%%$%%||||%%|||||%%%%%%%%%%%%%%%%%$@####$
%%%%%%%%%$%%%%%%%%%%%%%$$%%%%%%%%%%%|||||!%$%%%%|||%$;```  :%||||||||||||||||||||||||||||||%%!!|||||||||||||||||||||%!!%%%%|%%%$%%%||%%%|||||%%%%|%%%%%%%%%%%%%&####$
%%%%%%%%%$%%%%%%%%%%%%%$$%%%%%%%%%|||||||!%$%%%%%||%%:.`.  .!%|%%|||||||||||||||||||||||||||%|!|||||||||||||||||||||%|;!%%%||%%%%%%|||%|||||||||%%%%%%%%%%%%%%%$@###$
%%%%%%%%$$%%%%%%%%%%%%%$$%%%%%%%%%|||||||!%$%%%%%|%$|'.`.   '|||%%|||||||||||||||||||||||||%%||!|||||||||||||||||||||%;:%$%%|%%$%%%%||%%|||||||%%%%%%%%%%%%%%%%%&###$
%%%%%%%%$$%%%%%%%%%%%%%%$%%%%%%%|%%||||||!|%%%%%||$$!```    .!%|%$%||||||||||||||||||||||||%|||!!||||||||||||||||||||%|'!$%%%%%%%$$$|||||||||%%%%%%%%%%%%%%%%%%%$###$
%%%%%%%%$$%%%%%%%%%%%%%%$$%%%%%%|%%||||||!|%%%%%|%$$%;'.     '|%%%%|||||||||||||||||||||||||%!|%!!|||||||||||||||||||%%:'%$%%%%$$$%%%|||||||||%%%|%%%%%%%%%%%%%%$@##$
%%%%%%%%$$%%%%%%%%%%%%%%$$%%%%|||||||||||!%%%%%%%%$$;.';'     :%%%%%||||||||||||||||||||||||%!;||!|||||||||||||||||||%$;`;%%%%$$$%$%%%|||||||||%%%%%%%%%%%%%%%%%$$&#$
%%%%%%%%$$%%%%%%%%%%%%%%$$%%%%%%|||||||||!%$%%%%%%$%;``  ';`  .!%%||%|||||||||||||||||||||||%%:;%|!||||||||||||||||||%$|''|$$$$%%$%%$%|||||||||||%%%%%%%%%%%%%%%$$$&%
%%%%%%%%$$%%%%%%%%%%%%%%$$%%%|||||||||||||%$%%%%%%$%:..    .;;..!$|;|%|||||||||||||||||||||||%!`!%!||||||||||||||||||%$%;`;&$%%%%%%%%$%||||%%%%|||||%%%%%%%%%%%%%%%$|
%%%%%%%%%$%%%%%%%%%%%%%%$$%%%%%|||||||||||%$%$$$%%$%'..       `!|%$!'|%||||||||||||||||||||||%|''|%||||||||||||||||||%%$%|||$%%%%$$%$$$%||%||%%|||||%%%%%%%%%%%%%%%%|
%%%%%%%%%$%%%%%%%%%%%%%%%$%%|%%|||||||||||%%$%%%%%$%'`.          `%$:`!%||||||||||||||||||||||%;.`|%%%|||||||||||||||%$&%'.:%$$$%%%%$%%$%|||%||%||||%%%%%%$$%%%%%%%%|
%%%%%%%%%$%%%%%%%%%%%%%%%$%%|%%||||||||||||%$$$%$$$%'..           .!$%|%$%||||||||||||||||||||%|` `|%$%|||||||||||||%$$$%;.`!$$$$$$$%$$$%%||%|||||||%%%%%%%$%%%%%%%%|
%%%%%%%%%$$%%%%%%%%%%%%%%$$%%||||||||||||||%$$%%%%$%'.              ':..'%$%||||||||||||||||||%%:  .!%||%|||||||||%$$%%$$!'.:%%!%$%%%%%$$%|||%|||||||%%%%%%$%%%%%%$$|
%%%%%%%%%$$%%%%%%%%%%%%%%$$%%||||||||||||||%$%%%%%$%:.               .````'!$&&$%||%%%%%$$$$%%|%!`   :%;;%%%%|%$&&&$&&&$$|'..!$::%$%%$$%$$%%%||||||||%%%|%%$$%%%%%$$|
%%%%%%%%%$$%%%%%%%%%%%%%%%$%|||||||||||||||%$$%%%%$$:                     `:;!;;::!|!:`..........     .`..  '!;'..``......`` `!:.!$%%%$$%%$%|%|||||||%%%%%%%$$%%%%%$|
%%%%%%%%%$$%%%%%%%%%%%%%%%$%|||||||||||||||%$$&$|:``         .`:;|%%%$%%|;:`    `'`                           .`....             .:!;:::!%$$%|%%|||||%%%%%%%%$$%$%$$|
%%%%%%%%%%$%%%%%%%%%%%%%%%$$|||||||||||||||%%:``.      `;$&@&@&&&&&&&&&&&&&&&&&$!.                                                ````.'%%!%%%%||||||%%%|%%%%$$%%%%%|
%%%%%%%%%%$$%%%%%%%%%%%%%%$$%||||||||||||||%|'.`.   :%&@&$$$$$$$&&&&&&&&&&&&&$$|'                                                     .;%|!|%%|||||||%%%%%%%%%$$%%$%|
%%%%%%%%%%$$%%%%%%%%%%%%%%%$%||||||||||||||%%;.`.`!$&&&&&$$$$$&&&&&&&|:;!|$&&&$$|`                                                    `||!!!|$%||||||%%%%%%%%%$$$%$$|
%%%%%%%%%%$$%%%%%%%%%%%%%%%$%||||||||||||||%%;``:$&&&&|:!%%%$&&&&&&$&&|`.......`;!`                                 ...              .!%!!!!!%%%|||||%%%%%%%%%%$$%%%|
%%%%$%%%%%%$$%%%%%%%%%%%%%%$$%||||||||||||||%!'!$$|%&:  .`:$&&$$$%%%$&$;.........                              `;|;'.                :%|!!!!!|%%%%|%%|%%%%%%%%%%$$%%|
%%%%$%%%%%%$$%%%%%%%%%%%%%%$$%||||||||||||||%%|%!.'$%` `|$$$$$$$$%%%$$&!                                      `'      `'';;;!|||;`  .|%!!!!!!!|$%%%||%%%%%%%%%%%%$$$|
%%%%%%%%%%%$$$%%%%%%%%%%%%%%$%||||||||||||||%$$!`.:$&$$$%%$$$$$$$%%%%%&!                                     `.  '$@@@@&&&&&$$%|'   :%%|!!!!!!!%$%|%%%%%%%%%%%%%%%%%|
%%%%%%%%%%%%$$%%%%%%%%%%%%%%$$%|||||||||||||%%|!` `%&$%%%%$%!;;||||%%$$:                                      .|&&&$$$$$&&&&&&$;   '||!||!!!!!!|$%%%|%%%%%%%%%%%%%%%|
%%%%|%%%%%%%%$%%%%%%%%%%%%%%%$%||%%|||%|||||%%;;:  ;&$%%|:'!%||%:``';%%'                                     :%&&&%!:'`.          .!%!!!|%!!!!!!%$%|%%%%%%%%%%%%%$$%|
%%%%||%%%%%%$$$%%%%%%%%%%%%%%$%%||||||||||||%$!`'` .!&$!` .``.......:%!                                     ;|:.                  :%|!!!!|%|!!!!|%$%%%%%%%%%%%%%%%$$|
%%%%|!%%%%%%%$$%%%%%%%%%%%%%%$$%|||||||||||||$|'.    :$%:...  .....'%;                                    ..                     .!%!!!!!!|%|!!!!|$%%%|%%%%%%%%%%%$$|
%%%%|!|%%%%%%$$$%%%%%%%%%%%%%%$%%%|||||%|||||%%:.      '||'      .;%:                                                            '||!!!!!!!|%|!!!!%$%%%%%%%%%%%%%%$$|
%%%%%||%$%|%%$$$%%%%%%%%%%|%%%$%%|||%|||%%|||%$;.         `:;!!!|||:.``                               .                          ;%|!!!!!!!!|%|!!!|$%%%%%%%%%%%%%%%$%
%%|%$$$$$$%%%%%$$%%%%%%%%%%%%%%$%%|%%||||||||%$|`                                                    `:`                         ;%!!!!!!!!!!|%|!!!%$%%%%%%%%%%%%%%$%
|||%$$$$$$$%%%$$$%%%%%%%%%%%%%%$$%||||%%|||%||$%'                                                    .'                         `!|!!!!!!!!!!!!||!!|$$%%%%%%%%%$%%%$%
%%%%$$$$$$$$%%%%$$%%%%%%%%%%%%%$$%%|||||||%%||%$;.                                                                              :||!!!!!!!!!!!!!||!!%$%%%%%%%%%%%%%$%
%%%%%$$$$$$$$$%$$$$%%%%%%%%%%%%$$%%%||||||||||%$|`          `` ..                                                              .!%!!!!!!!!!!!!!!!||||$%%%%%%%%%$%%%$%
%%%%%$$$$$$%$$$%%$$%%%%%%%%%%%%%%$%%|||||||||||$%:                                                                             ;%!!|!!!!!!!!!!!!!!!||%$%%%%%%%%%$%%$%
%%%%%%$$$$$$$$$$$%$$%%%%%%%%%%%%%$%%%%|||||||||%$!.                                                                           :||!!|||!!!!!!!!!!!!!!|%$%|%%%%%%%%$%$%
%%%%%%$$$$$$$$$$$$$$$%%%%%%%%%%%$$$%%|||||||||||$%'                                   .';;;;;|||!'.                          '%|!!!!!||!!!!!!!!!!!!!!|%$%%%%%%%%%$$$|
%%%%%%%$$$$$$$$$$$$$$$%%%%%%%%%%$$$$%%%|%%||||||%$!.                               :;;:''''''''''';$&;                      :%|!!!!!!!|%|!!!!!!!!!!!!!|$%|%%%%%%%$$$|
%$$%%%%%$$$$$$$$$$$$$$$%%%%%%%%%%$$$%%%%%%|||||%|$%'                             '!:'''''''''''''':|@%`                   .|$|!!!!!!!!!|%|!!!!!!!!!!!!|%$%%%%%%%%$$$%
$%%$$%%%%$$$$$$$$$$$$$$%%%%%%%%%%$$$$%%%%||||||||%$!`                           `;:''''''''''''''':!%'                   !$%!!!!!!!!!!!!|%|!!!!!!!!!!!!%$%%%%%%%%%$$%
$$$$%%%$$%%$$$$$$$$$$$$$$%%%%%%%%%$%$%%%%%%|||||||$$|`                          '!:'''':'''''''''':|;                  ;$%!!!!!!!!!!!!!!!|%|!!!!!!!!!!!|%%%%%%%%%%$$%
%%%$$$%%$%%%$$$$$$%%$$$&$$%%%%%%%%$$$%%%%%|%%||||%%$$$|.                        '!;''''':'''''''':|;                 ;$&$$|!!!!!!!!!!!!!!!|$$!!!!!!!!!!!%%%%%%%%%%%$%
%%%%%$$$$$$%%%%%$$$$$$$$$$$%%%%%%%%$$$$%%%%%%%%%|%|%$$%%%:                       ;|:''':'''''''':|'               '$&$$$$$$$|!!!!!!!!!!!!!!%$&$!!!!!!!!!|%%%%%%%%%%&%
%%%%%%%%%%$$&&$$$%%%%$$$$$&$$%%%%%%%$$$$%%%%%%%%%||%%$!`.'||'                     '|;'''''::'';!'              .|&$%$$$$$$$$$%|!!!!!!!!!!!!|$##&|!!!!!!!|%%%%%%%%%%$%
%%%%%%%%%%%%%%%%%%$$&&&$&$$$$$%%%%%%$%%$$%|%%%%%%%%%%%;````.`;%!`                   .:;:::;!|:.             `|&&$$$$$$$$$$%$$$$|!!!!!!!!!!!!|$##@$|!!!!!!%%%%%%%%%%$%
%%%%%%%%%%%%%%%%%%%%%%%$$$$$$$$%$%%%%$$%$$%%%%%%%%%%%%%;...``...'!$|'                                   .;$&$$$$$$$$$$$$$$$$$$$$|!!!!!!!!!!!!|&###@|!!!!!|%%%%%%%%%%|
&&&&&$$$%%%%%%%%%%%%%%%%%$$$$$$$$%%%%%%%$$%%%%%%%%|%%%%|:....``````.`:|%!'                           `|&$$$$%$$$$$$$$$$$$$$$$$$$$|!!!!!!!!!!!|$@####$!!!!|%%%%%%%%%%|

*/
