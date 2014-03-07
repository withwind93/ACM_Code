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
int dp[100010];
int n,m;
struct tree
{
	vector<int> child;
	int flag;
}node[100010];
void BFS(int fa,int now,int cnt)
{
	for(int i = 0;i < node[now].child.size();i++)
	{
		int son = node[now].child[i];
		if(son == fa)	continue;
		if(node[son].flag)
		  continue;
		if(dp[son] != 0 && dp[son] <= cnt)
		  continue;
		BFS(now,son,cnt+1);
		if(dp[son] == 0 || dp[son] > cnt)
		  dp[son] = cnt;
	}
}
void print()
{
	for(int i = 1;i <= n;i++)
	  printf("%d  ",dp[i]);
	printf("\n");
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		node[x].child.push_back(y);
		node[y].child.push_back(x);
	}
	node[1].flag = true;
	dp[1] = 0;
	BFS(-1,1,1);
	//print();
	for(int i = 1;i <= m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x == 2)	printf("%d\n",dp[y]);
		else		
		{
			node[y].flag = true;
			dp[y] = 0;
			BFS(-1,y,1);	
		//	print();
		}
	}
	return 0;
}
