/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/5 0:21:16
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
int a[100010];
int n,t;

int get(int end,int key)
{
	int low=0,high=end,mid=0;
	while(low<=high)
	{
		mid = (low+high)>>1;
		if(key<=a[mid])		high=mid-1;
		else				low=mid+1;
	}
//	printf("low = %d\n",low);
	return low;
}
int main()
{
	int i,j,k;

	scanf("%d %d",&n,&t);
	int ans=0;
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=t)	ans=1;
		a[i]+=a[i-1];
	}
//	printf("ans = %d\n",ans);
	for(i=1;i<=n;i++)
	{
		if(a[i]<=t)
		{
			if(ans<i)	ans=i;
			continue;
		}
		int num=get(i,a[i]-t);
		if(num==0)	continue;
		if(i-num>ans)
		  ans=i-num;
	}
	printf("%d\n",ans);
	return 0;
}
