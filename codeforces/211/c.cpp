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
    string str;
    cin >> str;
    string s = "";
    int len = str.length();
    for (int i = 0; i < len; ){
        if (i < len - 2 && str[i]  == str[i+1] && str[i]  == str[i+2]){
            i++;
        }else{
            s += str[i] ;
            i++;
        }
    }

    str = "";
    len = s.length();
    for (int i = 0; i < len; ){
        if (i < len - 3 && s[i]  == s[i+1] && s[i+2] == s[i+3]){
            str += s[i] ;
            str += s[i+1];
            str += s[i+2];
            i += 4;
        }else{
            str += s[i] ;
            i++;
        }
    }
    cout << str << endl;
    return 0;
} 

