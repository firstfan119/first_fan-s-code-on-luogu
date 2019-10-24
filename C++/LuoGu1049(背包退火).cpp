#include<bits/stdc++.h>
#define MAXN 50
#define Tk 0.99789
#define rd (rand() % n + 1)
using namespace std;

int v[MAXN];
int V, n, ans = 0, tot = 0;
bool vis[MAXN];
double T = 1926;

bool accept(int del) {
    return ((del>0)||exp(-del/T) > (double)rand()/RAND_MAX);
} //转移概率表达式

int main() {
    srand(time(0));
    scanf("%d%d", &V ,&n);
    for(int i=1; i<=n; i++)
    {
    	scanf("%d", &v[i]);
	}
    int a;
    while(T > 1e-14) {
        ans=max(ans,tot);
        a = rd;
        int dE = v[a];
        if(vis[a])
		{
			dE *= -1;
		}
        if(accept(dE)) 
		{
            if(vis[a])
			{
                vis[a] = false;
                tot -= v[a];
            }
			else
			{
                if(tot + v[a] > V)
				{
					continue;
				}
                vis[a] = true;
                tot += v[a];
            }
        }
        T *= Tk;
    }
    cout <<V-ans;
    return 0;
}
