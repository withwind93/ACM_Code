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
int a[110];
int b[110];
int main()
{
	int minx = 110,maxb = 110;
	int maxa = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		minx = minx > a[i] ? a[i] : minx;
		maxa = maxa > a[i] ? maxa : a[i];
	}
	for(int i = 0;i < m;i++)
	{
		scanf("%d",&b[i]);
		maxb = maxb > b[i] ? b[i] : maxb;
	}
	int ans = minx*2;
	if(ans < maxa)	ans = maxa;
	
//	printf("mina = %d %d %d %d\n",minx,maxa,maxb,ans);
	
	if(ans >= maxb)	printf("-1\n");
	else			printf("%d\n",ans);
	return 0;
}
