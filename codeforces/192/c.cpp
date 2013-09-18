#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int map[110][110];
int r[110],c[110];
char str[110];
int main()
{
	int i,j,k;
	int n;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%s",str);
		for(j = 0;j < n;j++)
		{
			if(str[j] == '.')
			  map[i][j] = 1;
		}
	}
	int flag1 = 0;
	for(i = 0;i < n;i++)
	{
		int flag = 0;
		for(j = 0;j < n;j++)
		{
			if(map[i][j] == 1)
			{
				flag = 1;
				r[i] = j;
			}
		}
		if(flag == 0)
		{
			flag1 = 1;
			break;
		}
	}
	if(flag1 == 0)
	{
		for(i = 0;i < n;i++)
		{
			printf("%d %d\n",i+1,r[i]+1);
		}
	}
	else
	{
		flag1 = 0;
		for(i = 0;i < n;i++)
		{
			int flag = 0;
			for(j = 0;j < n;j++)
			{
				if(map[j][i] == 1)
				{
					flag = 1;
					r[i] = j;
				}
			}
			if(flag == 0)
			{
				flag1 = 1;
				break;
			}
		}
		if(flag1==0)
		{
			for(i = 0;i < n;i++)
			{
				printf("%d %d\n",r[i]+1,i+1);
			}
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
