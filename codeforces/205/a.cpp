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
int a[110],b[110];
int main()
{
	scanf("%d",&n);
	int sum1 = 0,sum2 = 0;
	int flag = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		sum1+=a[i];sum2+=b[i];
		if(a[i]%2 ==0 && b[i] %2 ==1)	flag = 1;
		if(b[i]%2 ==0 && a[i] %2 ==1)	flag = 1;
	}
	if(n == 1)
	{
		if(sum1 % 2 == 0 && sum2 % 2== 0)		printf("0\n");
		else									printf("-1\n");
		return 0;
	}
	if(sum1 % 2 == 0 && sum2 % 2== 0)		printf("0\n");
	else if(sum1 % 2 == 0 && sum2 % 2 == 1)	printf("-1\n");
	else if(sum1 % 2 == 1 && sum2 % 2 == 0)	printf("-1\n");
	else 
	{
		if(flag)	printf("1\n");
		else		printf("-1\n");
	}
	return 0;
}
