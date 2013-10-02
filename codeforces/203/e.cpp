#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}

int n,k,m,x,pos,alone;
bool vis[310];
vector< pair<int,int> > risan;

int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%d %d %d",&n,&m,&k);
	if(k == n)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 0;i < k;i++)
	{
		scanf("%d",&x);
		vis[x] = 1;
		alone = x;
	}
	for(int i = 1;i <= n;i++)
	  if(vis[i] == false)	pos = i;
	for(int i = 1;i <= n;i++)
	{
		if(i != pos)	
		  risan.push_back(make_pair(pos,i));
	}
	for(int i = 1;i <= n;i++)
	{
		if(i != pos && vis[i] == false)
		{
			risan.push_back(make_pair(i,alone));
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			if(i != alone && j != alone && i!=pos && j != pos)
			  risan.push_back(make_pair(i,j));
		}
	}
	if(risan.size() < m)	printf("-1\n");
	else
	{
		for(int i = 0;i < m;i++)
		{
			printf("%d %d\n",risan[i].first,risan[i].second);
		}
	}
	return 0;
}
