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
llg a[100010];
int main()
{
	int T;
	scanf("%d",&T);
	int cas = 1;
	while(T--)
	{
		int flag = 0;
		int n;
		scanf("%d %I64d",&n,&a[1]);
		for(int i = 2;i <= n;i++)
		{
			//cin >> a[i];
			scanf("%I64d",&a[i]);
			if((a[i] - a[i-1]) != 1 && flag == 0)
			{
				flag = i;
			}
		}
		printf("Case #%d: ",cas);
		cas++;
		if(flag == 0)	printf("1\n");
		else			printf("%d\n",flag);
	}
	return 0;
}
