/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/13 20:57:14
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg unsigned long long
llg c[1010][1010];

int main()
{
	int i,j,k;
	memset(c,0,sizeof(c));
	c[1][0] = c[1][1] = 1;
	for(i=1;i<=1001;i++)
	{
		c[i][0] = c[i][i] = 1;
		for(j=1;j<i;j++)
	  {
		c[i][j] = c[i-1][j]+c[i-1][j-1];
	//	double tmp = (double)c[i][j];
	//	printf("i = %d j = %d c = %lf \n",i,j,tmp);
	  }
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,tmp;
		scanf("%d%d",&n,&m);
		if(n>m)	{tmp = n;n = m;m = tmp;}

		llg tm = c[n+m][n];
//		printf("c = %d  ",c[n+m][n]);
		tm = tm/(n+m)*(n+1);
		printf("%llu\n",tm);
	}
	return 0;
}
