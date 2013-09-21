#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n,k;
int ans,mins,t,sum;
int a[10010];
int b[10010][10010];
int dfs(int now,int va,int kk)
{
	if(now == n+1 && kk==k)
	{
		ans=min(va,ans);
	}
	if(va>ans || kk>k)	return 0;/*”≈ªØ*/
	int tmin=INT_MAX,tmp;
	for(int i=now;i<=n;i++)
	{
		tmp=b[now][i];
		if(tmp>va)	dfs(i+1,tmp,kk+1);
		else		dfs(i+1,va,kk+1);
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==0 && k==0)	break;
		sum=0;
		ans=INT_MAX;mins=INT_MIN;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(k==1)	{printf("%d\n",sum);continue;}

		int tmp;
		t = sum/k;
		memset(b,0,sizeof(b));

		for(i=1;i<=n;i++)
		{
			tmp = 0;
			for(j=i;j<=n;j++)
			{
				tmp+=a[j];
				b[i][j]=tmp;
			}
		}
		dfs(1,0,0);	
		printf("%d\n",ans);
	}
	return 0;
}

