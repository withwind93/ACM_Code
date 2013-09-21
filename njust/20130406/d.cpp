/*************************************************************************
    > File Name: hdu4532.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/6 15:50:20
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
const llg mod = 1000000007;
const int INF = 1000000000;
const int N = 501;

llg c[N][N],f[2][N],a[N];
int n;
int t,num = 0;
int pre,cur,sum;
void init()
{
	int i,j;
	c[0][0] = 1;
	for(i=1;i<N;i++)
	{
		c[i][0] = c[i][i] = 1;	
		for(j=1;j<i;j++)
		{
			c[i][j] = c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
	a[0] = 1;
	for(i=1;i<N;i++)
	{
		a[i] = a[i-1]*i%mod;
	}
}
void cal(int x)
{
	int i,j,k;
	for(i=0;i<N;i++)
	  f[cur][i] = 0;
	for(i=0;i<sum;i++)
	{
		if(f[pre][i])
		  for(j=0;j<=x;j++)
		  {
			for(k=0;k<=i && k<=j;k++)
			{
				f[cur][x+i-j-k]+=f[pre][i]*c[i][k]%mod*c[sum-i][j-k]%mod*c[x-1][j-1]%mod;
				f[cur][x+i-j-k]%=mod;
			}
		  }
	}
	int tmp = pre;
	pre = cur;
	cur = tmp;
}


int main()
{
	int i,j,k;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		pre = 0;cur = 1;sum = 1;
		llg i,x,p=1;
		for(i=0;i<N;i++)
		  f[pre][i] = 0;
		f[pre][0] = 1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			cal(x);
	//		p = p*a[x]%mod;
			sum +=x;
		}
		printf("Case %d: ",++num);
//		printf("%d\n",f[pre][0]*p%mod);
		printf("%lld\n",(f[pre][0]-1)%mod);
	}
	return 0;
}

