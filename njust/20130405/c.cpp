/*1.如果点v是DFS序列的根节点，则如果v有一个以上的孩子，则v是一个割点。
 *2.如果v不是DFS序列根节点，并且点v的任意后继u能追溯到最早的祖先节点low[u]>=dfn[v]，则v是一个割点。
 * */
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 110
int edge_num[N],edge[N][N];
int dfn[N],time;
int low[N];
int degree[N];
int ans;
int count_num[N];
void tarjan(int now,int father)
{
	dfn[now] = low[now] = ++time;
	int out = 0 ,ok = 0;
	for(int i=0;i<edge_num[now];i++)
	{
		int next = edge[now][i];
	//	printf("now = %d next = %d\n",now,next);
		if(next != father)
		{
//			printf("next = %d father = %d\n",next,father);
			if(dfn[next] == 0)
			{
//				printf("next = %d %d\n",next,out);
				out++;
				tarjan(next,now);
				if(low[now] > low[next])
				{
					low[now] = low[next];
				}
				else if(low[next] >= dfn[now])/*第二种情况，可以帮助自己子孙回溯到祖先*/
						ok = 1;
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
	if(father == 0)
	{
		if(out > 1)	count_num[now] = 1;/*第一种情况，根结点只要有二个孩子*/
	}
	else	count_num[now] = ok;
//printf("u = %d out = %d ok = %d is = %d\n",now,out,ok,count_num[now]);
}
void solve(int n)
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(count_num,0,sizeof(count_num));
	time = 0;
	ans = 0;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
}


int main()
{
	int i,j,k;
	int n,m;
	int x,y;
	while(scanf("%d",&n)!=EOF)
	{
		memset(edge_num,0,sizeof(edge_num));
		while(1)
		{
			scanf("%d %d",&x,&y);
			if(x == -1 && y == -1)	break;
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
		solve(n);
		ans = 0;
		for(i=1;i<=n;i++)
		  ans+=count_num[i];
		printf("%d\n",ans);
	}
	return 0;
}



