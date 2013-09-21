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
llg x,y;
llg mod = (llg)10;
int a[100];
//llg dp[100][2][10];
llg dp[100][10];
llg dfs(int len,int remain,bool fp)
{
	if(len == 0)	return remain == 0 ? 1:0;
	//printf("len = %d\n",len);
	if(fp && dp[len][remain] != -1)	
	  return dp[len][remain];
	int fpmax = (fp == false) ? a[len] : 9;
	llg ret = 0;
	for(int i = 0;i <= fpmax;i++)
		ret += dfs(len-1,(remain + i) %10,fp || i < fpmax);
	if(fp)	  dp[len][remain] = ret;
	return ret;
}
llg gao(llg n)
{
	if(n < 0)	return 0;
	memset(a,0,sizeof(a));
	memset(dp,-1,sizeof(dp));
	llg ans = 0;
	int cnt = 0;
	llg nn = n;
	while(nn)
	{
		a[++cnt] = nn%10;
		nn = nn / 10;
	}
	ans = dfs(cnt,0,false);
	
/*	for(int i = 0;i < cnt/2;i++)
	{
		int tmp = a[i];
		a[i] = a[cnt - i - 1];
		a[cnt - i - 1] = tmp;
	}
	dp[0][0][0] = 1;
	for(int i = 0;i < cnt;i++)
	{
		for(int ise = 0;ise <= 1;++ise)
		{
			for(int j = 0;j < 10;j++)
			{
				for(int d = 0;d <= (ise ? a[i] : 9);d++)
				{
					if(i == 0 && d > a[0])	break;
					int nextj = (j + d)%10;
					int nextise = ise && (d == (ise ? a[i] : 9));
					dp[i+1][nextise][nextj] += dp[i][ise][j];
				}
			}
		}
	}
	ans = dp[cnt][0][0] + dp[cnt][1][0];*/
	//printf("n = %lld %lld\n",n,ans);
	//printf("%d %d\n",dp[cnt][0][0],dp[cnt][1][0]);
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	int cas = 1;
	while(T--)
	{
		scanf("%I64d %I64d",&x,&y);
		//printf("%lld %lld\n",gao2(y),gao2(x-1));
		printf("Case #%d: %I64d\n",cas++,gao(y) - gao(x - 1));
	}
	return 0;
}
