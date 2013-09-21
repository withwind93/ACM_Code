#include<stdio.h>
#include<string.h>

const int MAXN = 210;
int c[MAXN][MAXN];
int vis[MAXN], list[MAXN], pre[MAXN];
int n, m;
int sourse, sink;

int ek() {
    int i, u, last = 0, top = 1, low;
    memset ( vis, 0, sizeof ( vis ) );
    list[0] = sourse;
    vis[sourse] = 1;
    pre[sourse] = -1;
    low = ( 1 << 30 );
    while ( last < top ) {
        u = list[last++];
        for ( i = 1; i <= n; i++ )
            if ( !vis[i] && c[u][i] > 0 ) {
                vis[i] = 1;
                pre[i] = u;
                low = ( low < c[u][i] ) ? low : c[u][i];
                list[top++] = i;
            }
        if ( vis[sink] ) return low;
    }
    return 0;
}
int maxflow() {
    int u, low, flow = 0;
    while ( low = ek() ) {
        u = sink;
        while ( pre[u] != -1 ) {
            c[pre[u]][u] -= low;
            c[u][pre[u]] += low;
            u = pre[u];
        }
        flow += low;
    }
    return flow;
}

int main() {
    int T;
    scanf ( "%d", &T );
    for ( int kase = 1; kase <= T; kase++ ) {
        scanf ( "%d%d", &n, &m );
        memset ( c, 0, sizeof ( c ) );

        printf ( "Case #%d:\n", kase );

        int initflow = 0;
        for ( int i = 0; i < m; i++ ) {
            int x, y, z;
            scanf ( "%d%d%d", &x, &y, &z );
            c[x][y] += z;
            c[y][x] += z;

            sourse = 1;
            sink = n;
            int nowflow;
            if ( sourse != sink ) nowflow = maxflow();
            else nowflow = 0;

            if ( nowflow > 0 ) {
                printf ( "%d %d\n", i + 1, nowflow );
                initflow = nowflow;
            }
        }
    }
}

