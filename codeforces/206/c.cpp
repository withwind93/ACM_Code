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
int n,k,mx,x,ans;
int hash[10000010],a[10000010];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i = 0;i < n;i++)
	{
		int x;
		scanf("%d",&x);
		hash[x]++;
		mx = Max(x,mx);
	}
	for(int i = 1;i <= mx + k;i++)
	{
		hash[i] = hash[i-1] + hash[i];
	}
	for(int i = mx;i >= 1;i--)
	{
		int cnt = 0;
		for(int j = i;j <= mx;j+=i)
		{
			int left = j-1,right = j+Min(i-1,k);
			//在(left,right]可以存在
			//就是将区间分段,然后进行统计
			cnt += (hash[right] - hash[left]);
		}
		if(cnt == n)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
