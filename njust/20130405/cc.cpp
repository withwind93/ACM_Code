#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

const int MAXN = 1005;

int N;
bool edge[MAXN][MAXN];

int is[MAXN], dfn[MAXN], low[MAXN];
void dfs(int u, int d) {
	dfn[u] = low[u] = d;
	int out = 0, ok = 0;
	for (int v = 1; v <= N; ++v) {
		if (edge[u][v]) {
			if (!dfn[v]) {
				++out;
				dfs(v, d + 1);
				if (low[v] >= dfn[u]) {
					ok++;
				}
				checkMin(low[u], low[v]);
			} else {
				checkMin(low[u], dfn[v]);
			}
		}
	}
	if(d==1)
	{
		//printf("out = %d\n",out);
		if(out>1)	is[u] = out;
	}
	else{
		//printf("ok = %d\n",ok);
		if(ok)	is[u] = ok+1;
	}
}
void tarjan() { // dn == 1 时注意一下
	fill(dfn, dfn + N + 1, 0);
	fill(low, low + N + 1, 0);
	fill(is, is + N + 1, 0);
	for (int u = 1; u <= N; ++u) {
		if (!dfn[u]) {
			dfs(u, 1);
		}
	}
}

int main() {
	int casen = 0;
	while (1)
	{
		N = MAXN;
		fill(edge[1], edge[N + 1], false);
		int u, v;
		int flag = 0;
		N = 0;
		for (;;) {
			scanf("%d", &u);
			N = N>u?N:u;
			if(u == 0)	break;
			scanf("%d", &v);
			N = N>v?N:v;
			flag++;
			edge[u][v] = true;
			edge[v][u] = true;
		}
		if(flag == 0)	break;
		tarjan();
		if(casen)	
			printf("\n");
		printf("Network #%d\n",++casen);
		flag = 0;
		for(int i=1;i<=N;i++)
		{
			if(is[i])
			{
				flag++;
				printf("  SPF node %d leaves %d subnets\n",i,is[i]);
			}
		}
		if(!flag)
		{
			printf("  No SPF nodes\n");
		}
//		printf("%d\n", accumulate(is, is + N + 1, 0));
	}
	return 0;
}

