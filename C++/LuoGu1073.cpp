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
		//道路添加手续
		tot++;
		nex[tot]=hed[u];
		hed[u]=tot;
		to[tot]=v;
	}
};

GRAPH g, revg;

bool reach[N];
//到达记录
bool vis[N][P];
//交易访问记录
int n, m;
int ans;

struct jewel {
	int pos; //当前地区记录
	int now; //没买=0；求善待沽=进价；
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
			//到了就继续
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
			//没到还卖啥
			{
				continue;
			}
			if (vis[v.pos][v.now])
			//都看过不行还来看啥
			{
				continue;
			}
			q.push(v);
			vis[v.pos][v.now]=1;
		}
		if(!u.now) { //没买
			jewel v;
			v.pos=u.pos;
			v.now=price[u.pos];
			if (vis[v.pos][v.now])
			{
				//咱到过这个卖家了，看过不行~
				continue;
			}
			q.push(v);
			vis[v.pos][v.now]=1;
		}

		if (u.now)
		{ //检测到找到买家后出售
			int profit=price[u.pos]-u.now;
			//当前地区价格减去购入价格
			ans=max(ans, profit);
			//和目前最佳方案打擂
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
