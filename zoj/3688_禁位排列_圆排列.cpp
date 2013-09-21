//与上题一样，考虑用容斥定理解决
//考虑这样的“错误”顺序  1号取1，2号取1，2号取2，3号取2，3号取3，4号取3……n号取n-1,n号取n,1号取n把它们看成点，连成一个圆
//那么 出现k个错误的种数就相当于在这2n个点中取k个不两两不相邻的点
//首先随便选取一个点，然后两旁不能选，这时候还剩2n-3个中选k-1个，此时圆已断开，问题转换成一条链中选不相邻的点
//n个点序列选取k个两两不相邻的点的种数n-k+1Ck(在n-k+1个点中选取k个，然后除了最后一个，每一个被选的点“向右吐出一个点”得到选好了的长为n的序列，这两个序列一一映射）
#include<cstdio>
#define LL long long
const LL MOD=1000000007;
const int Maxn=100005;
LL jc[Maxn],r[Maxn],N,x,y,ans;
inline void exgcd(LL a,LL b,LL&x,LL&y);

int main()
{
	jc[0]=1;
	for(int i=1;i<Maxn;i++)
	  jc[i]=jc[i-1]*i%MOD;

	while(scanf("%lld",&N)!=EOF)
	{
		LL n=2*N;
		LL limit=N-1;
		r[0]=1*n;
		for(int i=1;i<=limit;i++)
		{
			r[i]=((n-2*i)*(n-2*i-1)*i%MOD)*r[i-1]%MOD;
			exgcd((n-i-1)*i*(i+1)%MOD,MOD,x,y);
			if(x<0)
			  x+=MOD;
			r[i]=r[i]*x%MOD;
		}
		ans=jc[N];
		int k=-1;
		limit++;
		for(int i=1;i<=limit;i++)
		{
			ans=(ans+k*r[i-1]*jc[N-i])%MOD;
			k=k*-1;
		}
		if(N==1)
		  printf("0\n");
		else
		{
			ans=(ans+MOD)%MOD;
		    printf("%lld\n",ans);
		}
	}
	return 0;
}

void exgcd(LL a,LL b,LL&x,LL&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
