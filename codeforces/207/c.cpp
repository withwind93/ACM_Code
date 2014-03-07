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
int n,m;
int a[100010],b[100010],c[100010];
struct no
{
	int fa,next;
	int ans;
}node[100010];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		node[i].fa = i-1;
		node[i].next = i+1;
	}
	if(node[1].ans)	node[0].next = node[1].next;
	else			node[0].next = 1;
	
	for(int i = 1;i <= m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		int star = node[x].fa;
		for(int k = star;k <= y;k = node[k].next)
		{
			if(k < x)	continue;
			if(k == z)	continue;
			if(node[k].ans)	continue;
			node[k].ans = z;
		}
		for(int k = x;k < z;k++)
		{
			node[k].fa = x-1;
			node[k].next = z; 
		}
		node[z].fa = x-1;
		node[z].next = y+1;
		for(int k = z+1;k <= y;k++)
		{
			node[k].fa = z;
			node[k].next = y+1; 
		}
		if(node[1].ans)	
		{
			node[0].next = node[1].next;
		}
		else			node[0].next = 1;
	}
	for(int i = 1;i <= n;i++)
	{
		printf("%d ",node[i].ans);
	}
	return 0;
}

