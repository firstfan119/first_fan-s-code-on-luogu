#include <bits/stdc++.h>
#define lson (root<<1)
#define rson (root<<1|1)
#define leaf (l==r)
using namespace std;

struct node
{
    int ls,rs,val;
} seg[800080];

int n,m;

void push_up(int root)
{
    seg[root].val=max(seg[lson].val,seg[rson].val);
}

void build(int root,int l,int r)
{
    if(leaf)
    {
        seg[root].ls=l;
        seg[root].rs=r;
        scanf("%d",&seg[root].val);
        return ;
    }
    seg[root].ls=l;
    seg[root].rs=r;
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(root);
}

void update(int root,int pos,int val)
{
    if(seg[root].ls==pos&&seg[root].rs==pos)
    {
        seg[root].val=max(seg[root].val,val);
        return ;
    }
    int mid=(seg[root].ls+seg[root].rs)>>1;
    if(pos<=mid)
    {
        update(lson,pos,val);
    }
    else
    {
        update(rson,pos,val);
    }
    push_up(root);
}

int query(int root,int l,int r)
{
    if(l==seg[root].ls&&r==seg[root].rs)
    {
        return seg[root].val;
    }
    int mid=(seg[root].ls+seg[root].rs)>>1;
    if(l>mid)
    {
        return query(rson,l,r);
    }
    else
    {
        if(mid>=r)
        {
            return query(lson,l,r);
        }
        else
        {
            return max(query(lson,l,mid),query(rson,mid+1,r));
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,1,n);
        while(m--)
        {
            char kd;
            scanf("\n%c",&kd);
            if(kd=='Q')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,l,r));
            }
            if(kd=='U')
            {
                int pos,val;
                scanf("%d%d",&pos,&val);
                update(1,pos,val);
            }
        }
    }
}
