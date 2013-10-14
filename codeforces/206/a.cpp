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

llg n,l,r,ql,qr;
llg w[1000010];
llg wl[1000010],wr[1000010];
int main()
{
	cin >> n >> l >> r >> ql >> qr;
	for(int i = 1;i <= n;i++)
	{
		cin >> w[i];
		wl[i] = w[i] + wl[i-1];
	}
	wr[n] = w[n];
	for(int i = n-1;i >= 1;i--)
	  wr[i] = wr[i+1] + w[i];

	llg ans = wl[n]*l + (n-1)*ql;
	ans = Min(ans, wr[1]*r + (n-1)*qr);

	for(llg i = 1;i <= n;i++)
	{
		llg left = i,right = n - i;
		llg tmp = wl[left] * l + wr[left + 1] * r;
		llg d;
		if(left > right){
			d = left - right - 1;
			tmp += d*ql;
		} else if(right > left)
		{
			d = right - left - 1;
			tmp += d*qr;
		}
		ans = Min(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}
