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
int n,a[2000],ans,l[3],r[3];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	int left,right;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != i)
		{
			left = i;
			for(int j = i + 1;j <= n;j++)
			{
				if(a[j] == i)
				{
					right = j;
					break;
				}
			}
			if(left > right)
			{
				int tmp = left;
				left = right;
				right = tmp;
			}
			l[ans] = left;r[ans++] = right;
			for(int p = 0;p < (right - left + 1)/2;p++)
			{
				int tmp = a[left + p];
				a[left + p] = a[right - p];
				a[right - p] = tmp;
			}
			for(int i = 1;i <= n;i++)
			{
				printf("%10d",a[i]);
				if(i%10 == 0)	printf("\n");
			}
			printf("\n");
		}
	}
			printf("%d\n",ans);
		for(int i = 0;i < ans;i++)
		  printf("%d %d\n",l[i],r[i]);
	return 0;
}
