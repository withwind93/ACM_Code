#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
int dp[20][200000];//第一维是位数,第二维是状态数
int bit[20];
int dfs(int pos,int num,bool flag)
{//dfs(len-1,num,true)
    if(pos == -1)    return num >= 0;//最终符合的条件
    if(num < 0)        return 0;//无需考虑的情况
    if(!flag && dp[pos][num] != -1)
      return dp[pos][num];
    int ans = 0, end = flag ? bit[pos] : 9;
    for(int i = 0;i <= end;i++)
        ans += dfs(pos-1,num - i*(1<<pos),flag && i==end);
    if(!flag)    dp[pos][num] = ans;
    return ans;
}
int calc(int a,int b)
{//[0,b],fit in 'a'
    static int calc_first = 1;
    if(calc_first){
        memset(dp,-1,sizeof(dp));
        calc_first = 0;
    }//important,状态相同,成段统计,无需多次初始化
    int len = 0;
    while(b){
        bit[len++] = b % 10;
        b /= 10;
    }
    return dfs(len - 1,a,true);
}
int f(int x)
{
    int ans = 0,len = 0;
    while(x)
    {
        ans += (x%10)*(1<<len);
        x /= 10;
        len++;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int fx = f(x);
        printf("Case #%d: %d\n",cas++,calc(fx,y));
    }
    return 0;
}