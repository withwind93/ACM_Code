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
llg a[10000000];
char str[1000000];
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	  scanf("%I64d",&a[i]);
	scanf("%s",str);
	llg ans = 0;
	int end = 0;
	for(int i = 0;i < strlen(str);i++)
	{
		if(str[i] == '1')
		{
			ans+=a[i];
		}
	}
//	printf("end = %d\n",end);
	llg tmp = 0,tmp1 = 0;
	llg res = ans;
	for(int i = 0;i < strlen(str);i++)
	{
		if(str[i] == '1')
		{
			tmp1 += a[i];
			llg t = ans - tmp1 + tmp;
			//printf("i = %d %I64d = %I64d %I64d %I64d\n",i,t,ans,tmp1,tmp);
			res = Max(res,t);
		}
		tmp+=a[i];
	}
//	printf("%I64d %I64d\n",ans,tmp);
	printf("%I64d\n",res);
	return 0;
}

