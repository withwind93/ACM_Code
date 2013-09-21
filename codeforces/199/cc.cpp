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
//int r,h;
int main()
{
//	scanf("%d %d",&r,&h);

	for(int tr = 1;tr <= 10000000;tr++)
	  for(int th = 1;th <= 10;th++)
	  {
		  int r = tr,h = th;
		  //printf("%d %d: ",r,h);
		  int ans = 0;
		  while(h >= r)	ans+=2,h-=r;
		  if(2*h >= r)	ans+=2;
		  else	ans+=1;
		  if(tr >= 10000000)
			printf("%d\n",ans);
		  //cout<<ans<<endl;
		  /*	int cnt = h / r,t = h % r;
	int ans = cnt * 2;
	if(2*t >= r)
	{
		ans = ans + 2;
		//if(t*t*4 >= 3*r*r)	ans++;
	}
	else			ans++;
	printf("%d\n",ans);
	*/  
	  }
	return 0;
}

