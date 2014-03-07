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
const int N = 100000 + 10;
int n,m,a;
int p[N],b[N];
int main()
{
	scanf("%d %d %d",&n,&m,&a);
	for(int i = 1;i <= n;i++)
	  scanf("%d",&b[i]);
	for(int i = 1;i <= m;i++)
	  scanf("%d",&p[i]);
	sort(b+1,b+1+n);
//	printf("b = %d  ",b[1]);
	sort(p+1,p+1+m);
//	printf("p = %d ",p[1]);
	int l = 0,r = m;
	int ans = l;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int flag = 1;//ÂòµÃÆð
		
		int ta = a;
		int ren = n;
		if(ren < mid)	{r = mid-1;continue;}
		for(int i = mid;i >= 1;i--)
		{
			if(b[ren] < p[i])
			  ta = ta - (p[i] - b[ren]);
			ren--;
	//	if(ren < 0)	printf("error");
			if(ta < 0)	{flag = 0;break;}
		}
		if(flag)	{l = mid + 1;ans = mid;}
		else		r = mid - 1;
	}	
	int sum = 0;
	for(int i = ans;i >= 1;i--)
	{
		sum += p[i];
	}
	sum -= a;
	if(ans == 0)
		printf("0 0\n");
	else
		printf("%d %d\n",ans,Max(sum,0));
	return 0;
}

