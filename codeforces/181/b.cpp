/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/26 0:00:02
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int i,j,k;
	int n,m;
	scanf("%d %d",&n,&m);
	int a[50][3];
	memset(a,0,sizeof(a));
	for(i = 1;i<=50;i++)
	  a[i][0]=i;
	if(n == 3 && m==0){printf("1 2 3\n");return 0;}
	
	int flag = 0;
	for(i = 1;i<=m;i++)
	{
		int x,y;
		flag=0;
		scanf("%d %d",&x,&y);
		for(j = 0;j<3;j++)
		{
			if(a[x][j] == 0)	{a[x][j] = y;flag++;break;}
			if(a[x][j] == y)	{flag++;break;}
		}
		for(j = 0;j<3;j++)
		{
			if(a[y][j] == 0)	{a[y][j] = x;flag++;break;}
			if(a[y][j] == x)	{flag++;break;}
		}
		if(flag != 2)	{flag=-1;break;}
	}
	if(flag == -1)	printf("-1\n");
	else
	{
		int vis[50];
		memset(vis,0,sizeof(vis));
		for(i = 1;i<=n;i++)
		{
			if(a[i][1] == 0 || a[i][2] == 0)	{flag=-1;break;}
		}
		
		if(flag == -1)	printf("-1\n");
		else
			for(i = 1;i<=n;i++)
			{
				if(vis[i] == 1)	continue;
				printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
				vis[a[i][0]] = vis[a[i][1]] = vis[a[i][2]]=1;
			}
	}
	return 0;
}
