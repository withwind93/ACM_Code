#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 30010
int v[N],va[N];
vector<int> g[N];
int out[N];
int res[N];
int stack[N],top=0;
bool instack[N];
int dfn[N];
int low[N];
int number = 0;/*ComponentNumber强连通分量*/
int index = 0;
vector <int> edge[N];
vector <int> component[N];/*强连通的结果*/
int incomponent[N];
int componentDegree[N];/*强连通分量的度*/
void tarjan(int now)
{
//	printf("now = %d\n",now);
	int i,j,k;
	int next;
	dfn[now] = low[now] = ++index;/*时间戳*/
	instack[now] = true;
	stack[++top] = now;
	for(int e = 0;e<edge[now].size();e++)
	{
		next = edge[now][e];
		if(dfn[next] == 0)/*没有遍历过*/
		{
			tarjan(next);
			low[now] = min(low[now],low[next]);/*next为now的一个子女*/
		}
		else if(instack[next])
		  low[now] = min(low[now],dfn[next]);/*存在回边，得到更小的时间戳*/
	}
	if(dfn[now] == low[now])
	{
		number++;
		component[number].clear();
		do
		{
			next = stack[top--];
			instack[next] = false;
			component[number].push_back(next);
			incomponent[next] = number;
			if(v[next]<0)	continue;
			va[number] += v[next];
	//		printf("%d va =  %d next = %d\n",number,va[number],next);
		//	printf("in [ %d ] = %d\n ",next,number);
		}while(next!=now);
	}
/*	if(low[now] >= dfn[now])
	{
		printf("\n");
		do
		{
			next = stack[top--];
			printf("%d  ",next);
		}while(next != now);
	}*/
}
void solve(int n)/*N为图中点的个数*/
{
	memset(stack,0,sizeof(stack));
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	number = 0;
	top = 0;
	index = 0;
	for(int i=1;i<=n;i++)
	{
		if(dfn[i] == 0)
		  tarjan(i);
	}
}
int ans;
int vis[N];
void dfs(int now,int count)
{
//	printf("now = %d %d\n",now,g[now].size());
	for(int i=0;i<g[now].size();i++)
	{
		int next = g[now][i];
		dfs(next,count+va[next]);
		if(count>ans)
		  ans = count;
	}
	if(count>ans)
	  ans = count;
}

int main()
{
	int i,j,k;
	int n,m;
	int x,y;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(v,0,sizeof(v));
		memset(va,0,sizeof(va));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			
			g[i].clear();
			edge[i].clear();
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			x++;y++;
			int flag=0;
			for(j=0;j<edge[x].size();j++)
			  if(edge[x][j]==y)
			  {
				  flag=1;
				  break;
			  }
			if(flag) continue;
			edge[x].push_back(y);
		}
		solve(n);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<edge[i].size();j++)
			{/*i j存在边*/
				int child = edge[i][j];
				if(incomponent[i] == incomponent[child])	continue;
			//	printf("i = %d %d\n",incomponent[i],incomponent[child]);
				g[incomponent[i]].push_back(incomponent[child]);
			//	printf("size = %d\n",g[incomponent[i]].size());
			}
		}
		ans = 0;
		for(i=1;i<=number;i++)
		{
			dfs(i,va[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}





