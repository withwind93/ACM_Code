/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/1 0:10:46
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[110][110];
int main()
{
	int i,j,k;
	int n,m;
	int t,tmp,f;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=100;j++)
		{
			a[i][j]=0;
		}
	}
	int ans=0;
	f=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t==0)	ans++;
		while(t--)
		{
			scanf("%d",&tmp);
			a[i][tmp]=1;
			f=0;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			int flag=0;
			for(k=1;k<=m;k++)
			  if(a[i][k] == 1 && a[j][k] == 1)
			  {
				flag=1;
				break;
			  }
			if(flag)
				for(k=1;k<=m;k++)
				{
					if(a[j][k]==1)	a[i][k]=1;	  
					a[j][k]=0;
				}
		}
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=m;j++)
	  {
//		printf("%d ",a[i][j]);
		if(a[i][j])	
		{
			ans++;
			break;
		}
	  }
//		printf("\n");
	}
	if(f)		printf("%d\n",n);
	else
	{	if(ans==0)	printf("0\n");
		else		printf("%d\n",ans-1);
	}
	return 0;
}
