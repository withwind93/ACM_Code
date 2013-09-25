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
const int maxn = 80010;
const int mod = 1000000007;
bool a[maxn];
int p[maxn],num;
void init()
{
	num=1;/*start from 1*/
	for(int i=2;i<=maxn;i++)
	{
		if(!a[i])
		{
			p[num++]=i;
		}
		for (int j = 1; j < num; j++)
		{
			if(p[j]*i>maxn) break;
			a[p[j] * i] = true;
			if (i%p[j] == 0)
				break;
		}
	}
}
int one[maxn],add[maxn],mul[maxn];
llg ans = 0;
int n;
int inv3 = 333333336;
void getans1()
{
	llg tmp = 0;//a+b+c
	for(int i = 1;i < num;i++)
	{
		int t = p[i];
		int left = n - t;
		if(left <= 2)	break;
		ans = (ans + mul[left])%mod;
		tmp = (tmp + add[left])%mod;
		if(left%2 == 0 && left == t*2 && a[left/2] == false)
		{//a + a + a
			tmp = (tmp + 2)%mod;
		}
		else if(left%2 == 0 && a[left/2] == false)
		{
			tmp = (tmp + 1)%mod;
		}
	}
	tmp = (((tmp)*inv3)%mod);
	ans = (ans + tmp)%mod;
}
void getans2()
{
	//a*b*c
	int tnum = 0;
	for(int i = 1;i < num;i++)
	{
		if(p[i] > n)	break;
		if(n%p[i] == 0)
		{
			while(n%p[i] == 0)
			{
				tnum++;
				n /= p[i];
				if(tnum > 3)	return ;
			}
		}
	}
	if(tnum == 3 && n == 1)	ans = (ans + 1)%mod;
	return ;
}

int main()
{
	init();
	//one
	for(int i = 0;i < maxn;i++)
	{
		if(a[i] == false)	one[i] = 1;
		else				one[i] = 0;
	}
	//two
	for(int i = 1;i < num;i++)
	{
		for(int j = i;j < num;j++)
		{
			int t = p[i] + p[j];
			if(t >= maxn || t < 0)	break;
			else					add[t1] = (add[t1] + 1)%mod;
		}
	}
	for(int i = 1;i < num;i++)
	{
		for(int j = i;j < num;j++)
		{
			int t = p[i]*p[j];
			if(t >= maxn || t < 0)	break;
			else					mul[t] = (mul[t] + 1)%mod;
		}
	}
	while(scanf("%d",&n) != EOF)
	{
		ans = (one[n]%mod + (add[n]%mod + mul[n]%mod)%mod)%mod; 
		getans1();//a + b + c or a + b*c
		getans2();//a * b * c
		printf("%lld\n",ans);
	}
	return 0;
}

