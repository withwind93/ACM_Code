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
char str[1000];
int main()
{
	int n;
	scanf("%d",&n);
	int sum = n*n + 1;
	int p = 0;
	int count = 1;
	for(int i = 1;i <= n;i++)
	{
		int first = 1;
		for(int j = 1;j <= n/2;j++)
		{
			if(first)	{printf("%d %d",count,sum-count);first = 0;}
			else		printf(" %d %d",count,sum-count);
			count++;
		}
		printf("\n");
	}
	return 0;
}
