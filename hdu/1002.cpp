#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
#define maxn 100010
struct no
{
	vector<int> next;
}node[maxn];
void add(int x,int y)
{
	node[x].next.push_back(y);
	node[y].next.push_back(x);
}
int n,d;
int ans = 0;
int dfs(int fa,int now,int dis)
{
	for(int i = 0;i < node[now].next.size();i++)
	{
		int son = node[now].next[i];
		//printf("son = %d %d\n",son,dis);
		if(fa == son)	continue;
		if(dis == d)	{ans++;continue;}
		ans++;
		dfs(now,son,dis+1);
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 1;
		scanf("%d%d",&n,&d);
		for(int i = 1;i <= n;i++)
		  node[i].next.clear();
		for(int i = 1;i <= n-1;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			x++;y++;
			add(x,y);
		}
		dfs(-1,1,1);
		printf("%d\n",n - ans);
	}
	return 0;
}
