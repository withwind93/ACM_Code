/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/4 23:12:01
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
int a[1010][1010];
int main()
{
	int i,j,k;
	int n;
	int x,y;
	scanf("%d %d",&x,&y);
	if(x == 0 && y==0 )
	{
		printf("0\n");
		return 0;
	}
	int len = 0;
	int nowx=0,nowy=0;
	int xx=0,yy=0;
	memset(a,0,sizeof(a));
	for(i=1;i<=300;i+=2)
	{
		for(j=1;j<=i;j++)
		{
			xx++;
			a[200+xx][200+yy] = len;
	//		printf("%d %d  ",xx,yy);
		}
		len++;

		for(j=1;j<=i;j++)
		{
			yy++;
			a[200+xx][200+yy] = len;
	//		printf("%d %d  ",xx,yy);
		}
		len++;
		
		for(j=1;j<=i+1;j++)
		{
			xx--;
			a[200+xx][200+yy] = len;
	//		printf("%d %d  ",xx,yy);
		}
		len++;
		for(j=1;j<=i+1;j++)
		{
			yy--;
			a[200+xx][200+yy] = len;
	 //		printf("  %d %d",xx,yy);
		}
	//	printf("\n");
		len++;	
	}
	printf("%d\n",a[200+x][200+y]);
	return 0;
}
