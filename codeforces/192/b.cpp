#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int map[1010][1010];
int t[1010];
int main()
{
	int i,j,k;
	int n,m;
	scanf("%d %d",&n,&m);
	for(i = 0;i < m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		map[y][x] = map[x][y] = 1;
	}
	int ans = 0;
	for(i = 1;i <= n;i++)
	{
		int flag = 0;
		for(j = 1;j <= n;j++)
		{
			if(map[i][j] == 1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			ans = i;
			break;
		}
	}
	printf("%d\n",n-1);
	for(i = 1;i <= n;i++)
	{
		if(i == ans)	continue;
		printf("%d %d\n",ans,i);
	}
	return 0;
}
