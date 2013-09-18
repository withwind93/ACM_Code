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
int main()
{
	scanf("%d %d",&n,&m);
	int flag1 = 0,flag2 = 0;
	if(n < 0)	flag1 = 1,n = -n;
	if(m < 0)	flag2 = 1,m = -m;
	int s = n + m;
	if(flag1 == 0 && flag2 == 0)	printf("0 %d %d 0\n",s,s);
	else if(flag1 == 1 && flag2 == 0)	printf("-%d 0 0 %d\n",s,s);
	else if(flag1 == 0 && flag2 == 1)	printf("0 -%d %d 0\n",s,s);
	else if(flag1 == 1 && flag2 == 1)	printf("-%d 0 0 -%d\n",s,s);
	return 0;
}
