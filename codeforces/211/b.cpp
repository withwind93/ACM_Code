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
int n,k;
int a[1000000 + 10];
int sum[1000000 + 10];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]+a[i];
	//	printf("%d\n",sum[i]);
	}
	int ans = 0;
	int maxn = sum[k];
	for(int i = 0;i <= n - k;i++)
	{
		int tmp = sum[i+k] - sum[i];
	//printf("i = %d  %d\n",i,tmp);
		if(tmp < maxn)
		{
			maxn = tmp;
			ans = i;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}

