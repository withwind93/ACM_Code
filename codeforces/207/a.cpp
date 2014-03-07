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
int a[10000010];
int x,y;
int main()
{
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	scanf("%d %d",&x,&y);
	int tmp = 0;
	int ans = 0;
	for(ans = 1;ans <= n;ans++)
	{
		tmp += a[ans];
		if(tmp >= x && tmp <= y && (sum - tmp) >= x && (sum - tmp) <= y)
		{
			break;
		}
	}
	if(ans == n || ans == n+1)	printf("0\n");
	else			printf("%d\n",ans+1);
	return 0;
}
