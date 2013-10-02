#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
int n;
struct point
{
	int x,y;
}p[100010];
int cmp(point a,point b)
{
	if(a.x < 0)	a.x = -a.x;
	if(a.y < 0)	a.y = -a.y;
	if(b.x < 0)	b.x = -b.x;
	if(b.y < 0)	b.y = -b.y;
	if(a.y == b.y)	return a.x < b.x;
	return a.y < b.y;
}
void print(int a)
{
	if(a==1)	printf("U\n");
	if(a==2)	printf("D\n");
	if(a==3)	printf("L\n");
	if(a==4)	printf("R\n");
}
int main()
{
	scanf("%d",&n);
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		if(p[i].x && p[i].y)	ans+=2;
	}
	sort(p,p+n,cmp);
	ans += (n*4);
	printf("%d\n",ans);
	for(int i = 0;i < n;i++)
	{
		if(p[i].x)
		{
			if(p[i].x < 0)
			{
				printf("%d %d ",1,-p[i].x);
				print(3);
			}
			else
			{
				printf("%d %d ",1,p[i].x);
				print(4);
			}
		}
		
		if(p[i].y)
		{
			if(p[i].y < 0)
			{
				printf("%d %d ",1,-p[i].y);
				print(2);
			}
			else
			{
				printf("%d %d ",1,p[i].y);
				print(1);
			}
		}
		printf("2\n");
		
		if(p[i].x)
		{
			if(p[i].x < 0)
			{
				printf("%d %d ",1,-p[i].x);
				print(4);
			}
			else
			{
				printf("%d %d ",1,p[i].x);
				print(3);
			}
		}
		
		if(p[i].y)
		{
			if(p[i].y < 0)
			{
				printf("%d %d ",1,-p[i].y);
				print(1);
			}
			else
			{
				printf("%d %d ",1,p[i].y);
				print(2);
			}
		}

		printf("3\n");

	}
	return 0;
}


