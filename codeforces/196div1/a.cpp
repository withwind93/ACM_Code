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
llg mod = 1000000009;
llg n,m,k;
llg ans;
llg quickpow(llg a,llg b)
{
	llg ans = 1;
	while(b)
	{
		if(b&1)	ans = (ans * a)%mod;
		a = (a * a)%mod;
		b = b>>1;
	}
	return ans;
}
int main()
{
	cin>>n>>m>>k;
	ans = 0;
	llg wa = n - m;
	llg r = (n - m) * k;
	if(r >= n)
	  ans = m;
	else
	{
		llg nn = n - r;
		llg a = nn / k;
		llg b = nn % k;
		ans = ((quickpow(2,a + 1) - 2 + mod)%mod)*k%mod;
		ans += b + wa*(k - 1)%mod;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
