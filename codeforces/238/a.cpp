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
int a[1000010];

int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i = 1;i <= n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n]);
	return 0;
}
