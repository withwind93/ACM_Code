#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
	int vis[100000],a[100000];
	int n,ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int b,flag;
		for(b=n;b>=1;b--)
		{
			flag=0;
			for(int j=b+1;j<=n;j++)
			{
				if(a[b]>a[j])
				{
					flag=1;
					break;
				}
				else break;
			}
			if(flag)	break;
		}
		printf("%d\n",b);
	}
	return 0;
}



