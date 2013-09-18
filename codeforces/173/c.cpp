/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/13 23:46:12
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
char a[1000010],b[1000010],c[1000010],d[1000010];
char ta[1000010],tb[1000010];
char xo(char x,char y)
{
	if(x == '1' && y == '1')	return '0';
	if(x == '1' && y == '0')	return '1';
	if(x == '0' && y == '1')	return '1';
	if(x == '0' && y == '0')	return '0';	
}
char ro(char x,char y)
{
	if(x == '1' && y == '1')	return '1';
	if(x == '1' && y == '0')	return '1';
	if(x == '0' && y == '1')	return '1';
	if(x == '0' && y == '0')	return '0';	
}
int main()
{
	int i,j,k;
	scanf("%s %s",a,b);
	int l1=strlen(a),l2=strlen(b);
	int star1=0;
	while(a[star1]=='0' && star1<l1)
	{
		star1++;
	}
	int star2=0;
	while(b[star2]=='0' && star2<l2)
	{
		star2++;
	}
	if((l1-star1)!=(l2-star2))	{printf("NO\n");return 0;}
	if(l1-star1==1 && l2-star2==1)
	{
		printf("NO\n");
		return 0;
	}
	for(i=star1;i<=l1;i++)
	  ta[i-star1]=a[i];
	for(i=star2;i<=l2;i++)
	  tb[i-star2]=b[i];
	int len = l1-star1;
//printf("ta %s  %s\n",ta,tb);
		c[len]='\0';
		d[len]='\0';
		for(i = 0;i<len;i++)
		{
			c[i]=xo(ta[i],tb[i]);
			d[i]=ro(ta[i],tb[i]);
		}
//		printf("%s\n%s\n",c,d);
		a[len]='\0';
		b[len]='\0';
		for(i = 0;i<len;i++)
		{
			a[i]=xo(c[i],d[i]);
			b[i]=ro(c[i],d[i]);
		}
//		printf("%s\n%s\n",a,b);
	if(strcmp(a,tb)==0)	
	{
		if(strcmp(b,ta)==0)	printf("YES\n");
		else				printf("NO\n");
		return 0;
	}
	if(strcmp(a,ta)==0)
	{
		if(strcmp(b,tb)==0)	printf("YES\n");
		else				printf("NO\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}
