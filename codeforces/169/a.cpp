#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;
int f[10010],t[10010];
int main()
{
    int i,j,k,n,m;
    int l,r;
    scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&f[i],&t[i]);
		if(t[i]-k<=0)	f[i]=f[i];
		else			f[i]=f[i]-t[i]+k;
	}
	int max=INT_MIN;
	for(i=1;i<=n;i++)
	  if(f[i]>max)	max=f[i];
	printf("%d\n",max);

	return 0;
}


