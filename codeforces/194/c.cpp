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
char str[1000];
int main()
{
	llg n,tmp;
	tmp  = 3;
	cin >> n;
	while(n%tmp == 0)
	{
		tmp *= 3;
	}
	llg ans = (n/tmp + (n%tmp>0));
	cout<<ans<<endl;
	return 0;
}

