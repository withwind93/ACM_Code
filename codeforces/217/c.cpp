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
int a[1000000];
int n,ans,m;
int cnt[110];
int dp[1000000];
int l[110],r[110];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int sum = 0;
	int maxn = 0, maxc = 0;
	for(int i =	1;i <= m;i++)
	{
		sum += cnt[i];
		if(maxn < cnt[i])
		{
			maxn = cnt[i];
			maxc = i;
		}
	}
	int tmp = sum / 2;
	for(int i = 1;i <= m;i++)
	  for(int j = tmp;j >= cnt[i];j--)
		dp[j] = Max(dp[j], dp[j - cnt[i]] + cnt[i]);
	ans = sum - dp[tmp] * 2;
	int left = ans;
	ans = n - ans;
	printf("%d\n",ans);
	
	for(int i = 1;i <= left;i++)
	  printf("%d %d\n",maxc,maxc);
	cnt[maxc] = cnt[maxc] - left;

	for(int i = 1;i <= m;i++)
	{
		while(cnt[i])	{
			l[i]++;
			r[i]++;
			cnt[i]--;
			//	printf("%d cnt = %d\n",i,cnt[i]);
		}
	}
	for(int i = left + 1;i <= n;i++)
	{
		int max1 = 0,max2 = 0,ans1 = 0,ans2 = 0;
		for(int j = 1;j <= m;j++)
		{
			if(max1 < l[j] && l[j]) 
			{
				max1 = l[j];
				ans1 = j;
			}
		}

		for(int j = 1;j <= m;j++)
		{
			if(j != ans1 && max2 < r[j] && r[j])
			{
				max2 = r[j];
				ans2 = j;
			}
		}
		printf("%d %d\n",ans1,ans2);
		l[ans1]--;r[ans2]--;
		//cnt[ans1]--;cnt[ans2]--;
	}
	return 0;
}

