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
int a[100000];
int num[8][5];
int flag[10];
int main()
{
	scanf("%d",&n);
	int t;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&t);
		flag[t]++;
	}
	int num1 = 0,num2 = 0,num3 = 0;
	int cnt = 0;
	while(flag[1] >= 1 && flag[2] >= 1 && flag[4] >= 1)
	{
		flag[1]--;flag[2]--;flag[4]--;
		cnt = cnt + 3;
		num1++;
	}
	while(flag[1] >= 1 && flag[2] >= 1 && flag[6] >= 1)
	{
		flag[1]--;flag[2]--;flag[6]--;
		cnt = cnt + 3;
		num2++;
	}
	while(flag[1] >= 1 && flag[3] >= 1 && flag[6] >= 1)
	{
		flag[1]--;flag[3]--;flag[6]--;
		cnt = cnt + 3;
		num3++;
	}
	if(cnt != n)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		for(int i = 1;i <= num1;i++)
		  printf("1 2 4\n");
		for(int i = 1;i <= num2;i++)
		  printf("1 2 6\n");
		for(int i = 1;i <= num3;i++)
		  printf("1 3 6\n");
	}
	return 0;
}
