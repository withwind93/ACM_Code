/*************************************************************************
  > File Name: g.cpp
  > Author: withwind
  > Mail: withwind93@gmail.com 
  > Created Time: 2013/3/17 12:59:06
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[10],n,ans;

void dfs(int star,int bef)
{
	int ii,i,j,k;
	int tmp[10];

	for(i=star;i<n;i++)
	{
		int tmp1=a[i],tmp2=a[i+1];
		if(a[i] && a[i+1])
		{
			dfs(i+1,0);
		if(bef!=2)
		{
			a[i+1]=a[i]*10+a[i+1];
			a[i]=0;
			dfs(i+1,1);
			a[i]=tmp1,a[i+1]=tmp2;
		}
		if(bef!=1)
		{
			a[i+1]=a[i+1]+a[i];
			a[i]=0;
			dfs(i+1,2);
			a[i]=tmp1,a[i+1]=tmp2;
		}
		}
	}
	
	if(star == n)//所有位置都有符号
	{
		for(i=1;i<=n;i++)
		  printf("%d  ",a[i]);
		printf("\n");
		k=0;
		j=a[n];
		for(i=1;i<n;i++)
		{
			if(a[i]==0)	continue;
			k=1;
			if(j!=a[i])	
			{
				k=0;
				break;
			}
		}
		if(k)
		{
			printf("star = %d \n",star);
			ans++;
		}
		return ;
	}
}



int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i =1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans=0;
		dfs(1,0);//第一个位置开始，进行0操作
		printf("%d\n",ans);
	}
	return 0;
}
