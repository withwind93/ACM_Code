/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/20 0:20:42
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

void change(char c,int &x,int &y)
{
	if(c == 'E')	x++;
	if(c == 'S')	y--;
	if(c == 'W')	x--;
	if(c == 'N')	y++;
}
int t,s1,s2,e1,e2;
char s[101000];
void need1(int x,int x1,int &flag,int &n)
{
	if(x1 > x)
	{
		flag = 4;
		n = x1 - x;
	}
	else
	{
		flag = 3;
		n = x - x1;
	}
}
void need2(int y,int y1,int &flag,int &n)
{
	if(y1 > y)
	{
		flag = 1;
		n = y1 - y;
	}
	else
	{
		flag = 2;
		n = y - y1;
	}
}

int main()
{
	int i,j,k;
	scanf("%d %d %d %d %d",&t,&s1,&s2,&e1,&e2);
	scanf("%s",s+1);
	char ss[10]={'A','N','S','W','E'};
	int flagx,flagy,t1,t2;
	need1(s1,e1,flagx,t1);
	need2(s2,e2,flagy,t2);
//	cout<<flagx<<" t 1 = "<<t1<<endl;
//	cout<<flagy<<" t 2 = "<<t2<<endl;
//	cout<<(s[2]==ss[flagx])<<endl;
	for(i=1;i<=t;i++)
	{
		if(s[i] == ss[flagx] && t1>0)	t1--;
		if(s[i] == ss[flagy] && t2>0)	t2--;
	//	cout<<t1<<"  "<<t2<<endl;
		if(t1 == 0 && t2 == 0)
		{
//			cout<<i<<endl;
			printf("%d\n",i);
			return 0;
		}
	}
//	if(i == t+1)
	printf("-1\n");
//	else			printf("%d\n",i);
	return 0;
}
