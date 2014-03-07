#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 100010
struct tree
{
	vector<int> child;
}node[maxn];
int n,m,d;
int dpdown[maxn][2];/*0 is longest 1 is second*/
int dpup[maxn];
int next[maxn];/*longest distance next*/
bool vis[maxn];
bool evil[maxn];
void addedge(int x,int y)
{
	node[x].child.push_back(y);
	node[y].child.push_back(x);
}
int mymax(int x,int y)
{return x>y?x:y;}

void dfs1(int fa,int now)
{
	vis[now] = true;
	dpdown[now][0] = dpdown[now][1] = -1;
	dpup[now] = -1;
	next[now] = 0;

	if(evil[now])	dpdown[now][0] = 0;
	for(int i = 0;i < node[now].child.size();i++)
	{
		int son = node[now].child[i];
		if(vis[son] || son == fa)	continue;
		dfs1(now,son);
		
		if(dpdown[son][0] >= 0)
		{/*³ýÈ¥-1*/
			if(dpdown[son][0] + 1 >= dpdown[now][0])
			{
				dpdown[now][1] = mymax(dpdown[now][0],dpdown[now][1]);

				dpdown[now][0] = dpdown[son][0] + 1;
				next[now] = son;
			}
			else
			{
				dpdown[now][1] = mymax(dpdown[son][0] + 1,dpdown[now][1]);
			}
		}
	}
}
void dfs2(int fa,int now)
{
	for(int i = 0;i < node[now].child.size();i++)
	{
		int son = node[now].child[i];
		if(son == fa)	continue;
		
		if(dpup[now] >= 0)
			dpup[son] = dpup[now] + 1;
		if(next[now] != son && dpdown[now][0] >= 0)
		{
			dpup[son] = mymax(dpup[son],dpdown[now][0] + 1);
		}
		else if(dpdown[now][1] >= 0)
		{
			dpup[son] = mymax(dpup[son],dpdown[now][1] + 1);
		}
		dfs2(now,son);
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&d);
	for(int i = 1;i <= m;i++)
	{
		int x;
		scanf("%d",&x);
		evil[x] = true;
	}
	for(int i = 1;i <= n - 1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		addedge(x,y);
	}
	dfs1(-1,1);
	dfs2(-1,1);
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(dpdown[i][0] <= d && dpup[i] <= d)
		  ans++;
	}
	printf("%d\n",ans);
	return 0;
}

