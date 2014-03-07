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
int a[1000000];
int gcd(int a,int b)
{return b == 0 ? a : gcd(b,a%b);}
int main()
{
	scanf("%d",&n);
	int flag = 1;
	int sum = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	flag = gcd(a[0],a[1]);
	for(int i = 2;i < n;i++)
	{
		flag = gcd(flag,a[i]);
	}
	int cnt = a[n-1]/flag - n;
	if(cnt%2)	printf("Alice\n");
	else		printf("Bob\n");
	return 0;
}


