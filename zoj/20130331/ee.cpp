#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m,k;
int count=0;
int count1=0;
int a[10000000];
int dfs(int now)
{
	if(now == n+1)
	{
		count++;
		if(a[1]==1)	count1++;
//		for(int i=1;i<=n;i++)
//			printf("%d  ",a[i]);
//		printf("\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
	if(a[now-1] ==i && i<=k)
		{
			continue;
		}
		a[now] = i;
		dfs(now+1);
		a[now] = 0;
	}
	return 0;
}
int main()
{
//	while(~scanf("%d %d %d",&n,&m,&k))
	for(n=2;n<=5;n++)
		for(m=2;m<=5;m++)
			for(k=0;k<=m;k++)
	{
		printf("n= %d m= %d k= %d ",n,m,k);
		memset(a,0,sizeof(a));
		count=0;
		count1=0;
		dfs(1);
		printf("%d\n",count);
//		printf("cou1 = %d\n",count1);
	}
	return 0;
}

