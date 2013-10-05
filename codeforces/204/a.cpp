#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int a[4100];
int main()
{
	scanf("%d",&n);
	int sum = 0;
	int cnt = 0;
	for(int i = 1;i <= 2*n;i++)
	{
		int x,y;
		scanf("%d.%d",&x,&y);
		sum += y;
		if(y != 0)	cnt++;
	}
	int minx = (cnt-n) > 0 ? 0:(cnt-n);
	int maxx = (cnt) > n ? cnt : n;
	int ans = 40000010;
	printf("min = %d %d\n",minx,maxx);
	for(int i = minx;i <= maxx;i++)
	{
		int tmp = sum - i;
		if(tmp < 0)	tmp = -tmp;
		ans = ans > tmp ? tmp : ans;
	}
	printf("%d.%d\n",ans / 1000,ans % 1000);
	return 0;
}
