#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int r,c;
int map[1010][1010];
int endx,endy;
char str[1010][1010];
int bu[1000000],num[1000000],cnt;
int myx,myy;

bool vis[1010][1010];
int que[1000000][2];

int add(int x0, int y0, int x1, int y1, int rear,int ans) {
    if (( x1 < 0 ) || ( y1 < 0 ) || ( x1 > c ) || ( y1 > r )) return rear;
    if (( map[x1][y1] == 0 )||( vis[x1][y1])) return rear;
    
	if(str[x1][y1] >= '1' && str[x1][y1]<='9')
	{
		cnt+=str[x1][y1] - '0';
	}
	printf("xin : %d %d  %c",x1,y1,str[x1][y1]);
	vis[x1][y1] = 1;
    //map[x1][y1] = mat[x0][y0] + 1;
    que[rear][0] = x1;
    que[rear][1] = y1;
    return ++rear;
}
void bfs(int x1,int y1)
{
	int ans = -1;
	memset(vis,0,sizeof(vis));
	int front = 0,rear = 1;
	que[0][0] = x1;que[0][1] = y1;
	vis[x1][y1] = 1;
	while(front < rear)
	{
	//	ans = ans+1;
	//	printf("ans = %d  \n",ans);
		int xx = que[front][0];
		int yy = que[front][1];
		rear = add(xx,yy,xx+1,yy,rear,ans);
		rear = add(xx,yy,xx-1,yy,rear,ans);
		rear = add(xx,yy,xx,yy+1,rear,ans);
		rear = add(xx,yy,xx,yy-1,rear,ans);

		printf("\n");
		if(vis[myx][myy])	break;
	//	printf("xx = %d %d\n",xx,yy);
		front++;
	}
}
int main()
{
	int i,j,k;
	scanf("%d %d",&r,&c);
	for(i = 0;i < r;i++)
	{
		scanf("%s",str[i]);
		for(j = 0;j < c;j++)
		{
			if(str[i][j] == 'T')
			  map[i][j] = 0;
			else
			  map[i][j] = 1;

			if(str[i][j] == 'E')
			{
				endx = i;
				endy = j;
			}
			
			if(str[i][j] == 'S')
			{
				myx = i;
				myy = j;
			}
		}
	}
//	printf("endx = %d %d\n",endx,endy);
	cnt = 0;
	bfs(endx,endy);
	printf("%d\n",cnt);
/*	cnt = bfs(4,3);
	for(i = 0;i < r;i++)
	{
		for(j = 0;j < c;j++)
		{
			if(str[i][j] == 'S')
			{
				mycnt = bfs(i,j);
			}
			if(str[i][j] >= '1' && str[i][j] <= '9')
			{
				num[cnt] = str[i][j] - '0';
				bu[cnt++] = bfs(i,j);
			}
		}
	}
	int ans = 0;
	printf("mycnt = %d\n",mycnt);
	for(i = 0;i < cnt;i++)
	{
		printf("%d %d\n",bu[i],num[i]);
		if(mycnt >= bu[i])
		{
			ans+=num[i];
		}
	}
	printf("%d\n",ans);*/
	return 0;
}
