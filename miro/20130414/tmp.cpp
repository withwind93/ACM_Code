#include <stdio.h>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;
#define N 510
int map[N][N];
int pre[N];
int n,np,nc,m;
queue<int> que;
bool bfs(int s,int d)//source  destination
{
	memset(pre,-1,sizeof(pre));
	while(!que.empty())
	  que.pop();
	pre[s]=0;
	int index;
	que.push(s);
	while(!que.empty())
	{
		index=que.front();
		que.pop();
		for(int i=0;i<=1+n;++i)
		{
			if(pre[i]==-1 && map[index][i]>0)//只要没被遍历过+map是有容量的。就可以当做路来走
			{
				pre[i]=index;
				if(i==d)
				  return true;//可能并不需要遍历完。就可以到达des
				que.push(i);
			}
		}
	}
	return false;
}

int MaxFlow(int s,int d)
{
	int maxflow=0;
	while(bfs(s,d))
	{
		int minflow=INT_MAX;
		for(int i=d;i!=s;i=pre[i])
/*des必定可以找到一条增广路径到达src，，因为pre存的是之前的那个点。所以不可能从source开始到des。而是des到source。并把这条路的最小容量算出来*/
		  minflow=min(minflow,map[pre[i]][i]);
		for(int i=d;i!=s;i=pre[i])
		{
			map[pre[i]][i]-=minflow;//反向边为负数
			map[i][pre[i]]+=minflow;
		}
/*		for(int i=0;i<=1+n;++i)
		{
			for(int j=0;j<=1+n;++j)
				printf("(%d,%d)%5d",i,j,map[i][j]);
			printf("\n");
		}
		printf("*****\n");
*/		maxflow+=minflow;
	}
	return maxflow;
}

int main()
{
	int src,des;
	int u,v,w;
	int x[200],y[200],va[200];
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:\n",cas++);
		scanf("%d %d",&n,&m);
		memset(map,0,sizeof(map));

		src=0;des=n-1;
		int first = 1;
		int tmp,last;
		for(int i=0;i<m;i++)
		{
			memset(map,0,sizeof(map));
			
			scanf("%d %d %d",&u,&v,&w);
			u--;v--;
			map[u][v]+=w;
			map[v][u]+=w;
			x[i] = u;y[i] = v;va[i] = w;
			for(int j = 0;j<i;j++)
			{
				map[x[j]][y[j]] += va[j];
				map[y[j]][x[j]] += va[j];
			}

			tmp = MaxFlow(src,des);
			if(tmp != 0 && first)
			{
				first = 0;
				last = tmp;
				printf("%d %d\n",i+1,tmp);
			}
			if(first == 0 && last != tmp)
			{
				printf("%d %d\n",i+1,tmp-last);
				last = tmp;
			}
		}
	}
	return 0;
}

