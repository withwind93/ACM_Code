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
int a[10000000];
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	  scanf("%d",&a[i]);
	int flag25 = 0;
	int flag50 = 0;
	int flag100 = 0;
	if(a[0] != 25)	{printf("NO\n");return 0;}
	flag25++;
	int flag = 0;
	for(int i = 1;i < n;i++)
	{
		if(a[i] == 25)	flag25++;
		if(a[i] == 50)	
		{
			if(flag25==0)	{flag=1;break;}
			flag25--;
			flag50++;
		}
		if(a[i] == 100)
		{
			if(flag50 >= 1)
			{
				if(flag25 >= 1)	
				{
					flag50--;
					flag25--;
				}	
				else
				{
					flag=1;
					break;
				}
			}else
			{
				if(flag25 >= 3)
				{
					flag25 = flag25-3;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
	}
	if(flag)	printf("NO\n");
	else		printf("YES\n");
	return 0;
}
