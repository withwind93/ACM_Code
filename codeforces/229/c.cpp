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
int tree[11][100010];
int n;
int a[100010];
int t[11][100010];
int k,w,l,r;

int lowbit(int x)
{
    return x&(-x);
}

void add(int now,int i,int val)
{
    while(i<=n)
    {
        tree[now][i]+=val;
        i=i+lowbit(i);
		printf("i= %d\n",i);
    }
}

int sum(int now,int n)
{
    int sum=0;
    while(n>0)
    {
        sum=sum+tree[now][n];
        n=n-lowbit(n);
		printf("n=%d \n",n);
    }
    return sum;
}
/*
void initial()//¸öÊý
{
    int x;
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&x);
        add(i,x);
    }
}*/


char str[1000010];
int main()
{
	scanf("%d %d %d",&n,&k,&w);
	scanf("%s",str);
	//printf("%s\n",str);
	for(int i = 1;i <= n;i++)
	{
		a[i] = str[i-1] - '0';
//		printf("%d a = %d\n",i,a[i]);
	}
	for(int i = 0;i < k;i++)
	{
		for(int j = i;j <= n;j+=k)
		{
			if(a[j] == 1)	
			{
			//	printf("i = %d  j = %d\n",i,j);
				add(i,j,1);
			}
		}
	}
	for(int j = 1;j <= n;j++)
	  if(a[j])	add(k,j,1);
	
	for(int wt = 1;wt <= w;wt++)
	{
		int ans = 0;
		scanf("%d %d",&l,&r);
		int kk = (l+k-1) % k;
		ans = sum(k,r) - sum(k,l-1) - 2*(sum(kk,r) - sum(kk,l-1)) + (r-l+1)/k;
		printf("%d %d %d %d\n",sum(k,r),sum(k,l-1),sum(kk,r),sum(kk,l-1));
		printf("%d\n",ans);
	}
	//printf("%d\n",ans);
	return 0;
}

