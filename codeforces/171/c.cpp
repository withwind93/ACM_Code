/*************************************************************************
    > File Name: c.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/5 0:36:55
 ************************************************************************/

#include <stdio.h>

int a[100010],left[100010],right[100010];
int main()
{
	int i,j,k;
	int n,m;
	scanf("%d%d",&n,&m);
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	//暴力坡形长度
	left[1]=1;//往左数
	for(i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])	left[i]=left[i-1]+1;
		else				left[i]=1;
	}
	right[n]=n;
	for(i=n-1;i>=1;i--)
	{
		if(a[i]<=a[i+1])	right[i]=right[i+1]+1;
		else				right[i]=1;
	}

	int x,y;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
//		printf("%d %d\n",right[x],left[y]);
		if(right[x]+left[y] >= y-x+1)	printf("Yes\n");
		else							printf("No\n");
		
		/*		int tx=x,ty=y,flag=0;
		int flag1=1,flag2=1;
		while(tx != ty)
		{
			if(flag1 == 0 && flag2 == 0)	break;
			if(tx-ty==1 || ty-tx==1)
			{
				tx=ty;
				break;
			}
			if(vis[tx+1]==1)	tx++;
			else				flag1=0;
			if(vis[ty]==0)	ty--;
			else				flag2=0;
		
		}
		if(tx==ty)	printf("Yes\n");
		else		printf("No\n");
*/
	}
	return 0;
}
