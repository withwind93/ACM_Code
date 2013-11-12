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

int main()
{
    int n;
    cin >> n;
    string exp[10];
    exp[0] = "O-|-OOOO";
    exp[1] = "O-|O-OOO";
    exp[2] = "O-|OO-OO";
    exp[3] = "O-|OOO-O";
    exp[4] = "O-|OOOO-";
    exp[5] = "-O|-OOOO";
    exp[6] = "-O|O-OOO";
    exp[7] = "-O|OO-OO";
    exp[8] = "-O|OOO-O";
    exp[9] = "-O|OOOO-";
    if (n == 0){
        cout << exp[0] << endl;
        return 0;
    }
    while (n > 0){
        int tmp = n % 10;
        n /= 10;
        cout << exp[tmp]  << endl;
    }
    return 0;
} 

