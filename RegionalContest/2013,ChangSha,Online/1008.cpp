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
const int maxn = 10;
llg mod;
llg l,kk;
struct Matrix{
	llg N,a[maxn][maxn];
	void init(){
		N = (llg)2;
		mod = kk;
		a[0][0] = 2*l;a[0][1] = -l;
		a[1][0] = (llg)1;a[1][1] = (llg)0;
	}
	void mul(const Matrix r)
	{
		Matrix l(*this);
		for(llg i = 0;i < N;i++)
		{
			for(llg j = 0;j < N;j++)
			{
				llg temp = 0;
				for(llg k = 0;k < N;++k)
				{
					temp = (temp+l.a[i][k] * r.a[k][j])%mod;
				}
				a[i][j] = temp%mod;
			}
		}
	}
	void pow(llg e)
	{
		Matrix temp(*this);
		a[0][0] = 0;a[0][1] = 0;
		a[1][0] = 0;a[1][1] = 0;
		for(llg i = 0;i < N;++i)	{a[i][i] = 1;}
		for(;e;e >>=1){
			if(e & 1)	this->mul(temp);
			temp.mul(temp);
		}
	}
}mat;

int main()
{
	while(scanf("%lld %lld",&kk,&l) != EOF)
	{
		mat.init();
		mat.pow(kk);
		llg ans = 0;
		ans = ((mat.a[1][0]*2*l+2*mat.a[1][1])%mod-1+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
