#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
char str[20][20];
bool map1[20],map2[21];

int main()
{
	int i,j,k;
	int r,n;
	scanf("%d%d",&r,&n);
	for(i = 0;i < r;i++)
	{
		scanf("%s",str[i]);
		int flag = 0;
		for(j = 0;j < n;j++)
		{
			if(str[i][j] == 'S')
			{
				//flag = 1;
				map1[j] = 1;//shu
				break;
			}
		}
	}
	for(i = 0;i < n;i++)
	{
		int flag = 0;
		for(j = 0;j < r;j++)
		{
			if(str[j][i] == 'S')
			{
				map2[i] = 1;
				break;
			}
		}
	}
	int ans = 0;
	int ans1 = 0,ans2 = 0;
	for(i = 0;i < n;i++)
	{
		if(map1[i] == 0)
		{
			ans1++;
			ans = ans+r;
		}
	}
	//printf("ans  1 = %d\n",ans);
	for(i = 0;i < r;i++)
	{
		if(map2[i] == 0)
		{
			ans = ans + n - ans1;
		//	printf("i = %d\n",i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
