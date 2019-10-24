#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int cnt,fst[MAXN],nxt[MAXN<<1],to[MAXN<<1],w[MAXN<<1];
int n,Q,a[MAXN],t[MAXN<<2],tag[MAXN<<2],maxn[MAXN<<2],minx[MAXN<<2];
int siz[MAXN],son[MAXN],top[MAXN],dep[MAXN],faz[MAXN],dfn[MAXN],Index,rk[MAXN];
string s;
void AddEdge(int u,int v,int c)
{
    to[++cnt]=v;
    nxt[cnt]=fst[u];
    fst[u]=cnt;
    w[cnt]=c;
}
void Dfs1(int u)
{
    siz[u]=1;
    son[u]=0;
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==faz[u]) continue;
        dep[v]=dep[u]+1;
        faz[v]=u;
        rk[v]=w[i];
        Dfs1(v);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) son[u]=v;
    }
}
void Dfs2(int u,int rt)
{
    top[u]=rt;
    dfn[u]=++Index;
    a[Index]=rk[u];
    if(son[u]) Dfs2(son[u],rt);
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==faz[u] || v==son[u]) continue;
        Dfs2(v,v);
    }
}
void PushUp(int rt)
{
    t[rt]=t[rt<<1]+t[rt<<1|1];
    maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
    minx[rt]=min(minx[rt<<1],minx[rt<<1|1]);
}
void PushDown(int rt)
{
    if(tag[rt])
    {
        t[rt<<1]*=-1;
        t[rt<<1|1]*=-1;
        tag[rt<<1]^=1;
        tag[rt<<1|1]^=1;
        swap(maxn[rt<<1],minx[rt<<1]);
        swap(maxn[rt<<1|1],minx[rt<<1|1]);
        maxn[rt<<1]*=-1;
        minx[rt<<1]*=-1;
        maxn[rt<<1|1]*=-1;
        minx[rt<<1|1]*=-1;
        tag[rt]=0;
    }
}
void BuildSegmentTree(int rt,int l,int r)
{
    if(l==r)
    {
        t[rt]=maxn[rt]=minx[rt]=a[l];
        return;
    }
    int mid=l+r>>1;
    BuildSegmentTree(rt<<1,l,mid);
    BuildSegmentTree(rt<<1|1,mid+1,r);
    PushUp(rt);
}
void ModifyPoint(int rt,int l,int r,int pos,int val)
{
    if(l==r)
    {
        t[rt]=maxn[rt]=minx[rt]=val;
        return;
    }
    PushDown(rt);
    int mid=l+r>>1;
    if(pos<=mid) ModifyPoint(rt<<1,l,mid,pos,val);
    else ModifyPoint(rt<<1|1,mid+1,r,pos,val);
    PushUp(rt);
}
void ModifyNega(int rt,int l,int r,int tl,int tr)
{
    if(tl<=l && r<=tr)
    {
        t[rt]*=-1;
        tag[rt]^=1;
        swap(maxn[rt],minx[rt]);
        maxn[rt]*=-1;
        minx[rt]*=-1;
        return;
    }
    PushDown(rt);
    int mid=l+r>>1;
    if(tl<=mid) ModifyNega(rt<<1,l,mid,tl,tr);
    if(tr>mid) ModifyNega(rt<<1|1,mid+1,r,tl,tr);
    PushUp(rt);
}
int QuerySum(int rt,int l,int r,int tl,int tr)
{
    if(tl<=l && r<=tr) return t[rt];
    PushDown(rt);
    int mid=l+r>>1,res=0;
    if(tl<=mid) res+=QuerySum(rt<<1,l,mid,tl,tr);
    if(tr>mid) res+=QuerySum(rt<<1|1,mid+1,r,tl,tr);
    return res;
}
int QueryMaxn(int rt,int l,int r,int tl,int tr)
{
    if(tl<=l && r<=tr) return maxn[rt];
    PushDown(rt);
    int mid=l+r>>1,res=-2e9;
    if(tl<=mid) res=max(res,QueryMaxn(rt<<1,l,mid,tl,tr));
    if(tr>mid) res=max(res,QueryMaxn(rt<<1|1,mid+1,r,tl,tr));
    return res;
}
int QueryMinx(int rt,int l,int r,int tl,int tr)
{
    if(tl<=l && r<=tr) return minx[rt];
    PushDown(rt);
    int mid=l+r>>1,res=2e9;
    if(tl<=mid) res=min(res,QueryMinx(rt<<1,l,mid,tl,tr));
    if(tr>mid) res=min(res,QueryMinx(rt<<1|1,mid+1,r,tl,tr));
    return res;
}
void ModifyToNegative(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        ModifyNega(1,1,n,dfn[top[u]],dfn[u]);
        u=faz[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    ModifyNega(1,1,n,dfn[u]+1,dfn[v]);
}
int QuerySumOnTree(int u,int v)
{
    int res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=QuerySum(1,1,n,dfn[top[u]],dfn[u]);
        u=faz[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res+=QuerySum(1,1,n,dfn[u]+1,dfn[v]);
    return res;
}
int QueryMaxnOnTree(int u,int v)
{
    int res=-2e9;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,QueryMaxn(1,1,n,dfn[top[u]],dfn[u]));
        u=faz[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=max(res,QueryMaxn(1,1,n,dfn[u]+1,dfn[v]));
    return res;
}
int QueryMinxOnTree(int u,int v)
{
    int res=2e9;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=min(res,QueryMinx(1,1,n,dfn[top[u]],dfn[u]));
        u=faz[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=min(res,QueryMinx(1,1,n,dfn[u]+1,dfn[v]));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        AddEdge(x+1,y+1,z);
        AddEdge(y+1,x+1,z);
    }
    Dfs1(1);
    Dfs2(1,1);
    BuildSegmentTree(1,1,n);
    scanf("%d",&Q);
    while(Q--)
    {
        cin>>s;
        int x,y;
        scanf("%d %d",&x,&y);
        if(s=="C") ModifyPoint(1,1,n,dfn[x+1],y);
        else if(s=="N") ModifyToNegative(x+1,y+1);
        else if(s=="SUM") printf("%d\n",QuerySumOnTree(x+1,y+1));
        else if(s=="MAX") printf("%d\n",QueryMaxnOnTree(x+1,y+1));
        else if(s=="MIN") printf("%d\n",QueryMinxOnTree(x+1,y+1));
    }
    return 0;
}
