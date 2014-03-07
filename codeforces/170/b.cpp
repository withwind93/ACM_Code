/*************************************************************************
    > File Name: b.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/2/28 23:43:37
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
char s[50][50];
int hash[26];
int main()
{
	int i,j,k;
	int len;
	int n;
	scanf("%d",&n);
	for(i=0;i<26;i++)
	  hash[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		len=strlen(s[i]);
		for(j=0;j<len;j++)
		  hash[s[i][j]-'a']++;
	}
	int flag=1;
	for(i=0;i<26;i++)
	  if(hash[i]==0)	
		{
			flag=0;
			printf("%c",i+'a');
			return 0;
		}
	if(flag)
	{
		char str[3];
		for(int ii=0;ii<26;ii++)
		  for(int jj=0;jj<26;jj++)
		  {
			str[0]='a'+ii;
			str[1]='a'+jj;
			str[2]='\0';
			int find=0;
			for(i=1;i<=n;i++)
			{
				len=strlen(s[i]);
				for(j=1;j<len;j++)
				{
					if(s[i][j-1]==str[0] && s[i][j]==str[1])
					{
						find=1;
						break;
					}
				}
			}
			if(find==0)
			{
				printf("%s",str);
				return 0;
			}
		  }
	}
	return 0;
}
