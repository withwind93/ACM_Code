/*************************************************************************
    > File Name: i.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/17 16:06:31
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int flag[100000000];
int main()
{
	int i,j,k;
	for(int i=1;i<=100;i++)
	  for(int j=i;j<=100;j++)
	  {
		flag[j*j-i*i]++;
	  }
	for(int i=0;i<=100;i++)
	{
	  printf("%d  ",flag[i]);
		if(i%10==0)	printf("\n");
	}
	return 0;
}
