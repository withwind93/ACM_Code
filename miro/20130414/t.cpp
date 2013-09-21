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
		for(v = cur[u]; v <= n; ++v) //Ѱ������
		{
			if(maze[u][v] > 0 && dis[u] == dis[v] + 1)
			{
				flag = true;
				break;
			}
		}
		if(flag) //�ҵ�����
		{
			pre[v] = u;
			cur[u] = v;
			aug = min(aug, maze[u][v]);
			u = v;
			if(v == t) //�ҵ���������·
			{
				maxflow += aug;
				for(v = t; v != s; v = pre[v]) //���²�������
				{
					maze[pre[v]][v] -= aug; //�����
					maze[v][pre[v]] += aug; //�����
				}
				aug = MAX, u = s; //���´�Դ��Ѱ��
			}
		}
		else //�Ҳ�������
		{
			int mindis = n;
			for(v = 1; v <= n; ++v) //���±��
			{
				if(maze[u][v] && mindis > dis[v])
				{
					cur[u] = v;
					mindis = dis[v];
				}
			}
			if(--gap[dis[u]] == 0) //���¶ϲ� + �ж��Ƿ�ϲ㣨��϶�Ż���
				break;
			gap[dis[u] = mindis + 1]++; //���¶ϲ�
			u = pre[u]; //��ǰ���Ż�
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



