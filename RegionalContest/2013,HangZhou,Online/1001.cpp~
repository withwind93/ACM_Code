#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 1001
#define INF 0x3f3f3f3f
struct node
{
    int v,id,cnt,weight;
    struct node *next;
};
struct node *list[N];
char vis[N];
int dfn[N],low[N],father[N],n,m,id,ans[N],num;
int cnt;
int findEdge(int u,int v)
{
    struct node *p=list[u];
    while(p)
    {
        if(p->v==v)
        {
            p->cnt++;
            return 1;
        }
        p=p->next;
    }
    return 0;
}
void addEdge(int u,int v,int id,int weight)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->id=id;
    p->v=v;
	p->weight=weight;
    p->next=0;
    p->cnt=1;
    if(list[u])
    {
        p->next=list[u];
        list[u]=p;
    }
    else    list[u]=p;
}
void init()
{
    memset(vis,0,sizeof(vis));
    memset(father,0,sizeof(father));
    dfn[1]=low[1]=id=1;
    vis[1]=1;
    num=0;
	cnt=1;
}
void dfs(int u)
{
    int v;
    struct node *p=list[u];
    while(p)
    {
        v=p->v;
        if(father[u]!=v)
        {
            if(vis[v])  low[u]=MIN(low[u],dfn[v]);
            else
            {
                father[v]=u;
                vis[v]=1;
				cnt++;
                id++;
                dfn[v]=low[v]=id;
                dfs(v);
                low[u]=MIN(low[v],low[u]);
                if(dfn[u]<low[v]&&p->cnt==1)
                {
                    ans[num++]=p->weight;
                }
            }
        }
        p=p->next;
    }
}
int main()
{
    int i,t,a,b,f,w;
    struct node *p;
    while(1)
    {
        scanf("%d%d",&n,&m);
		if(n==0 && m==0) break;
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            f=findEdge(a,b)+findEdge(b,a);
            if(!f)
            {
                addEdge(a,b,i,w);
                addEdge(b,a,i,w);
            }
        }
        init();
        dfs(1);
       	int min=INF;
		for(i=0;i<num;i++)
			if(min>ans[i])
				min=ans[i];
	//	cout<<"count="<<count<<endl;
		if(cnt!=n)
			printf("0\n");
		else if(min==INF)
			printf("-1\n");
		else
		{
			if(min == 0)	min++;
			printf("%d\n",min);
		}
		for(i=1; i<=n; i++)
        {
            p=list[i];
            while(p)
            {
                list[i]=p->next;
                free(p);
                p=list[i];
            }
        }
    }
    return 0;
}
