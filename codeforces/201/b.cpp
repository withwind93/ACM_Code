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
int a[1000000];
int hash[1000000];
int main()
{
	scanf("%d",&n);
	int flag = -1;
	for(int i = 0;i < n;i++)
	  hash[i] = -1;
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		if(hash[a[i]] != -1 && hash[a[i]] == i)
		  flag = 2;
		if(a[i] == i)		ans++;
		if(flag == -1 && a[i] != i)	flag = 1;
		hash[i] = a[i];
	}
	if(flag == -1)		printf("%d\n",ans);
	else if(flag == 2)	printf("%d\n",ans + 2);
	else				printf("%d\n",ans + 1);

	return 0;
}

