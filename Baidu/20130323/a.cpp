#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[10010];
int main()
{
	int i,j;
	int n,k;
	int sum,tmax;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==0 && k==0)	break;
		sum = 0;tmax = INT_MIN;
		for(i=1;i<=n;i++)
		{
	//		scanf("%d",&a[i]);
			a[i] = i; 
			sum+=a[i];
			tmax = max(tmax,a[i]);
		}
		/*在tmin 和 sum中二分*/
		int low = tmax,high = sum,mid,ans=-1;
		while(low<=high)
		{
			mid = (low+high)>>1;
			int s = 0,count = 0;//s表示部分和
			int now = 1;
			while(now<=n)
			{
				s+=a[now];
				if(s>mid)/*部分和超出界限*/
				{
					count++;
					s = a[now];
				}
				if(count == k)	break;
				now++;
			}
			if(now == n+1)/*符合 条件 n个分给了k组*/
			  ans=mid,high = mid-1;/*尝试更小*/
			else
			  low = mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
