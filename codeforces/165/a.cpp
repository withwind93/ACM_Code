#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
	int n,a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if(a<60)
		  printf("NO\n");
		else
		{
			a=180-a;
			if(360%a==0)
			  printf("YES\n");  
			else
			  printf("NO\n");
		}
	}
	return 0;
}



