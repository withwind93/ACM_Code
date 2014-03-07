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
int hash[110][110];
struct po
{
	int x,id;
}p[110];
int cmp(po a,po b)
{
	return a.x > b.x;
}
int ans[110];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= 2*n;i++)
	{
		scanf("%d",&p[i].x);
		p[i].id = i;
	}
	sort(p+1,p+1+2*n,cmp);
//	for(int i = 1;i <= 2*n;i++)
//	  printf("%d\n",p[i].x);
	int res = 0;
	memset(hash,0,sizeof(hash));
	for(int i = 1;i <= 2*n;i+=2)
	  for(int j = 2;j <= 2*n;j+=2)
	  {
		if(hash[p[i].x][p[j].x]==0)
		{
			res++;
			hash[p[i].x][p[j].x] = 1;
		}
	  }
	for(int i = 1;i <= 2*n;i++)
	{
		if(i%2)
			ans[p[i].id] = 1;
		else 
		  ans[p[i].id] = 2;
	}
	printf("%d\n",res);
	printf("%d",ans[1]);
	for(int i = 2;i <= 2*n;i++)
	  printf(" %d",ans[i]);
	printf("\n");
	return 0;
}

