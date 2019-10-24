//�����,��ҪDFS��������dp���ں�Ч�ԣ�
#include <bits/stdc++.h>
#define ri register ll
#define ll long long
#pragma GCC optimize("O3")
#define ll long long
using namespace std;
ll read()
{
	ll num=0;
	ll flg=1;
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
}//���

//DFS�Ĳ������ǣ�
//��ǰ��Ⱦ��㣿��X��
//�ڵ���ȣ���Ⱦ������?(��)
//�����м��Σ�(X)
//��ǰ��Ⱦ���������̣�

//�г���������һ���㼰�������������ϡ��г� ��
//�����ǲ�����

const ll maxn=1125;
ll n,p;
ll b[305][305];
ll cnt[305],sick,dis[305];
bool bol[305],vis[305];
vector <ll> ed[305],son[305];
struct node
{
	ll x,val;
	node (ll a,ll b) : x(a),val(b)
	{
	}
	friend bool operator < (node a,node b)
	{
		return a.val>b.val;
	}
};//����

priority_queue <node> q;


ll calc_size(ll i)
{
	bol[i]=true;
	ll num=1;
	ll p=son[i].size();//size С��0�Ͳ���ѭ���ˣ�ֱ�ӷ���1
	//������С
	for (ll j=0; j<p; j++)
	{
		num +=calc_size(son[i][j]);
	}
	return num;
}

void flow_back(ll i)
{
	bol[i]=false;
	ll size=son[i].size();
	for (ll j=0; j<size; j++)
	{
		flow_back(son[i][j]);
	}
}

void dfs(ll dep,ll tot)//��ȣ���ǰ��Ⱦ����
{
	sick=max(sick,tot);
	for (ll i=0; i<cnt[dep]; i++)
	{
		if (!bol[b[dep][i]])
		{
			ll num=calc_size(b[dep][i]);
			tot +=num;//����ȫ������
			dfs(dep+1,tot);
			flow_back(b[dep][i]);
			tot -=num;//�޳�û�ò���
		}
	}
}
void solve(ll i,ll dep)
{
	b[dep][cnt[dep]++]=i;
	
	ll p=ed[i].size();//�ߵĸ���
	
	for (ll j=0; j<p; j++)
	{
		if (dis[ed[i][j]]==dis[i]+1)
		{
			solve(ed[i][j],dep+1);//bacteria expanding successfully
			son[i].push_back(ed[i][j]);
		}
	}
}

//������ӽڵ�ָ�򸸽ڵ�Ĺ�ϵ�Ļ�������û�á�����������
void shortest_path()
{
	fill(dis,dis+n+1,1125);
	dis[1]=0;
	q.push((node)
	{
		1,0
	});//�ṹ��ѹ��
	while (!q.empty())
	{
		node top=q.top();
		q.pop();//ϲ���ּ���ͺ������
		ll x=top.x;
		ll size=ed[x].size();
		for (ll j=0; j<size; j++)
		{
			if (dis[ed[x][j]]>dis[x]+1)
			{
				dis[ed[x][j]]=dis[x]+1;
				q.push(node(ed[x][j],dis[ed[x][j]]));
			}
		}
	}
	solve(1,0);
}//���·�����Ӽ��·��ϵ
int main()
{
	n=read();
	p=read();
	for (ll i=1; i<=p; i++)
	{
		ll u=read();
		ll v=read();
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	shortest_path();//����
	dfs(1,0);//����
	printf("%d",n-sick);//����
}
