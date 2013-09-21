/*************************************************************************
  > File Name: b.cpp
  > Author: withwind
  > Mail: withwind93@gmail.com 
  > Created Time: 2013/3/13 23:34:04
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct no
{
	int a,b;
	int num;
}node[1000010];
//int a[1000010],b[1000010];
int cmp(const void *aa,const void *bb)
{
	return (*(struct no*)bb).a-(*(struct no*)aa).a;
}
int main()
{
	int i,j,k;
	int n;
	int sum = 0;
	scanf("%d",&n);

	char s[1000010];
	s[n]='\0';
	for(i = 0;i<n;i++)
	{
		scanf("%d%d",&node[i].a,&node[i].b);
		sum +=node[i].b;
		node[i].num=i;
	}
	qsort(node,n,sizeof(node[1]),cmp);
	/*	for(i = 0;i<n;i++)
		{
		printf("a = %d b = %d\n",node[i].a,node[i].b);
		}	*/
	int flag=0;
	int ans1=0,ans2=sum;
	for(i=0;i<n;i++)
	{
		ans1+=node[i].a;
		ans2-=node[i].b;
		if(abs(ans1-ans2)<=500)	
		{
			flag=i+1;
			break;
		}
	}
	if(flag)
	{
		flag--;
		for(i=0;i<=flag;i++)
		{
			s[i]='A';
		}
		for(i=flag+1;i<n;i++)
		  s[i]='G';
		printf("%s\n",s);
		return 0;
	}
	else
	{
		ans1=0;ans2=sum;
		for(i=n-1;i>0;i++)
		{
			ans1+=node[i].a;
			ans2-=node[i].b;
			if(abs(ans1-ans2)<=500)	
			{
				flag=i+1;
				break;
			}
		}
		if(flag)
		{
			flag--;
			for(i=0;i<flag;i++)
			{
				s[i]='G';
			}
			for(i=flag;i<n;i++)
			  s[i]='A';
			printf("%s\n",s);
			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	return 0;
}
