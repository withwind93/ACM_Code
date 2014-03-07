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
int n,x[1000000],y[1000000];
int xcnt, ycnt;
int mx[110],my[110];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		//mp[x[i]][y[i]]++;
		mx[x[i]]++;
		my[y[i]]++;
	}
	
	for(int i = 0;i <= 100;i++)
	  if(mx[i])	xcnt++;
	for(int i = 0;i <= 100;i++)
	  if(my[i])	ycnt++;

	int ans = Min(xcnt,ycnt);
	printf("%d\n",ans);
	return 0;
}
