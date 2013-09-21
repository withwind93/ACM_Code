/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/11 23:26:33
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[110];
int f[1010];
int main()
{
	int i,j,k;
	int n;
	int max = 0;
	scanf("%d",&n);
	int flag = 0;
	k = 1;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
	{
	  scanf("%d",&a[i]);
		f[a[i]]++;
		if(f[a[i]]>max) max = f[a[i]];
	}

	if(n==1)	{printf("YES\n");return 0;}
//	printf("%d %d\n",max,n);
	if(max*2 > n+1)
		printf("NO\n");
	else
	  printf("YES\n");
	return 0;
}
