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
int v;
int a[10];
int main()
{
	scanf("%d",&v);
	int minn = 2000000;
	int flag1;
	for(int i = 1;i <= 9;i++)
	{
		scanf("%d",&a[i]);
		if(minn >= a[i])
		{
			minn = a[i];
			flag1 = i;
		}
	}
	if(minn > v)
	{
		printf("-1\n");
		return 0;
	}
	int cnt = v / minn;
	int left = v - cnt*minn;
	for(int i = 9;i > flag1;i--)
	{
		int dis = a[i] - minn;
		if(dis <= 0)	continue;
		while(left >= dis && cnt >= 1)
		{
			printf("%d",i);
			left -= dis;
			cnt--;
		}
	}
	for(int i = 1;i <= cnt;i++)
	  printf("%d",flag1);
	printf("\n");
	return 0;
}

