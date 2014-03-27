#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
int n;
int a[1000010];
bool hash[1000010];
int ansn = 0,ans[1000010];
int ttn = 0,tn = 0,tmp[1000010];
const int maxn = 1000000;
int main()
{
	//scanf("%d",&n);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
		hash[a[i]] = true;
		a[i]-=1;
		if(hash[maxn - a[i]])	a[i] = -1;
	} //  scanf("%d",&a[i]);
	for(int i = 1;i < 1000000;i++)
	{
		if(hash[i] == false && hash[maxn-i+1] == false)	
		{
			tmp[tn++] = i;	
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == -1)	continue;
		int now = maxn - a[i];
		if(hash[now] == false)
		{
			ans[ansn++] = now;
		}
		else{
			int t = tmp[ttn++];
			ans[ansn++] = t;
			ans[ansn++] = maxn - t+1;
			
		}
	}
	cout << ansn << endl;
	for(int i = 0;i < ansn-1;i++)
	  cout << ans[i] << " ";
	cout << ans[ansn-1] << endl;
	return 0;
}

