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
int n;
int a[1010][1010];
int cal()
{
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int t = 0;
		for(int j = 1;j <= n;j++)
		{
			int x = j, y = i;
			t = (t + a[i][j]*a[x][y]) % 2;
		}
		ans = (ans + t) % 2;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		  scanf("%d",&a[i][j]);
	}
	int q;
	scanf("%d",&q);
	int now = cal();
//	printf("%d\n",now);
	while(q--)
	{
		int c,t;
		scanf("%d",&c);
		if(c == 3)	printf("%d",now);
		if(c == 1){
			scanf("%d",&t);
			now = 1 - now;
		}
		if(c == 2){
			scanf("%d",&t);
			now = 1 - now;
		}
	}
	return 0;
}

