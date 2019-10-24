#include<bits/stdc++.h>
using namespace std;

int n, a, b;
int p[1010], vis[1010];
queue<int> q;

int main(){
    scanf("%d%d%d", &n, &a, &b);
    vis[a] = 1;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    q.push(a);
    while(!q.empty()){
        int now = q.front(), l = now - p[now], r = now + p[now];
        q.pop();
        if(l >= 1 && !vis[l])
            q.push(l), vis[l] = vis[now] + 1;
        if(r <= n && !vis[r])
            q.push(r), vis[r] = vis[now] + 1;
        if(l == b || r == b)
        	break;
    }
    printf("%d\n", vis[b] - 1);
    return 0;
}
