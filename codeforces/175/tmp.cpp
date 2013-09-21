#include <stdio.h>
#include <string.h>
#define ll long long
int c[30];
ll ans;
bool is[30];
const ll mod=1000000007;
void swap(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
bool ok(int m) {
    memset(is, false, sizeof(is));
    for (int i = 1; i <= m; ++i) {
        if (is[c[i]]) return false;
        is[c[i]] = true;
    }
    return true;
}
ll jie(ll n) {
    ll res = 1;
    while (n) {
        res *= n;
        --n;
    }
    return res;
}
void perm(int a[], int k, int m, int pk, int pm) {
    if (k==m) {
        for (int i = pk; i <= pm; ++i)
            c[i] = (a[i]+i-2) % m + 1;
//        for (int i = pk; i <= pm; ++i) printf("%d ", c[i]);
//        printf("\n");
        if (ok(m)) {
            ++ans;
            if (ans == mod)   ans=0;
        }
    } else {
        for (int i = k; i <= m; ++i) {
            swap(a, k, i);
            perm(a, k+1, m, pk, pm);
            swap(a, k, i);
        }
    }
}

int main()
{

int a[] = {1, 3, 15, 133, 2025, 37851, 1030367, 36362925};
	
    int a[30];
    int nn;
    for (nn = 13; nn <= 16; nn+=2) {
        ans = 0;
        for (int i = 0; i < 20; ++i) a[i] = i;
        perm(a, 1, nn, 1, nn);
        ans = jie(nn) * ans;
        printf("%d == %I64d\n", nn, ans);
    }
    return 0;
}

