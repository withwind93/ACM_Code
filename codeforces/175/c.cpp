/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/22 0:01:05
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
llg a[300010];
llg b[300010];
llg n;
int main()
{
	llg i,j,k;
	llg ans,tmp;
	cin>>n;
	tmp=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=i;
	}
	sort(a+1,a+n+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
//		cout<<b[i]-a[i]<<endl;
		ans+=abs(b[i]-a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
