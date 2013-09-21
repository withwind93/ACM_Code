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
const int maxn = 10000000;
bool a[maxn];
int p[maxn],num;
void init(){
	num=1;/*start from 1*/
	for(int i=2;i<=maxn;i++){
		if(!a[i])	{p[num++]=i;}
		for (int j = 1; j < num; j++){
			if(p[j]*i>maxn) break;
			a[p[j] * i] = true;
			if (i%p[j] == 0) break;
		}
	}
}
int main()
{
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x;
		scanf("%d",&x);
		if(x == 0)	{printf("2 2\n");continue;}
		int flag = false;
		if(x < 0)	flag = true,x = -x;
		int flag2 = false;
		for(int i = 1;i < num;i++)
		{
			if(a[x + p[i]] == false)
			{
				flag2 = true;
				if(flag)
					printf("%d %d\n",p[i],p[i]+x);
				else
					printf("%d %d\n",p[i]+x,p[i]);
				break;
			}
		}
		if(flag2 == false)	printf("FALL\n");
	}
	return 0;
}
