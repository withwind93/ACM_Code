#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
const int maxn = 100;
struct edge
{
	int from,to;
}edge[maxn + maxn];
int cnt,num[maxn];//the number of edge

void add(int x,int y)
{//x min = 1
	edge[cnt].from = x;
	edge[cnt].to = num[y];
	num[y] = cnt++;

	edge[cnt].from = y;
	edge[cnt].to = num[x];
	num[x] = cnt++;
}

void dfs(int fa,int now)
{
	for(int son = num[now];son != 0;son = edge[son].to)
	{
		if(son == fa)	continue;
		dfs(now,son);
		printf("%d\n",son);
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;i++)
	{
		int  x,y;
		scanf("%d %d",&x,&y);
		add(x,y);
	}
	dfs(-1,1);
	return 0;
}
