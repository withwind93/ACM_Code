#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <algorithm>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}

struct nod
{
	int x,y;
}node[10];
int cmp(nod a,nod b)
{
	if(a.y == b.y)	return a.x < b.x;
	return a.y < b.y;
}
int main()
{
	int n;
	int flag = 0;
	for(int i = 1;i <= 8;i++)
	{
		cin>>node[i].x>>node[i].y;
		for(int j = 1;j < i;j++)
		{
			if(node[i].x == node[j].x && node[i].y == node[j].y)
			{
				flag = 1;
			}
		}
	}
	if(flag)
	{
		printf("ugly\n");
		return 0;
	}
	sort(node+1,node+9,cmp);
/*	for(int i = 1;i <= 8;i++)
	{
		cout<<node[i].x<<"  "<<node[i].y<<endl;
	}*/
	if(node[1].y == node[2].y && node[2].y == node[3].y && 
		node[4].y == node[5].y &&
		node[6].y == node[7].y && node[7].y == node[8].y && 
		node[1].x == node[4].x && node[4].x == node[6].x && 
		node[2].x == node[7].x &&  
		node[3].x == node[5].x && node[5].x == node[8].x)
	  printf("respectable\n");
	else			printf("ugly\n");
	return 0;
}


