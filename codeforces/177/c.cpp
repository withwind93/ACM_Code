/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/3 0:12:29
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int i,j,k;
	int n;
	scanf("%d%d",&n,&k);
	if(n==1 && k==1)
	{
		printf("a\n");
		return 0;
	}
	if(n<k || k==1){
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n-k+2;i++)
	{
		if(i%2==1)	printf("a");
		else		printf("b");
	}
	for(i=1;i<=k-2;i++)
	{
		printf("%c",'b'+i);
	}
	printf("\n");
	return 0;
}
