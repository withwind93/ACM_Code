#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define llg long long
#define N 110
llg dp[N][N],maxlcm[N];
llg factor[N];
int fnum;
llg p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
llg gcd(llg x,llg y)
{
	return (y==0)?x:gcd(y,x%y);
}

void init(int n)
{
	int i,j,k,lcm;
	memset(dp,0,sizeof(dp));
	for(i = 1;i<=n;i++)
	  dp[i][1]=i;
	for(i = 2;i <= n;i++)
	  for(j = 2;j<=i;j++)
		for(k = 1;k < i && i-k >= j-1 ;k++)
		{
			lcm = dp[i-k][j-1]/gcd(dp[i-k][j-1],k)*k;
			if(lcm > dp[i][j]) dp[i][j] = lcm;
		}
	/*
	for(i = 1;i <= n;i++)
	{
	  for(j = 1;j<=i+2;j++)
	  {
		printf(" %d ",dp[i][j]);
	  }
		printf("\n");
	}*/
	for(i = 1;i<=n;i++)
	{
		maxlcm[i]=0;
		for(j = 1;j<=n; j++)
		  if(dp[i][j] >= maxlcm[i])	maxlcm[i] = dp[i][j];
	}
}

void split(llg n)
{
	int i,j,k,tmp;
	fnum = 0;//分解成质因数的数目
	for(i=0;i<25;i++)
	{
		if(n%p[i] == 0)
		{
			factor[fnum] = 1;
			while(n % p[i] ==0)
			{
				factor[fnum]*=p[i];
				n = n/p[i];
			}
			fnum++;
		}
	}
}

int main()
{
	int i,j,k;
	init(100);
	llg t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		split( maxlcm[n]);
		sort(factor,factor+fnum);
		llg sum = 0;
		for(i=0;i<fnum;i++)
		{
//			printf("factor[%d] = %lld\n",i,factor[i]);
			sum += factor[i];
//			printf("sum = %lld\n",sum);
		}
	//	printf("%lld",maxlcm[n]);
//		printf("fnum = %d  sum = %lld  factor[0] = %lld  \n",fnum,sum,factor[0]);
		/*先输出 一阶变化，按字典序来说，应该为前面几个数字*/
//		printf("n = %lld sum = %lld",n,sum);
		int ff = 1;
		for(i=1;i<=n-sum;i++)
			if(ff)	{printf("%d",i);ff = 0;}
			else		printf(" %d",i);

		int first = n-sum;
		for(i=0;i<fnum;i++)
		{
			for(j=2;j<=factor[i];j++)
			{
				if(ff)		{printf("%d",j+first);ff = 0;}
				else		printf(" %d",j+first);
			}
			printf(" %d",first+1);/*小循环中最小的那个数字*/
			first+=factor[i];
		}
		printf("\n");
	}
	return 0;
}

