/*************************************************************************
  > File Name: d.cpp
  > Author: withwind
  > Mail: withwind93@gmail.com 
  > Created Time: 2013/3/22 0:21:38
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
const llg mod=1000000007;
llg fun(llg n)
{
	llg ans=1;
	for(llg i=1;i<=n;i++)
	{
		ans=(ans*i)%mod;
	}
	return ans;
}
int b[20]={1,3,15,133,2025,37851,1030367,36362925};
int main()
{
	llg i,j,k;
	llg n;
	cin>>n;
	if(n%2==0)	{printf("0");return 0;}

	llg ans=1;
/*	cout<<"ans = "<<ans;
	llg ji = fun(n);
	cout<<"ji = "<<ji;
	ans = ans*ji%mod;*/
	for(i=1;i<=n;i++)
	{
		ans=(ans*i)%mod;
	}
	ans=ans*b[n/2]%mod;
	cout<<ans<<endl;
	return 0;
}
