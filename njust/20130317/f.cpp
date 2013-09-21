/*************************************************************************
    > File Name: f.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/17 14:30:08
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct no
{
	int fa;
	int va;
	vector<int> child;
	no()
	{
		fa = 0;
		va = 0;
	}
}node[100];
int dp[110][110];
//int vis[110];
int max(int x,int y)
{
	return x>y?x:y;
}
int k,n;

int DFS(int x)
{
//	vis[x]=1;
	int num=node[x].child.size();
	int father;
	for(int i=0;i<num;i++)
	{
		int next=node[x].child[i];
//		if(!vis[next])
//		{
			DFS(next);
			int tmp=0,num;
			for(int j=k-1;j>=1;j--)
			{
				if(dp[x][j+1]<(dp[x][j]+node[next].va))
					  dp[x][j+1]=dp[x][j]+node[next].va;	
				for(int jj=k-1;jj>=1;jj--)
				{
					if(j<=k && j-jj>=0)
					{
						if(dp[x][j]<(dp[x][j-jj]+dp[next][jj]))
							dp[x][j]=dp[x][j-jj]+dp[next][jj];
					}
				}
			}
					for(int i=1;i<=n;i++)
				{
					for(int j = 1;j<=k;j++)
					 printf("%d  ",dp[i][j]);
					printf("\n");
				}	
//		}
	}
}
int main()
{
	int i,j;
	int tmp,x,y;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			node[i].va = tmp;
			dp[i][1]=tmp;
			dp[i][0]=0;
//			vis[i]=0;
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d %d",&x,&y);
			x++;y++;
			node[y].fa=x;
			node[x].child.push_back(y);
	//		printf("%d\n",node[x].child.size());
		}
		for(i=1;i<=n;i++)
		{
			if(node[i].fa==0)	break;
		}
		int root = i;
		DFS(root);
/*		for(i=1;i<=n;i++)
		{
			for(j = 1;j<=k;j++)
			  printf("%d  ",dp[i][j]);
			printf("\n");
		}*/
		printf("%d\n",dp[root][k]);
	}
	return 0;
}
