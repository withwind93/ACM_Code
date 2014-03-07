/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/2 23:18:30
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int l[100010],r[100010];
int main()
{
//	freopen("in","r",stdin);
	int i,j,k;
	int n;
	scanf("%d %d",&n,&k);
	int ans = 0;
	l[0]=r[0]=0;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
//		if(r[i-1] != l[i])
			ans +=(r[i]-l[i]+1);
//		else
//		 ans +=(r[i]-l[i]);
	}
	for(i=0;i<=k;i++)
	{
		ans = ans+i;
		if(ans%k==0)	break;
		ans = ans-i;
	}
	printf("%d\n",i);
	return 0;
}
