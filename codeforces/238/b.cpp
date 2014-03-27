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
int n;
int a[1000010];
int b[1000010];
char str[3010];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i = 1;i <= n;i++)
    {
        if(str[i] == '.')   a[i] = 0;
        if(str[i] == 'L')   a[i] = -1;
        if(str[i] == 'R')   a[i] = 1;
    }
    int ans = 0;
    int last = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)
        {
            int l = i;
            while(a[l] == 0 && l >= 1)
                    l--;
            while(a[l] == 1 && l >= 1)
            {
                int tmp = l;
                l--;
                while(a[l] == 0 && l >= 1)
                    l--;
                if(a[l] == -1 || l == 0)    
                {
                    l = tmp;
                    break;
                }
            }
            
            int r = i;
            while(a[r] == 0 && r <= n)
                    r++;
            while(a[r] == -1 && r <= n)
            {
                int tmp = r;
                r++;
                while(a[r] == 0 && r <= n)
                    r++;
                if(a[r] == 1 || r == n+1)
                {
                    r = tmp;
                    break;
                }
            }
            //printf("%d %d %d\n",i,l,r);
            if(a[l] == -1 && a[r] == 1) ans++;
            if(a[l] == -1 && a[r] == 0) ans++;
            if(a[l] == 0 && a[r] == 1)  ans++;
            if(a[l] == 0 && a[r] == 0)  ans++;
            if(a[l] == 1 && a[r] == -1) 
            {
                if(i-l == r-i)  ans++;
            }
        }
        else
          last = a[i];
    }
    printf("%d\n",ans);
    return 0;
}

