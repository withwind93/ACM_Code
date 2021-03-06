/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/26 1:07:29
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
const llg mod = 1000000007;
llg a,b,n;
llg ans;

bool check(llg sum)
{
	while(sum)
	{
		llg tmp = sum%10;
		if(tmp != a && tmp != b)	return false;
		sum/=10;
	}
	return true;
}
void exgcd(llg a,llg b,llg &x,llg &y)
{
	if(b == 0){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main()
{
	int i,j,k;
	cin>>a>>b>>n;
	
	if(check(n*b))	ans = 1;
	else			ans=0;
	llg count=1,x,y;
	for(i = 1;i<=n;i++)
	{
		llg tmp = i*a+(n-i)*b;
//cout<<"tmp  : "<<tmp<<endl;
		count=count*(n-i+1)%mod;
//	cout<<"n-i+1 : "<<n-i+1<<endl;	
//	count=count/(i);
		exgcd(i%mod,mod,x,y);
		if(x<0)	x+=mod;
		count=count*x%mod;
		
		if(check(tmp))	
		{
			ans+=count;
			ans%=mod;
		}
//	cout<<"count : "<<count<<endl;	
	}
	cout<<ans<<endl;
	return 0;
}
