#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
	int t;
	int m,n,k;
	long long vis[50];
	long long ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<=40;i++)
		{
			vis[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			m=0;
			if(k%2==1)	m++;
			while(k)
			{
				if((k>>1)%2==1) m++;
				k=k>>1;
			}
			vis[m]++;
		}
		ans=0;
		long long tmp;
		for(int i=1;i<=33;i++)
		{
			if(vis[i]==1 || vis[i]==0)	continue;
			if(vis[i]%2==0)
			{
				tmp=vis[i]/2;
				ans+=((tmp*(vis[i]-1)));
			}
			else
			{
				tmp=(vis[i]-1)/2;
				ans+=((tmp*(vis[i])));		
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


