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
llg n;
llg a[10000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	llg maxn = -1;  
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		maxn = maxn > a[i] ? maxn : a[i];
	}
	llg ans = maxn;
	llg sum = 0;
	for(int i = 0;i < n;i++)
	{
		a[i] -= maxn;
		sum += a[i];
	}
	sum = sum + maxn;
	if(sum <= 0)	
	{
		cout << ans << endl;
		return  0;
	}
	if(sum % (n-1))
		ans += (sum / (n-1) +1);
	else
		ans += (sum / (n-1));
	cout << ans << endl;
	return 0;
}

