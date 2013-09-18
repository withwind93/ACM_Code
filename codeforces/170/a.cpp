/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/2/28 23:13:40
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
	int d[110];
int main()
{
	int i,j,k;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==b)	{printf("0\n");return 0;}
	int tmp;
	if(a>b)	{tmp=a;a=b;b=tmp;}
	int x=0,y=0;
	for(i=a;i<b;i++)
		x+=d[i];
	for(i=b;i<=n;i++)
		y+=d[i];
	for(i=1;i<a;i++)
		y+=d[i];
//printf("%d %d\n",x,y);
	if(x>y)	printf("%d\n",y);
	else	printf("%d\n",x);
	return 0;
}
