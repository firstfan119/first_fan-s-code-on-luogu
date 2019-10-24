#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 1000010
#define P 110

int price[N];

struct GRAPH {
	int hed[N];
	int nex[M];
	int to[M];
	int tot;

	void add(int u, int v) {
		//��·�������
		tot++;
		nex[tot]=hed[u];
		hed[u]=tot;
		to[tot]=v;
	}
};

GRAPH g, revg;

bool reach[N];
//�����¼
bool vis[N][P];
//���׷��ʼ�¼
int n, m;
int ans;

struct jewel {
	int pos; //��ǰ������¼
	int now; //û��=0�����ƴ���=���ۣ�
};
void init() {
	queue<int> q;
	q.push(n);
	reach[n]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i=revg.hed[u]; i; i=revg.nex[i]) {
			int v=revg.to[i];
			if (reach[v])
			//���˾ͼ���
			{
				continue;
			}
			q.push(v);
			reach[v]=1;
		}
	}
}
void bfs() {
	queue<jewel> q;
	q.push((jewel) {1, 0});
	while(q.size()) {
		jewel u=q.front();
		q.pop();
		for (int i=g.hed[u.pos]; i; i=g.nex[i]) {
			jewel v;
			v.pos=g.to[i];
			v.now=u.now;
			if (!reach[v.pos])
			//û������ɶ
			{
				continue;
			}
			if (vis[v.pos][v.now])
			//���������л�����ɶ
			{
				continue;
			}
			q.push(v);
			vis[v.pos][v.now]=1;
		}
		if(!u.now) { //û��
			jewel v;
			v.pos=u.pos;
			v.now=price[u.pos];
			if (vis[v.pos][v.now])
			{
				//�۵�����������ˣ���������~
				continue;
			}
			q.push(v);
			vis[v.pos][v.now]=1;
		}

		if (u.now)
		{ //��⵽�ҵ���Һ����
			int profit=price[u.pos]-u.now;
			//��ǰ�����۸��ȥ����۸�
			ans=max(ans, profit);
			//��Ŀǰ��ѷ�������
		}
	}
}
void regis_graph()
{
	int x,y,z;
		cin>>x>>y>>z;
		g.add(x, y);
		if (z==2) g.add(y, x);
		revg.add(y, x);
		if (z==2) revg.add(x, y);
}
int main() {
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>price[i];
	for (int i=1; i<=m; i++) {
		regis_graph();
	}
	init();
	bfs();
	cout<<ans;
	return 0;
}
