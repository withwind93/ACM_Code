/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/30 21:27:55
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
#define llg long long
int main()
{
	llg i,j,k;
	llg c,q,n,x;
	while(scanf("%lld %lld %lld %lld",&c,&q,&n,&x)!=EOF)
	{
		llg tmp = 1;
		llg mod = 1<<n;
		//printf("%lld\n",mod);
		map<llg,bool> m;
		int flag = 1;
		x = x%mod;
		for(i=1;;i++)
		{
			tmp = q;
//			printf("tmp = %lld\n",tmp);
			llg sum = tmp*(tmp+1)%mod;
			sum = sum*(2*q+1)%mod;
			printf("sum = %lld\n",sum);
			sum = (sum*mod/6)%mod;
			sum = (((sum*q)%mod)*q%mod)*(c-1)%mod;
			//printf(" i = %lld  sum = %lld",i,sum);
			if(m[sum] == true)
			{
				flag = 0;
				break;
			}
			m[sum] = true;
			if(sum == x)
			  break;	
			q = ((q%mod)*q);	
		}
		printf("i = %d\n",i);
		if(flag)	printf("%lld\n",i);
		else		printf("-1\n");
	}
	return 0;
}
