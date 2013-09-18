#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[1010];
int m=INT_MAX;
int BFS(int first,int end,int num)
{
	if(first==end)
	{
		if(num<m)	m=num;
//		printf("1  num=%d\n",num);
		return 0;
	}
	if(first==end-1)
	{
		if(s[first]==s[end])	
		{
			if(num<m)	m=num;
//			printf("2  num=%d\n",num);
			return 0;
		}
		else
		{
			num=num+1;
			if(num<m)	m=num;
//			printf("3  num=%d\n",num);
			return 0;
		}
	}
	if(s[first]==s[end])	BFS(first+1,end-1,num);
	else
	{
		BFS(first+1,end,num+1);
		BFS(first,end-1,num+1);
	}
	return 0;
}
int main()
{
    int i,j,k,n;
    int l,r;
    scanf("%s",s);
	l=strlen(s);
	k=BFS(0,l-1,0);
	if(m%2==0)		printf("First\n");
	else			printf("Second\n");
	
	return 0;
}



