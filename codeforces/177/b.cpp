/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/2 23:51:06
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int t[100010],d;
bool f(int s,int mid,int &count)
{
	int i,k;
	for(i=1;i<=s;i++)
	{
		if(t[i] > mid)	k=t[i]-mid;
		else			k=mid-t[i];
		if(k%d)
		{
			return false;
		}
		count=count+k/d;
	}
	return true;
}
int main()
{
//	freopen("in","r",stdin);
	int i,j,k;
	int n,m,first;
	k=0;
	scanf("%d %d %d",&n,&m,&d);
	for(i=1;i<=n*m;i++)
	{
		scanf("%d",&t[i]);
	}
	sort(t+1,t+1+n*m);
	int flag = 0;
	for(i=2;i<=n*m;i++)
	{
		k = t[i]-t[i-1];
		if(k%d)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		printf("-1\n");
		return 0;
	}
	int mid = t[n*m/2+1];
	if(n*m == 1)	{printf("0\n");return 0;}

	int count1=0,count2=0;
	
	if(n*m%2 == 1)
	{
		if(f(n*m,t[n*m/2+1],count1))
			printf("%d\n",count1);
		else
			printf("-1\n");
		return 0;
	}
	else
	{
		if(n*m ==2 )
		{
			if((t[2]-t[1])%d==0)
			  printf("%d\n",(t[2]-t[1])/d);
			else
			  printf("-1\n");
			return 0;
		}
		f(n*m,t[n*m/2],count1);
		if(f(n*m,t[n*m/2+1],count2) == false)
		  printf("-1\n");
		else
		  printf("%d\n",count1>count2?count2:count1);
	}
	return 0;
}
