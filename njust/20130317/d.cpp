/*************************************************************************
    > File Name: d.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/17 12:26:46
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
llg gcd(llg x,llg y)
{
	return y==0?x:gcd(y,x%y);
}
void exgcd(long long a, long long b, long long& x, long long &y) {
        if(b == 0) {
                x = 1;
                y = 0;
                return;
        }
        exgcd(b, a % b, x, y);
        long long tmp = x;
        x = y;
        y = tmp - a / b * y;
}

llg ans(llg a,llg b,llg n)
{
	llg x,y,d;
	llg t;
	llg c;
	c = gcd(a,b);
	if(n%c!=0)	return -1;
	a=a/c;b=b/c;n=n/c;
	exgcd(a,b,x,y);
	x=(n*x)%b;
	if(b<0)	b=-b;
	if(x<0)	x+=b;
	return x;
}

int main()
{
	llg i,j,k;
	llg a,b,x,y,m,n,l;
	llg k1,k2;
	while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
	{
		x = (x+l)%l;y=(y+l)%l;
		x = l-x;y=l-y;
		if(m == n)	{printf("Impossible\n");continue;}
		llg tmp = ans(n-m,l,x-y);
		if(tmp==-1)	{printf("Impossible\n");continue;}
		else		{printf("%lld\n",(tmp));}
	}
	return 0;
}
