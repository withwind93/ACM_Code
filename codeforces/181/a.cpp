/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/25 23:22:40
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int i,j,k;
	int n;
	scanf("%d",&n);
	int a[100];
	int n1=0,n2=0,n3=0;
	int flag = 0;
	for(i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i] == 0)	n3++;
		if(a[i] < 0)	n1++;
		if(a[i] > 0)	n2++;
	}
	int flag1,flag2,flag3;
	if(n2==0)
	{
		printf("1");
		for(i = 1;i<=n;i++)
		{
			if(a[i]<0)	{flag1=i;cout<<" "<<a[i]<<endl;break;}
		}
		n2=2;
		printf("2");
		for(i = 1;i<=n;i++)
		{
			if(i == flag1)	continue;	
			if(!n2)	break;
			if(a[i]<0)	
			{
				cout<<" "<<a[i];
				if(n2 == 2)	flag2=i;
				if(n2 == 1) {flag3=i;break;}
				n2--;
			}
		}
		printf("\n%d",n-3);
		for(i = 1;i<=n;i++)
		{
			if(i == flag1 || i==flag2 || i==flag3)	continue;
			cout<<" "<<a[i]<<endl;
		}
	}
	else
	{
		printf("1");
		for(i = 1;i<=n;i++)
		{
			if(a[i]<0)	{flag1=i;cout<<" "<<a[i]<<endl;break;}
		}
		n2=1;
		printf("1");
		for(i = 1;i<=n;i++)
		{
			if(a[i]>0)	
			{
				cout<<" "<<a[i]<<endl;
				flag2=i;
				break;
			}
		}
		printf("%d",n-2);
		for(i = 1;i<=n;i++)
		{
			if(i == flag1 || i==flag2)	continue;
			cout<<" "<<a[i];
		}
	}
/*i
 *
 *	f(n2 == 0)
	{
		printf("%d",n1-2);
		for(i = 1;i<=n;i++)
		{
			if(n1 == 2)	break;
			if(a[i]<0)
			{
				printf(" %d",a[i]);
				n1--;
			}
		}
		printf("\n2");
		n2=2;
		for(i = n;i>=1;i--)
		{
			if(n2==0)	break;
			if(a[i]<0)
			{
				n2--;
				printf(" %d",a[i]);
			}
		}
		printf("\n%d",n3);
		for(i = 1;i<=n3;i++)
		  printf(" 0");
	}
	else
	{
		printf("%d",n1);
		for(i = 1;i<=n;i++)
		{
			if(n1 == 0)	break;
			if(a[i]<0)
			{
				printf(" %d",a[i]);
				n1--;
			}
		}
		printf("\n%d",n2);
		for(i = 1;i<=n;i++)
		{
			if(n2==0)	break;
			if(a[i]>0)
			{
				n2--;
				printf(" %d",a[i]);
			}
		}
		printf("\n%d",n3);
		for(i = 1;i<=n3;i++)
		  printf(" 0");
	}*/
	return 0;
}
