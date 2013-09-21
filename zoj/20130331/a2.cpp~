#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100005
int sum[MAXN<<2];
bool lazy[MAXN<<2];
struct Node
{
    int fa,son,bro;
}tree[MAXN];
int cnt,pos[MAXN],son[MAXN];
void pretravel(int k)
{
    pos[k]=cnt++;
	printf("pos [ %d ] = %d\n",k,cnt);
    if(tree[k].son)
        pretravel(tree[k].son);
    if(tree[k].bro)
        pretravel(tree[k].bro);
    son[tree[k].fa]+=son[k]+1;
}
void pushdown(int l,int r,int rt)
{
    if(lazy[rt])
    {
        int m=(l+r)>>1;
        lazy[rt<<1]^=1;
        lazy[rt<<1|1]^=1;
        sum[rt<<1]=(m-l+1)-sum[rt<<1];
        sum[rt<<1|1]=(r-m)-sum[rt<<1|1];
        lazy[rt]=0;
    }
}
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void update(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        sum[rt]=r-l+1-sum[rt];
        lazy[rt]^=1;
        return;
    }
    pushdown(l,r,rt);
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,l,m,rt<<1);
    if(R>m)
        update(L,R,m+1,r,rt<<1|1);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    int res=0;
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    pushdown(l,r,rt);
    int m=(l+r)>>1;
    if(L<=m)
        res+=query(L,R,l,m,rt<<1);
    if(R>m)
        res+=query(L,R,m+1,r,rt<<1|1);
    pushup(rt);
    return res;
}
int main()
{
    freopen("in","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        memset(sum,0,sizeof(sum));
        memset(pos,0,sizeof(pos));
        memset(son,0,sizeof(son));
        cnt=1;
        int p;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&p);
            if(tree[p].son==0)
            {
                tree[p].son=i;
                tree[i].fa=p;
            }
            else
            {
                tree[i].bro=tree[tree[p].son].bro;
                tree[tree[p].son].bro=i;
                tree[i].fa=p;
            }
        }
		for(int i=1;i<=n;i++)
		{
			printf("i = %d fa = %d son = %d  bro = %d\n",i,tree[i].fa,tree[i].son,tree[i].bro);
		}
        pretravel(1);
        while(m--)
        {
            char str[5];
            int x;
            scanf("%s%d",str,&x);
            if(str[0]=='o')
            {
                update(pos[x],pos[x]+son[x],1,n,1);
            }
            else
            {
                printf("%d\n",query(pos[x],pos[x]+son[x],1,n,1));
            }
        }
        printf("\n");
    }
}

