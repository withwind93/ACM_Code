/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/19 23:28:03
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int i,j,k;
	int n;
	int flag;
	scanf("%d",&n);
	char s[1100];
	scanf("%s",s);
	int first = 0,end = n-1;
	while(s[first] == '.')	first++;
	while(s[end] == '.')	end--;
	
	flag = 0;
	if(first == end)	
	{
		if(s[first] == 'R')	printf("%d %d\n",first+1,first+2);
		else				printf("%d %d\n",first+1,first);
		return 0;
	}
	
	for(i=first;i<=end;i++)
	{
		if(s[i] != 'L')	break;
	}
	if(i == end+1)	{printf("%d %d\n",end+1,first);return 0;}
	for(i=first;i<=end;i++)
	{
		if(s[i] != 'R')	break;
	}
	if(i == end+1)	{printf("%d %d\n",first+1,end+2);return 0;}
	
	int k1,k2;
	for(i=first;i<=end;i++)
	{
		if(s[i] == 'R' && flag ==0){
			k1=i;
			flag = 1;
		}
		if(s[i]== 'R')	k2=i;
	}
	printf("%d %d\n",k1+1,k2+1);
	/*
	for(i=first;i<end-1;i++)
	{
		if(s[i] == 'R' && s[i+1] == 'L')
		{
			k = i;
			flag = 1;
			break;
		}
		if(s[i] == 'L' && s[i+1] == 'R')
		{
			k = i;
			flag = 2;
			break;
		}
	}
	if(flag == 1)	printf("%d %d\n",first+1,k+1);
	else			printf("%d %d\n",end+1,k+1);
*/	return 0;
}
