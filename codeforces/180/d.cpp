/*************************************************************************
    > File Name: d.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/20 1:23:19
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<int,int> mmap;
int main()
{
	int i,j,k;
	int n,m;
	scanf("%d %d %d",&n,&m,&k);
	int a[100010];
	for(i = 1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(i = 1;i<=m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(mmap[tmp])	mmap[tmp]+=1;
		else			mmap[tmp]=1;
	}
	int flag = 0;
	for(i = 1;i<=n;i++)
	{
		if(mmap[a[i]])	
		{
			mmap[a[i]]-=1;
			if(mmap[a[i]]<0)	
			{
				printf("YES\n");
			}
		}
	}
	printf("NO\n");
	return 0;
}
