/*************************************************************************
    > File Name: d.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/21 19:27:19
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int ww[110],vv[110];
int a[100010];
int main()
{
	int i,j,k;
	int n,m;
	int w,v;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&vv[i],&ww[i]);
		}
		memset(a,0,sizeof(a));
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			w=ww[i];v=vv[i];
			for(j=w;j<=m;j++)
			{
				if(w<=j)
				{
					a[j]=a[j]>(a[j-w]+v)?a[j]:(a[j-w]+v);
				}
			}
		}
		printf("%d\n",a[m]);
	}
	return 0;
}
