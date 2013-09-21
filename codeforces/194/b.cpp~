#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
char str[1000];
llg x[9],y[9];
int dir[8][2] = {{0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,1},{2,2}};
bool get(int tx,int ty)
{
	for(int i = 1;i <= 8;i++)
	{
		if(tx == x[i] && ty == y[i])
		  return true;
	}
	return false;
}
int main()
{
	int n;
	int maxn = -1;
	int flag = 0;
	int tx = 1000000000,ty = 1000000000;
	for(int i = 1;i <= 8;i++)
	{
		//scanf("%d %d",&x[i],&y[i]);
		cin>>x[i]>>y[i];
		if(tx > x[i] || ty > y[i])
		{
			tx = x[i];
			ty = y[i];
		}
	}
	//printf("  dd %d %d",tx,ty);
	
	if(get(tx+dir[2][0],ty+dir[2][1]) && get(tx+dir[3][0],ty+dir[3][1]) &&
		get(tx+dir[4][0],ty+dir[4][1]) && get(tx+dir[5][0],ty+dir[5][1]) && 
		get(tx+dir[6][0],ty+dir[6][1]) && get(tx+dir[7][0],ty+dir[7][1]) && 
		get(tx+dir[1][0],ty+dir[1][1]))
		printf("respectable\n");
	else			printf("ugly\n");
	return 0;
}

