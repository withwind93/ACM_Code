#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 10010
int edge_num[N],edge[N][N];
int dfn[N],time;
int low[N];
int degree[N];
int ans;
void tarjan(int now,int father)
{
	dfn[now] = low[now] = ++time;
	for(int i=0;i<edge_num[now];i++)
	{
		int next = edge[now][i];
		printf("now = %d next = %d\n",now,next);
		if(next != father)
		{
			if(dfn[next] == 0)
			{
				tarjan(next,now);
				if(low[now] > low[next])
				  low[now] = low[next];
			}
			else
			{
				if(low[now] > dfn[next])
				{
					low[now] = dfn[next];
				}
			}
		}
	}
}
void solve()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	time = 0;
	tarjan(1,-1);
}

int get_ans(int n)
{
	memset(degree,0,sizeof(degree));
	int i,j;
	int now,next;
	for(i=1;i<=n;i++)
	{
		now = i;
		for(j=0;j<edge_num[i];j++)
		{
			next = edge[now][j];
			if(low[now] != low[next])
			{
				degree[low[now]]++;
				degree[low[next]]++;
			}
		}
	}
	int leaves=0;
	for(i=1;i<=n;i++)
	{
		if(degree[i] == 2)
		{
			leaves++;
		}
	}
	//printf("leave = %d\n",leaves);
	return (leaves+1)/2;
}

int main()
{
	int i,j,k;
	int n,m;
	int x,y;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(edge_num,0,sizeof(edge_num));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			int flag=0;
			for(j=0;j<edge_num[x];j++)
			  if(edge[x][j]==y)
			  {
				flag=1;
				break;
			  }
			if(flag)	continue;
			edge[x][edge_num[x]++]=y;
			edge[y][edge_num[y]++]=x;
		}
		solve();
		ans = get_ans(n);
		printf("%d\n",ans);
	}
	return 0;
}


