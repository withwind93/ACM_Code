#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
using namespace std;

int main()
{
	int a[4][4];
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
		scanf("%d",&a[i][j]);
	int count=(a[1][2]+a[3][2])/2;
	int sum=3*count;
	printf("%d ",sum-a[1][2]-a[1][3]);	printf("%d ",a[1][2]);	printf("%d\n",a[1][3]);
	printf("%d ",a[2][1]);	printf("%d ",sum-a[2][1]-a[2][3]);	printf("%d\n",a[2][3]);
	printf("%d ",a[3][1]);	printf("%d ",a[3][2]);	printf("%d\n",sum-a[3][1]-a[3][2]);
	return 0;
}

