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
string s1 = "*------------*";
string s2 = "|............|";
string s3 = "|------------|";
int main()
{
	int T;
	cin >> T;
	int cas = 1;
	while(T--)
	{
		cout << "Case #"<<cas<<":"<<endl;
		cas++;
		int n;
		cin >> n;
		cout << s1 <<endl;
		int m = (100 - n)/10;
		n = n / 10;
		for(int i = 1;i <= m;i++)
		  cout<<s2<<endl;
		for(int i = 1;i <= n;i++)
		  cout<<s3<<endl;
		cout << s1 <<endl;
	}
	return 0;
}
