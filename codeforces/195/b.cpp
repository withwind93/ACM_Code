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
int m,r;

int main()
{
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
int m,r;

int main()
{
	scanf("%d %d",&m,&r);
	
	double a = sqrt(2);
	double ans = (m+1.0)*r + (m-1.0)*a*r + (m-1)*(m-1)*r;
	printf("%lf\n",ans/(m*1.0));
	return 0;
}
	scanf("%d %d",&m,&r);	
	double a = sqrt(2);
	double ans = (m+1.0)*r + (m-1.0)*a*r + (m-1)*(m-1)*r;
	printf("%lf\n",ans/(m*1.0));
	return 0;
}
