#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
using namespace std;
#define LL long long
int main()
{
	int i,j,k;
	int t,tmp;
	int a[5][5];
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		  a[i][j]=0;
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		  scanf("%d",&a[i][j]);
	}
	
	int f[9][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			tmp=0;
			for(k=0;k<=4;k++)
			{
				tmp+=a[i+f[k][0]][j+f[k][1]];
			}
			if(tmp%2==0 || tmp==0)	printf("1");
			else					printf("0");
		}
		printf("\n");
	}
	return 0;
}



