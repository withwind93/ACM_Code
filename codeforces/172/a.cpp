/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/10 23:21:19
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
	char s[1100];
	scanf("%s",s);
	if(s[0]>='a' && s[0]<='z')
	  s[0]=s[0]-'a'+'A';
	printf("%s\n",s);
	return 0;

}
