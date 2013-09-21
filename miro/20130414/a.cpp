#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
using namespace std;


struct Network_sap{
#define Max_V 100000                 //最大点数
#define Max_E 200000             //最大边数
	int e,vs,vt;
	struct edge{int x,y,c;edge *next,*op;}*ls[Max_V],*fa[Max_V],*cur[Max_V],g[Max_E];
	int d[Max_V],num[Max_V];
#undef Max_V
#undef Max_E
	void init(){e=0; memset(ls,0,sizeof(ls));}
	void clear(){for (int i=0;i<e;i++) ls[g[i].x]=NULL; e=0;}
	void addedge(int x,int y,int c){
		g[e].x=x; g[e].y=y; g[e].c=c; g[e].next=ls[x]; ls[x]=&g[e]; g[e].op=&g[e+1];
		e++;
		g[e].x=y; g[e].y=x; g[e].c=0; g[e].next=ls[y]; ls[y]=&g[e]; g[e].op=&g[e-1];
		e++;
		//无向图加双边
		// /*
		swap(x,y);
		g[e].x=x; g[e].y=y; g[e].c=c; g[e].next=ls[x]; ls[x]=&g[e]; g[e].op=&g[e+1];
		e++;
		g[e].x=y; g[e].y=x; g[e].c=0; g[e].next=ls[y]; ls[y]=&g[e]; g[e].op=&g[e-1];
		e++;
		// */
	}
#define INF 0x7FFFFFFF
	int solve(int n){     //注意是从1到n这个范围有点
		int ans=0,i,nf;
		for (i=1;i<=n;i++) d[i]=0,num[i]=0,cur[i]=ls[i];
		for (i=vs,num[0]=n;d[vs]<n;){
			edge *&t=cur[i];
			while (t && !(t->c && d[t->y]+1==d[i])) t=t->next;
			if (t){
				fa[t->y]=t;
				i=t->y;
				if (i==vt){
					for (nf=INF;i!=vs;i=fa[i]->x) if (fa[i]->c<nf) nf=fa[i]->c;
					for (i=vt  ;i!=vs;i=fa[i]->x) {fa[i]->c-=nf; fa[i]->op->c+=nf;}
					ans+=nf;
				}
			}
			else{
				if (--num[d[i]]==0) return ans;   // gap
				d[i]=n;
				for (t=ls[i];t;t=t->next)
				  if (t->c && d[t->y]+1<d[i]) d[i]=d[t->y]+1;
				num[d[i]]++;
				t=ls[i];
				if (i!=vs) i=fa[i]->x;
			}
		}
		return ans;
	}
#undef INF
}Sap;

int main()
{
	int t,n,m;
	Sap.init();
	int cas = 0;
	scanf("%d", &t);
	while(t--)
	{
		printf("Case #%d:\n",++cas);
		Sap.clear();
		scanf("%d%d",&n,&m);
		Sap.vs = 1;
		Sap.vt = n;
		int u, v, va, maxflow = 0;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &u, &v, &va);
			Sap.addedge(u, v, va);
			int tmp = Sap.solve(Sap.vt);
			if(tmp)
			{
				printf("%d %d\n", i, tmp);
			}
		}
	}
	return 0;
}

