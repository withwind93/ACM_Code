/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/3 23:46:55
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,x[25],y[25];
int day[60],ch[60],s[60]={1};
const int mod = 55566677;

int dfs(int i,int t)
{
	if(i==m)
	{
		if(t%2)	return (mod-s[n-t])%mod;
		else	return s[n-t];
	}
	int next = dfs(i+1,t);
	if(!day[x[i]] && !ch[y[i]])
	{
		day[x[i]] = ch[y[i]] = 1;
		next = (next+dfs(i+1,t+1))%mod;
		day[x[i]] = ch[y[i]] = 0;
	}
	return next;
}
int main()
{
	int i,j,k;
	int tmp;
	for(int i=1;i<60;i++)
	  s[i]=(s[i-1]*1ll*i)%mod;/*·ÀÖ¹Òç³ö£¡£¡*/
	while(~scanf("%d %d",&n,&m))
	{
		for(int i=0;i<m;i++)
		  scanf("%d %d",&x[i],&y[i]);
		for(int i=0;i<m;i++)
		{
			if(x[i]==x[j] && y[i]==y[j])
			{
				tmp = x[j];x[j]=x[m-1];x[m-1]=tmp;
				tmp = y[j];y[j]=y[m-1];y[m-1]=tmp;
				m--;
			}
		}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}
