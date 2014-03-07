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
llg n,m;
llg a[100010];
llg cnt;
int main()
{
	cnt = 0;
	cin>>n>>m;
	for(int i = 1;i <= m;i++)
	  cin>>a[i];
	cnt = a[1] - 1;
	for(int i = 2;i <= m;i++)
	{
		if(a[i] > a[i-1])
		  cnt += a[i] - a[i - 1];
		else if(a[i-1] > a[i])
		  cnt += a[i] - a[i - 1] + n;
	}
	cout<<cnt<<endl;
	return 0;
}

