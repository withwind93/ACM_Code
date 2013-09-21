#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
int dp[102][102];
int p[102];
int n,k;
vector<int>vect[102];
void dfs(int u,int fa)
{
    int v;
    dp[u][1]=p[u];
    for(int i=0; i<vect[u].size(); ++i)
    {
        v=vect[u][i];
        if(v==fa)continue;
        dfs(v,u);
        for(int j=k; j>=1; --j)
        {
            for(int w=1; w<=j; ++w)
            {
                dp[u][j]=max(dp[u][j],dp[u][w]+dp[v][j-w]);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        int i,j,u,v,ans=0;
        for(i=0; i<=n; i++)
        {
            vect[i].clear();
            for(j=0; j<=k; j++)
                dp[i][j]=0;
        }

        for(i=1; i<=n; i++)
		{
			scanf("%d",&p[i]);
		}
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            u++,v++;
            vect[u].push_back(v);
            vect[v].push_back(u);
        }
        dfs(1,-1);
        for(i=1; i<=n; i++)
        {
            ans=max(ans,dp[i][k]);
        }
        printf("%d\n",ans);
    }
    return 0;
}


