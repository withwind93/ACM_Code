/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/21 18:49:55
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[20];
int main()
{
	int i,j,k;
	int c,n;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(i = 1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		int t = 6*a[1];
		t = t+5;
		t++;
		for(i=2;i<=n;i++)
		{
			if(a[i-1] == a[i])	{t++;continue;}
			if(a[i-1] <a[i])	
			{
				t=t+6*(a[i]-a[i-1]);
			}
			else
			{
				t=t+4*(a[i-1]-a[i]);
			}
			t =t+5;
			t++;
		}
		t = t+a[n]*4;
		printf("%d\n",t);
	}
	return 0;
}
