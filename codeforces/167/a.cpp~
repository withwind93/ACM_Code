#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	int m,n,k,ans;
	while(scanf("%d",&n)!=EOF)
	{
		m=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			m+=k;
		}
		n++;
		for(int i=1;i<=5;i++)
		{
			k=(m+i)/n;
			k=(m+i)-k*n;
			if(k!=1)	ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

