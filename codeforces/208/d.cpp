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
const int N = 3010;
int dp[N][2];//枚举到i位,第i-1位为0 or 1
int a[N],b[N],c[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	  scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++)
	  scanf("%d",&b[i]);
	for(int i = 1;i <= n;i++)
	  scanf("%d",&c[i]);
	if(n == 1)
	{
		printf("%d",a[1]);
		return 0;
	}
	dp[1][0] = a[1];
	dp[1][1] = -10000000;
	for(int i = 2;i <= n;i++)
	{//只有01，10两种情况,1表示先给兔子吃
		dp[i][0] = a[i] + Max(dp[i-1][0] - a[i-1] + b[i-1], dp[i-1][1] - b[i-1] + c[i-1]);
		dp[i][1] = b[i] + Max(dp[i-1][0], dp[i-1][1]);
	}
	int ans = 0;
	for(int i = 0;i < 2;i++)
	{
//		if(dp[n][i] > ans)	printf("i = %d ",i);
		ans = Max(ans,dp[n][i]);
	}
	printf("%d",ans);
	return 0;
}

