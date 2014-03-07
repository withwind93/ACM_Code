#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
using namespace std;
#define LL long long
int a[55][55],vis[55][55];
int black[2510][2];
int f[9][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int check1(int x1,int y1,int x2,int y2)
{
	int firstx,endx;
	int firsty,endy;
	if(x1<x2)	{firstx=x1;endx=x2;}
	else		{firstx=x2;endx=x1;}
	if(y1<y2)	{firsty=y1;endy=y2;}
	else		{firsty=y2;endy=y1;}
	int flag=0;
	for(int i=firstx;i<=endx;i++)
	  if(!a[i][y2])	return 0;
	for(int i=firsty;i<=endy;i++)
	  if(!a[x1][i])	return 0;
	return 1;
}
int check2(int x1,int y1,int x2,int y2)
{
	int firstx,endx;
	int firsty,endy;
	if(x1<x2)	{firstx=x1;endx=x2;}
	else		{firstx=x2;endx=x1;}
	if(y1<y2)	{firsty=y1;endy=y2;}
	else		{firsty=y2;endy=y1;}
	int flag=0;
	for(int i=firstx;i<=endx;i++)
	  if(!a[i][y1])	return 0;
	for(int i=firsty;i<=endy;i++)
	  if(!a[x2][i])	return 0;
	return 1;
}
int main()
{
	int i,j,k;
	int t,tmp;
	int n,m;
	scanf("%d%d",&n,&m);
	char s[10];
while(1)
{
	memset(a,0,sizeof(a));
	
	tmp=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		t=0;
		for(j=0;j<m;j++)
		{
			if(s[j]=='B')	
			{
				a[i][j+1]=1;
				black[++tmp][0]=i;
				black[tmp][1]=j+1;
			}
			else			a[i][j+1]=0;
		}
	}
	int flag=1;
	for(i=1;i<=tmp;i++)
	{
		for(j=i+1;j<=tmp;j++)
		{
			if(check1(black[i][0],black[i][1],black[j][0],black[j][1]))	continue;
			if(check2(black[i][0],black[i][1],black[j][0],black[j][1]))	continue;
			//printf("i=%d  j=%d \n",i,j);
			printf("%d %d %d %d\n",black[i][0],black[i][1],black[j][0],black[j][1]);
			flag=0;
			break;
		}
		if(flag==0)	break;
	}
	if(flag)	printf("YES\n");
	else		printf("NO\n");
}
	return 0;
}




