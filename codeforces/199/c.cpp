#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
struct node{
    int t, left, right;
}watch[100005];

int main()
{
    int n, m, s, f;
    int t, left, right;
    scanf("%d%d%d%d", &n, &m, &s, &f);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &watch[i].t, &watch[i].left, &watch[i].right);
    watch[m+1].t = -1;
    if (s < f){
        int cur = s,step = 1,cp = 1;
        bool flag = true;
        while (flag){
            if (step != watch[cp].t){
                cur++;
                printf("R");
                if (cur == f) flag = false;
            }else{
                if (cur >= watch[cp].left-1 && cur <= watch[cp].right){
                    printf("X");
                }else{
                    cur++;
                    printf("R");
                    if (cur == f) flag = false;
                }
                cp++;
            }
            step++;
        }
        printf("\n");
    }
	else
	{
        int cur = s,step = 1,cp = 1;
        bool flag = true;
        while (flag){
            if (step != watch[cp].t){
                cur--;
                printf("L");
                if (cur == f) flag = false;
            }else{
                if (cur >= watch[cp].left && cur <= watch[cp].right+1){
                    printf("X");
                }else{
                    cur--;
                    printf("L");
                    if (cur == f) flag = false;
                }
                cp++;
            }
            step++;
        }
        printf("\n");
    }
    return 0;
}

