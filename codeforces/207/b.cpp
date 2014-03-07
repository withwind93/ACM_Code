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
int n,m;
int a[100001],b[100001],c[100001];
int flag[1000010];

int flag1 = 0,flag2 = 0,flag3 = 0;
bool fun()
{
		if(flag1 == 1)
		{
			if(flag2 == 0 && flag3 == 0)
			{
				flag2 = 2;flag3=3;
			}else if(flag2 == 0)
			{
				if(flag3 == 2)	flag2 = 3;
				else if(flag3 == 3)	flag2 = 2;
			}else if(flag3 == 0)
			{
				if(flag2 == 2)	flag3 = 3;
				else if(flag2 == 3)	flag3 = 2;
			}
		} else if(flag1 == 2)
		{
			if(flag2 == 0 && flag3 == 0)
			{
				flag2 = 1;flag3=3;
			}else if(flag2 == 0)
			{
				if(flag3 == 1)	flag2 = 3;
				else if(flag3 == 3)	flag2 = 1;
			}else if(flag3 == 0)
			{
				if(flag2 == 1)	flag3 = 3;
				else if(flag2 == 3)	flag3 = 1;
			}
		} else if(flag1 == 3)
		{
			if(flag2 == 0 && flag3 == 0)
			{
				flag2 = 1;flag3=2;
			}else if(flag2 == 0)
			{
				if(flag3 == 1)	flag2 = 2;
				else if(flag3 == 2)	flag2 = 1;
			}else if(flag3 == 0)
			{
				if(flag2 == 1)	flag3 = 2;
				else if(flag2 == 2)	flag3 = 1;
			}
		}else if(flag1 == 0 && flag2 == 0 && flag3 == 0)
		{
			flag1 = 1;
			flag2 = 2;
			flag3 = 3;
		}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}
	for(int i = 1;i <= m;i++)
	{
		int x = a[i],y = b[i],z = c[i];
		if(flag[x])
		{
			flag1 = flag[x],flag2 = flag[y],flag3 = flag[z];
			fun();
			flag[x] = flag1;flag[y] = flag2;flag[z] = flag3;
		} else if(flag[y])
		{
			flag1 = flag[y],flag2 = flag[x],flag3 = flag[z];
			fun();
			flag[y] = flag1;flag[x] = flag2;flag[z] = flag3;
		}else
		{
			flag1 = flag[z],flag2 = flag[y],flag3 = flag[x];
			fun();
			flag[z] = flag1;flag[y] = flag2;flag[x] = flag3;
		}
	}
	int tmp = 1;
	for(int i = 1;i <= n;i++)
	{
		if(flag[i])	printf("%d ",flag[i]);
		else		printf("%d ",tmp++);
		if(tmp == 3)	tmp = 1;
	}
	return 0;
}

