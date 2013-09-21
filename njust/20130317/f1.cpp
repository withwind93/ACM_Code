#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
struct no
{
	int va;
	int fa;
	int ch;
	int child[110];
}node[110];
int dp[110][110];
int max(int x,int y)
{
	return x>y?x:y;
}
int k;
void dfs(int now)
{
	int i,j;
	int s=node[now].ch;
/*	if(s==0)	
	{
		if(k!=1)	return 0;
		return node[now].va;
	}*/
	for(i=0;i<s;i++)
	{
		int next = node[now].child[i];
		if(node[next].ch)   dfs(next);
		for(j=k;j>=1;j--)
			for(int w=1;w<=j;w++)
				if(dp[next][j-w]+dp[now][w]>dp[now][j])
					dp[now][j] = dp[next][j-w]+dp[now][w];
					  
//			if(j-w>=0)
//			  if(dp[now][j-w]+dp[next][w]>dp[now][j])
//				dp[now][j] = dp[now][j-w]+dp[next][w];
		/*		for(j=k;j>=2;j--)
				for(int w=0;w<=j;w++)
				{
				if(j-w>=0)
				{
				int t=dfs(next,w);
				if(dp[now][j-w]+t>dp[now][j])
				dp[now][j] = dp[now][j-w]+t;
				}
				}*/


/*		printf("\n");
		for(j=1;j<=10;j++)
		{
			for(int w=0;w<=5;w++)
			{
				printf("%d  ",dp[j][w]);
			}
			printf("\n");
		}*/
	}
}
int main()
{
	int i,j;
	int tmp,x,y;
	int n;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			dp[i][1]=tmp;
			node[i].va = tmp;
			node[i].fa = 0;
			node[i].ch = 0;
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&x,&y);
			x++;y++;
			node[y].fa = x;
			node[x].child[node[x].ch++]=y;
			//            printf("%d",node[x].ch);
		}
		for(i=1;i<=n;i++)
		  if(node[i].fa==0)   break;
		int root=i;
		dfs(root);
		int ans1=0;
		for(i=1;i<=n;i++)
		  if(ans1<=dp[i][k])   ans1=dp[i][k];
		printf("%d\n",ans1);
	}
	return 0;
}

