#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
/*
 *map ”≥…‰∑Ω∑®
 * */
#define LL long long
#define %lld %I64d
map<LL,bool>	m;
LL a[100010];
LL n,k;
int main()
{
	int i,j,k;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	  scanf("%lld",&a[i]);
	if(n==1)	{printf("%lld\n");return 0;}
	sort(a,a+n);
//	printf("%lld %lld\n",a[0],a[1]);
	for(i=0;i<n;i++)
	  if(m[a[i]]==false)	m[a[i]]=m[a[i]*k]=true;
	printf("%d\n",(k==0)?m.size():(m.size()/2));
	return 0;
}




