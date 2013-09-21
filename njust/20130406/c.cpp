/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/6 21:22:44
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int day[60],ch[60];
int x[60],y[60];
int s[60];
int n,m;
const int mod = 55566677;
int dfs(int now,int t)
{
	if(now == m)
	{
		if(t%2)	return (mod-s[n-t])%mod;
		else	return s[n-t];
	}
	int ans = dfs(now+1,t);
//	printf("now = %d day = %d ch = %d\n",now,day[x[now]],ch[y[now]]);
	if(!day[x[now]] && !ch[y[now]])
	{
		day[x[now]] = 1;
		ch[y[now]] = 1;
		ans=(ans+dfs(now+1,t+1))%mod;
		day[x[now]] = 0;
		ch[y[now]] = 0;
	}
	return ans;
}

int main()
{
	int i,j,k;
	s[0]=s[1]=1;
	for(i=1;i<60;i++)
	{
		s[i] = (int)((s[i-1]*1ll*i)%mod);
//		printf("%d\n",s[i]);
	}
	while(scanf("%d %d %d",&n,&m,&k)==3)
	{
		memset(day,0,sizeof(day));
		memset(ch,0,sizeof(ch));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
		}
		for(i=0;i<m;i++)
		  for(j=i+1;j<m;j++)
			{
				if(x[j]==x[i] && y[j]==y[i])
				{
					int tmp = x[j];
					x[j] = x[m-1];
					x[m-1] = tmp;
					
					tmp = y[j];
					y[j] = y[m-1];
					y[m-1] = tmp;
					m--;
				}
			}
	//	printf("m = %d\n",m);
		int a,b;
		int flag = 0;
		for(i=1;i<=k;i++)
		{
			scanf("%d %d",&a,&b);
			if(flag)	continue;
			if(day[a] != 0)
			{
				flag=1;
			}
			day[a] = 1;
			ch[b] = 1;
			n--;
			
		/*	}
			else
			{
				flag = 1;
			}*/
		}
		if(flag)	printf("0\n");
		else		printf("%d\n",dfs(0,0));
	}
	return 0;
}
