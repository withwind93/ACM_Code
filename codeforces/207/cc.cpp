#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn 300005
int next[maxn];
int win[maxn];
int res[maxn];
int main()
{
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        int now=a;
        while(now<=b)
        {
            if(next[now]) 
            {
				if(res[win[now]]==0 && win[now] <= b)
                    res[win[now]]=c;
				win[now]=c;
                now=next[now];
            }
			win[now]=c;
            next[now]=b+1;
            if(now!=c)  res[now]=c;
            now++;
        }
        next[a]=b+1;
        //if(i == m) res[c]=0;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}

