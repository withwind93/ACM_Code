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
llg a[1000000];
llg b[1000000];
llg c[1000000];
int n;
llg ans;
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		cin >> a[i];//scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++)
	{
//		scanf("%d",&b[i]);
		cin >> b[i];
		if(b[i] == 1LL)	{ans--;continue;}
		c[i] = (b[i]+1LL)/(2LL);
	//	printf("c : %d\n",c[i]);
		if(b[i]%(2LL) == 1LL)
		{
			if(a[i] >= c[i])
			  ans += (b[i]-c[i])*c[i];
			else
			  ans--;
		}
		else
		{
			if(a[i] >= c[i])
			  ans+=c[i]*c[i];
			else
			  ans--;
		}
	//printf("%d\n",ans);
		
	}
	cout << ans << endl;
//	printf("%d\n",ans);
	return 0;
}

