#include <cstdio>
#include <memory.h>
#define Mod 1000000007

struct matrix
{
	unsigned long long a[3][3];
}p, e;
int n, m, k;

void mmul(matrix a, matrix b, matrix& c)
{
	memset(c.a, 0, sizeof(c.a));
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			for(int k=0; k<3; ++k)
			{
				c.a[i][j] += a.a[i][k]*b.a[k][j];
				if(c.a[i][j] >= Mod)
					c.a[i][j] %= Mod;
			}
}

void mexp(int n)
{
	memset(e.a, 0, sizeof(e.a));
	e.a[0][0] = e.a[1][1] = e.a[2][2] = 1;
	while(n)
	{
		if(n & 1)
			mmul(e, p, e);
		n >>= 1;
		mmul(p, p, p);
	}
}

int main()
{
	while(scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		memset(p.a, 0, sizeof(p.a));
		p.a[0][0] = p.a[0][1] = p.a[0][2] = m-k;
		p.a[1][0] = k, p.a[1][1] = k-1;
		p.a[2][2] = m-1;
		mexp(n-1);
		unsigned long long sum = 0;
		sum += e.a[0][2];
		sum += e.a[1][2];
		sum += (e.a[2][2]*m)%Mod;
		sum %= Mod;
		printf("%llu\n", sum);
	}
	return 0;
}

