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
const int maxn = (1<<17) + 10;
int a[maxn];
int tree[300000];
int next[300000],maxnext;
int n,m;
int p,b;

void bfs(int now,int flag)
{
	if(now >= (1<<n))	return ;

	bfs(now*2,1-flag);
	bfs(now*2 + 1,1-flag);
	if(flag == 0)	tree[now] = tree[now*2] | tree[now*2 + 1];
	else			tree[now] = tree[now*2] ^ tree[now*2 + 1];
}
int bfs2(int now,int flag,int i)
{
	if(now >= (1<<n))	return 0;

	bfs2(now*2 + next[maxnext-i],1-flag,i+1);
	
	if(flag == 0)	tree[now] = tree[now*2] | tree[now*2 + 1];
	else			tree[now] = tree[now*2] ^ tree[now*2 + 1];
	
	//printf("now = %d %d\n",now,tree[now]);
	return tree[now];
}

int main()
{
	scanf("%d %d",&n,&m);
	int index = 1<<n;
	for(int i = 1;i <= (1<<n);i++)
	{
		scanf("%d",&a[i]);
		tree[index + i - 1] = a[i];
	}
	bfs(1,(n+1)%2);
	int ans = 0;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d %d",&p,&b);
		//int tmp = a[p];
		tree[index + p - 1] = b;
		maxnext = 0;
		p = index + p - 1;
		while(p)
		{
			next[maxnext++] = p%2;
			p/=2;
		}
		ans = bfs2(1,(n+1)%2,2);
		//tree[index + p - 1] = tmp;
		printf("%d\n",ans);
	}
	return 0;
}
