/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/21 19:50:07
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int mod = 1000000007;
#define llg long long
llg a[10010];
llg ans[10010];
llg quickpower(llg m,llg n)
{
    llg temp,ans=1;
	if(n==0)	return 1;
	if(m==1)	return m;
    temp=m%mod;
    while(n)
    {
        if(n&1)     ans=(ans*temp)%mod;
        temp=(temp*temp)%mod;
        n=n>>1;
    }
    return ans;
}
int main()
{
	int i,j;
	int T;
	int n,t,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&t,&k);
		llg tmp = quickpower(k,t)%mod;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			llg num = (i+t)%n;
			if(num == 0)	num=n;
			ans[num]=(a[i]%mod)*tmp%mod;			
		}
/*		t=t%n;
		int s=t+1;
		printf("%lld",a[s]);
		for(i=s+1;i<=n;i++)
		  printf(" %lld",a[i]);
		for(i=1;i<s;i++)
		  printf(" %lld",a[i]);*/
		for(i=1;i<=n-1;i++)
		  printf("%lld ",ans[i]);
		printf("%lld\n",ans[n]);
	}
	return 0;
}
