/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/21 23:26:54
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[100010];
int main()
{
	int i,j,k;
	int n;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		a[i] = i;
	}
	k++;
	int tmp=1;
	for(i=k;i>=1;i--)
	{
		a[i]=tmp++;
	}
	for(i=1;i<=n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d",a[n]);
	return 0;
}
