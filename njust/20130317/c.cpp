/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/17 12:11:38
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 100000001
#define M 350000
int p[500],pn;
int hash[M];
//int ans[N];
int init()
{
	memset(p,0,sizeof(p));
	pn=0;
	int res = 1;
	for(int i=1;res<=N;i++)
	{
		res = i*i*i;
		p[pn++]=res;
	}
	int count=1;
	int c=1;
	hash[0]=0;
	for(int i=1;i<=N;i++)
	{
		hash[i]=c+hash[i-1];
		if(hash[i-1]+1 == p[count])
		{
			hash[i]=hash[i-1]+1;
			c++;
			count++;
		}
		if(hash[i]>N+100)	{break;}
		//		printf("i = %d %d\n",i,hash[i]);
	}
/*	ans[0]=1;
	count=2;
	for(int i=1;i<=N;i++)
	{
		ans[i]=ans[i-1];
	//	printf("%d\n",i);
		if(i==hash[count])
		{
			ans[i]++;
			count++;
		}
		
//		printf("%d %d\nhash = %d\n",i,ans[i],hash[count]);
	}*/
}

int get(int key,int size)
{
	int low = 0,high = size-1,mid=0;
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(key<=hash[mid])	high = mid-1;
		else				low = mid+1;
	}
	if(key != hash[low])	low--;
	return low;
}
int main()
{
	int i,j,k;
	int n;
	init();
	int count1,count2;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
/*		count1=0;count2=0;
		for(i = 1;i<=n;i++)
		{
			double a = pow(i,1.0/3.0);
			int b = (int)(a+0.00001);
			if(i%b==0)
			{
				count1++;
			}
			else
				count2++;
		}*/
		int size=n;
		if(324322<n)	size=324322;
		int count1 = get(n,size);
//		printf("count = %d\n",count1);
//		count1=ans[n];
		count2=n-count1;
		printf("%.2lf\n",((count1*5.0-count2*1.0)/(n*1.0))*100.0);
	}
	return 0;
}
