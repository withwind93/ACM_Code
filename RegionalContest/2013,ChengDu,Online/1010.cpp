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
int a[100010];
int hash[32];
void add(int x)
{
    for(int i =0;i <= 31;i++)
    {
        if(x&(1<<i))    hash[i]++;
    }
}
void jian(int x)
{
    for(int i = 0;i <= 31;i++)
    {
        if(x&(1<<i))    hash[i]--;
    }
}
int get()
{
    int ans = 0;
    for(int i = 0;i <= 31;i++)
    {
        if(hash[i])    ans = ans|(1<<i);
    }
    return ans;
}
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    int cas = 1;
    while(T--)
    {
        memset(hash,0,sizeof(hash));
        scanf("%d %d",&n,&m);
        llg ans = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i] < m)    ans++;
        }
        a[n+1] = m+1;
        int left = 1,right = 1;
        while(left <= n+1 && right <= n+1)
        {
            int num = 0;
            if(left == right)
            {
                if(a[left] < m)
                {
                    add(a[left]);
                    right++;    
                }
                else
                {
                    left++;
                    right++;
                }
                continue;
            }
            int now = get();
            if((now | a[right]) < m)
            {
                int dis = right - left;
                ans += dis;
                add(a[right]);
                right++;
            }else{
                jian(a[left]);
                left++;
            }
        }
        printf("Case #%d: %I64d\n",cas++,ans);
    }
    return 0;
}