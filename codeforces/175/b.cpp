/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/21 23:40:52
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[100010];
int vis[100010];
int main()
{
	int i,j,k;
	int n,s,t;
	scanf("%d %d%d",&n,&s,&t);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	if(s==t)	{printf("0\n");return 0;}

	memset(vis,0,sizeof(vis));
				int next = a[s];
				int tmp = 1;
				while(next != t)
				{
					if(vis[next])	{printf("-1");return 0;}
					vis[next]=1;
					next = a[next];
					tmp++;
				}
		printf("%d\n",tmp);

	return 0;
}
