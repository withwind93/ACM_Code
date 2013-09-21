/*************************************************************************
    > File Name: b2.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/26 0:32:48
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
	int n,m;
	scanf("%d %d",&n,&m);
	if(n == 3 && m==0){printf("1 2 3\n");return 0;}
	if(m == 0)
	{
		for(i = 1;i<=n;i+=3)
		  printf("%d %d %d\n",i,i+1,i+2);
		return 0;
	}
	int a[50];
	memset(a,0,sizeof(a));
	int count = 1;
	int flag = 0;
	for(i = 1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(flag == -1)	continue;
		if(a[x] == 0 && a[y] == 0)	a[x]=a[y]=count++;
		else if(a[x] == 0 && a[y] != 0)	a[x] = a[y];
		else if(a[x] != 0 && a[y] == 0)	a[y] = a[x];
		else if(a[x] == a[y])	continue;
		else	{flag=-1;}
	}
//cout<<"flag : "<<flag<<endl;
	int team[50][4];
	memset(team,0,sizeof(team));
	for(i = 1;i<=n;i++)
	{
//cout<<"i = "<<i<<"  a = "<<a[i]<<endl;				
		if(a[i] == 0)	continue;
		team[a[i]][0]++;
		if(team[a[i]][0] == 4)	
		{
			flag = -1;
			break;
		}
		team[a[i]][team[a[i]][0]] = i;
	}
//cout<<"flag : "<<flag<<endl;
//cout<<"count = "<<count<<endl;		
	if(flag == -1 || (count-1)*3>n)	{printf("-1\n");return 0;}
	for(i = 1;i<=n;i++)
	{
		if(a[i] == 0)
		{
			if((count-1)*3<n)
			{
				team[count][++team[count][0]] = i;
				a[i] = count++;
			}
			else
			for(j = 1;j<count;j++)
			{
				if(team[j][0] < 3) 
				{
					team[j][++team[j][0]] = i;
					a[i] = j;
					break;
				}
			}
		}
	}
//cout<<"22 flag :"<<flag<<endl;
	if(flag == -1 || (count-1)*3>n)	printf("-1\n");
	else
	{
		for(i = 1;i<=n;i++)
		{
			if(team[a[i]][0]!=3)	{flag=-1;break;}
		}
		if(flag == -1 && (count-1)*3!=n)	printf("-1\n");
		else
		{
			for(i=1;i<count;i++)
			  printf("%d %d %d\n",team[i][1],team[i][2],team[i][3]);
		}
	}
	return 0;
}
