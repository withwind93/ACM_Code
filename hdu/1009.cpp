#pragma comment(linker, "/STACK:1024000000,1024000000") 
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
vector<int> next[1000010];
int ans = 0;
int dfs(int fa,int now)
{
	int sum = 0;
	for(int i = 0;i < next[now].size();i++)
	{
		int son = next[now][i];
		if(son == fa)	continue;
		sum += dfs(now,son);
	}
	if(now == 1)	
	{
		if(sum == 0)	{ans++;return 0;}
		if(sum == 1)	{ans++;return 0;}
		if(sum == 2)	{ans++;return 0;}
		if(sum > 2)	
		{
			ans += (sum-2)*2 + 1;
			return 0;
		}
	}
	else
	{
		if(sum == 0)	return 1;
		if(sum == 1)	return 1;
		if(sum == 2)	{ans+=2;return 1;}
		if(sum > 2)		{ans+=(sum - 1)*2;return 1;}
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i =1;i <= n;i++)
		  next[i].clear();
		for(int i = 1;i <= n-1;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			next[x].push_back(y);
			next[y].push_back(x);
		}
		ans = 0;
		dfs(-1,1);
		printf("%d\n",ans);
	}
	return 0;
}
