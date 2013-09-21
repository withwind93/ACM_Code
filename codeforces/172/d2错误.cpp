/*************************************************************************
    > File Name: d2.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/11 9:48:49
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int max1[100010],max2[100010];
int min1[100010],min2[100010];
int a[100010];
int main()
{
	int i,j,k;
	int n;
	int ans=0;
	scanf("%d",&n);
	for(i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans = max(ans,a[i]);
		if(i==1)
		{
			max1[i]=a[i];
			min1[i]=a[i];
		}
		else
		{
			max1[i] = max1[i-1];
			if(max1[i-1]<a[i])
				max1[i]=a[i];
			
			if(a[i]==max1[i])		min1[i] = max(max1[i-1],min1[i-1]);
			else					min1[i] = max(min1[i-1],a[i]);

		}
	}
	for(i = n;i>=1;i--)
	{
		if(i==n)
		{
			max2[i]=a[i];
			min2[i]=a[i];
		}
		else
		{
			max2[i] = max2[i+1];
			if(max2[i+1]<a[i])	max2[i]=a[i];
			
			if(a[i]==max2[i])		min2[i] = max(max2[i+1],min2[i+1]);
			else					min2[i] = max(min2[i+1],a[i]);
		}
	}
	for(i = 1;i<=n;i++)
	{
		printf("max = %d %d min = %d %d\n",max1[i],max2[i],min1[i],min2[i]);
		ans = max(ans,max1[i]^min1[i]);
		ans = max(ans,max2[i]^min1[i]);
		ans = max(ans,max1[i]^min2[i]);
		ans = max(ans,max2[i]^min2[i]);
	}
	printf("%d\n",ans);

	return 0;
}
