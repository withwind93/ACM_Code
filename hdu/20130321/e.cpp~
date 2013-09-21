/*************************************************************************
    > File Name: e.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/21 20:38:07
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[1500];
int main()
{
	int i,j,k1,k2;
	int n;
	int h,m,h2,m2;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			scanf("%d:%d %d:%d",&h,&m,&h2,&m2);
			k1=h*60+m;
			k2=h2*60+m2;
			for(j=k1;j<k2;j++)
			  a[j]=1;
		}
		int ans=0;
	//	printf("%d\n",a[0]);
		for(i=0;i<=1439;i++)
		  if(a[i]==0)	ans++;
		printf("%d\n",ans);
	}
	return 0;
}
