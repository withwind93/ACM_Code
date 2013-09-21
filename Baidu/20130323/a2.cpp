#include <cstdio>  

int main() {  
	int n, k, t[10000];  
	while (scanf("%d%d", &n, &k) != EOF && !(n == 0 && k == 0)) {  
		int tsum = 0, tmax = 0;  
		for (int i = 0; i < n; ++i) {  
			scanf("%d", &t[i]);  
			tsum += t[i];  
			tmax = tmax > t[i] ? tmax : t[i];  
		}  
		int high = tsum, low = tmax, ans = -1;  
		while (low <= high) {  
			int mid = (low + high) >> 1;  
			int cur = 0, cnt = 1;  
			int i = 0;  
			while (i < n) {  
				cur += t[i];
				printf("cur = %d  ",cur);
				if (cur > mid) {  
					++cnt;  
					cur = t[i];  
				}  
				if (cnt > k) break;  
				++i;  
			} 
			printf("\n");
			if (i < n)  
			  low = mid + 1;  
			else // i == n  
			  ans = mid, high = mid - 1;  
					printf("low = %d high = %d\n",low,high);
		}  
		printf("%d\n", ans);  
	}  
	return 0;  
} 

