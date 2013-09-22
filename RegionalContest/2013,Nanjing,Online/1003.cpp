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
struct Node
{
	int x,y,va;
}node[10010];
int n,m;
int father[10010];
int num[10010];
int q;
struct ques
{
	int t,pos;
}qu[500010];
int ans[500010];
void init()
{
	for(int i = 0;i <= n;i++)
	{
		father[i] = i;
		num[i] = 1;
	}
}
int cmp1(Node a,Node b)
{	return a.va < b.va;}
int cmp2(ques a,ques b)
{	return a.t < b.t;}
int getfather(int x)
{
	if(x != father[x])	return getfather(father[x]);
	else	return x;
}
int main()
{
	int x,y,va;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		init();
		for(int i = 0;i < m;i++)
		{
			scanf("%d %d %d",&x,&y,&va);
			node[i].x = x;node[i].y = y;node[i].va = va;
		}
		sort(node , node + m,cmp1);
		scanf("%d",&q);
		for(int i = 0;i < q;i++)
		{
			scanf("%d",&qu[i].t);
			qu[i].pos = i;
		}
		sort(qu,qu + q,cmp2);
		int timeflag = 0;
		
		int sum = 0;
		for(int i = 0;i < q;i++)
		{
			while(timeflag < m && node[timeflag].va < qu[i].t)
			{
				int fx = getfather(node[timeflag].x),fy = getfather(node[timeflag].y);
				if(fx == fy)	{timeflag++;continue;}
				sum += num[fx]*num[fy]*2;
				num[fx] += num[fy];
				father[fy] = fx;
				timeflag++;
			}
			ans[qu[i].pos] = n*(n-1) - sum;
		}
		for(int i = 0;i < q;i++)
		  printf("%d\n",ans[i]);
	}
	return 0;
}
