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
int n;
const int maxn = 100010;
int t[maxn];
int child[maxn];
int fa[maxn];
int ans = -1;
int ansmax = 0;
int path[maxn];
bool vis[maxn];
int flag = 0;
int dfs(int now)
{
	if(vis[now])	return -1;
	vis[now] = true;
//	printf("now = %d\n",now);
	if(now == 0)	return 0;
	int f = fa[now];
	if(t[f] == -1)	return 0;
	if(t[f] == 1)	return 0;
	int tmp = dfs(f);
	if(tmp == -1)	
	{
		flag = 1;
		return 0;
	}
	else
		return tmp + 1;
}
int firstprint = 1;
void print(int now,int cnt)
{
	if(now == 0 || cnt == 0)	return;
	print(fa[now],cnt-1);
	if(firstprint)
	{
		printf("%d",now);
		firstprint = 0;
	}
	else
		printf(" %d",now);
}

int main()
{
	scanf("%d",&n);
	int ans = 0;
	t[0] = -1;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&t[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		int x,y = i;
		scanf("%d",&x);
		fa[y] = x;
		child[x]++;
	}
	for(int i = 1;i <= n;i++)
	{
		if(child[i] >= 2)
		  t[i] = -1;
	}
	for(int i = 1;i <= n;i++)
	{
		if(t[i] == 1)	
		{
			memset(vis,false,sizeof(vis));
			flag = 0;
			int tmp = dfs(i) + 1;
			/*if(flag==1)
			{
				ans = i;
				ansmax = 1;
				continue;
			}*/
			printf("flag = %d \n",flag);
			if(ansmax < tmp && flag == 0)
			{
				ans = i;
				ansmax = tmp;
			}
		}
	}
	printf("%d\n",ansmax);
	print(ans,ansmax);
	return 0;
}

