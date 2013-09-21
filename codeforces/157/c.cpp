#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
using namespace std;

int main()
{
	char s[100010];
	int firstone=0,first=0;
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	  if(s[i]=='1')	{firstone=i;break;}
	for(int i=firstone;i<len;i++)
	  if(s[i]=='0')	{first=i;break;}
	int tlen=0;
	char tmp[100010];
	for(int i=firstone;i<len;i++)
	{
		if(i==first)	continue;
		tmp[tlen++]=s[i];
	}
	tmp[tlen]='\0';
	printf("%s\n",tmp);
	return 0;
}

