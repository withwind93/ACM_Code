/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/10 23:21:27
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	int i,j,k;
	int x,y,a,b;
	int n;
	double min=1000000.0;
	scanf("%d %d %d",&x,&y,&n);
	double x1 = (x*1.0)/(y*1.0);

	double	tmin = x1;
	for(i = n;i>=1;i--)
	{
		int tb = i;
		int ta ;

		int t = (x*1.0/(y*1.0))*tb+0.5;
		ta = 0;
		j=t+2;
		for( ;j>=t-2 ;j--)
		{
			if(j<0)	break;
			double tmp = fabs(x1-(j*1.0)/(tb*1.0));
			if(tmp<=tmin)
			{
				tmin = tmp;
		//		printf("tmin  = %llf\n",tmin);
				ta = j;
				a = j;
				b = i;
			}
		}
	}
	printf("%d/%d\n",a,b);
	return 0;
}
