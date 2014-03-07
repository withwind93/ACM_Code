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
int cnt[110],a[110][110];
int flag[110];
int n,ans;
void check(int x,int y)
{
	//i == j
	int all = true;
	if(cnt[x] == cnt[y])
	{
		for(int i = 1;i <= cnt[x];i++)
		{
			if(a[x][i] != a[y][i])	all = false;
		}
		if(all)		{flag[x] = flag[y] = false;}
		return ;
	}
	if(cnt[x] < cnt[y])
	{//x wei y ziji
		int xx = 1;
		for(int i = 1;i <= cnt[y];i++)
		{
			if(a[x][xx] == a[y][i]) xx++;
		}
		if(xx == cnt[x] + 1)	{flag[y] = false;}
	}
	if(cnt[x] > cnt[y])
	{//x wei y ziji
		int yy = 1;
		for(int i = 1;i <= cnt[x];i++)
		{
			if(a[y][yy] == a[x][i]) yy++;
		}
		if(yy == cnt[y] + 1)	{flag[x] = false;}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		flag[i] = true;
		scanf("%d",&cnt[i]);
		for(int j = 1;j <= cnt[i];j++)
		  scanf("%d",&a[i][j]);
		sort(a[i] + 1, a[i] + 1 + cnt[i]);

//		for(int j = 1;j <= cnt[i];j++)
//		 printf("%d",a[i][j]);
		

		for(int j = 1;j < i;j++)
		{
			check(i,j);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(flag[i])	printf("YES\n");
		else		printf("NO\n");
	}
//	printf("%d\n",ans);
	return 0;
}

