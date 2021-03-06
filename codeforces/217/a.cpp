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
int r1,c1,r2,c2;
int get(int x)
{
	if(x < 0)	x = -x;
	else		x = x;
	return x;
}
int main()
{
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	if(r1 == r2 && c1 == c2)	{printf("%d %d %d\n",cnt1,cnt2,cnt3);return 0;}
	
	if(r1 == r2 || c1 == c2)	cnt1 = 1;
	else						cnt1 = 2;

	int xx,yy;
	xx = get(r1 - r2),yy = get(c1 - c2);
	if((r1 + c1) % 2 != (r2 + c2) % 2)	cnt2 = 0;
	else
	{
		if(xx == yy)	cnt2 = 1;
		else			cnt2 = 2;
	}
	
	cnt3 = Max(xx,yy);

	printf("%d %d %d\n",cnt1,cnt2,cnt3);
	return 0;
}
