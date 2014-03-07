/*************************************************************************
    > File Name: d.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/11 9:04:19
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], stack[100005];
int main()
{
 int i,top,n,ans;

    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);

    stack[1]=a[1]; top=1; ans=0;
    for (i=2;i<=n;i++)
    {
//			for(int j=1;j<=5;j++)
//				printf("top = %d stack = %d\n",j,stack[j]);
        while (top>=1 && a[i]>stack[top])
        {
			printf("first: %d ^ %d max(%d)\n",a[i],stack[top],max(ans,a[i] ^ stack[top]));
            ans=max(ans,a[i] ^ stack[top]);	
			top--;
        }
        stack[++top]=a[i];
    }

    stack[1]=a[n]; top=1;
    for (i=n-1;i>=1;i--)
    {
//					for(int j=1;j<=5;j++)
//				printf("top = %d stack = %d\n",j,stack[j]);
        while (top>=1 && a[i]>stack[top])
        {
			printf("Second: %d ^ %d max(%d)\n",a[i],stack[top],max(ans,a[i] ^ stack[top]));
			ans=max(ans,a[i] ^ stack[top]); top--;
        }
        stack[++top]=a[i];
    }

    cout<<ans;
	return 0;
}
