/*************************************************************************
    > File Name: t.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/14 15:22:40
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 210  
#define MAX 1<<28  
#define CLR(arr, what) memset(arr, what, sizeof(arr))  

int maze[N][N];
int pre[N], cur[N];
int gap[N];
int dis[N];
int source, sink, nodenum;

int SAP(int s, int t, int n)
{
	CLR(gap, 0); CLR(cur, 0); CLR(dis, 0);
	int u = pre[s] = s, maxflow = 0, aug = MAX, v;
	gap[0] = n;
	while(dis[s] < n)
	{
		bool flag = false;
		for(v = cur[u]; v <= n; ++v) //寻找允许弧
		{
			if(maze[u][v] > 0 && dis[u] == dis[v] + 1)
			{
				flag = true;
				break;
			}
		}
		if(flag) //找到允许弧
		{
			pre[v] = u;
			cur[u] = v;
			aug = min(aug, maze[u][v]);
			u = v;
			if(v == t) //找到完整增广路
			{
				maxflow += aug;
				for(v = t; v != s; v = pre[v]) //更新残留网络
				{
					maze[pre[v]][v] -= aug; //正向边
					maze[v][pre[v]] += aug; //反向边
				}
				aug = MAX, u = s; //重新从源点寻找
			}
		}
		else //找不到允许弧
		{
			int mindis = n;
			for(v = 1; v <= n; ++v) //重新标号
			{
				if(maze[u][v] && mindis > dis[v])
				{
					cur[u] = v;
					mindis = dis[v];
				}
			}
			if(--gap[dis[u]] == 0) //更新断层 + 判断是否断层（间隙优化）
				break;
			gap[dis[u] = mindis + 1]++; //更新断层
			u = pre[u]; //当前弧优化
		}
	}
	return maxflow;
}

int main()
{
	int n, m;
	int start, end, cost;
	int answer;
	int t;
	int cas =1;
	int x[201],y[210],va[210];
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:\n",cas++);
		scanf("%d%d", &m, &n);
		CLR(maze, 0);
		source = 1, sink = m, nodenum = m;
		int tmp,first=1,last;
		for(int i = 0; i < n; ++i)
		{
			CLR(maze, 0);
			scanf("%d%d%d", &start, &end, &cost);
			maze[start][end] += cost;
			
			x[i] = start;y[i] = end;va[i] = cost;
			for(int j = 0;j<i;j++)
			{
			//	map[x[j]][y[j]] = va[j];
				maze[x[j]][y[j]] += va[j];
			}
			

			tmp =  SAP(source, sink, nodenum);
		//	printf("tmp  = %d\n",tmp);
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



