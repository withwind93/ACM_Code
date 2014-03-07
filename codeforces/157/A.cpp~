#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
using namespace std;

int main()
{
	char s[10];
	int flag=1;
	for(int i=1;i<=8;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=6;j++)
//		  if(s[j-1]==s[j+1] && s[j-1]!=s[j])
//			flag=0;
		{
			if(s[j]=='W')
			{
				if(s[j-1]=='W' || s[j+1]=='W')
				  flag=0;
			}
			else
			{
				if(s[j-1]=='B' || s[j+1]=='B')
				  flag=0;
			}
		}
		if(s[0]==s[7])	flag=0;
	}
	if(flag)	printf("YES\n");
	else		printf("NO\n");
	return 0;
}

