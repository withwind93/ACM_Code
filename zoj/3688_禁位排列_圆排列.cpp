//������һ�����������ݳⶨ����
//���������ġ�����˳��  1��ȡ1��2��ȡ1��2��ȡ2��3��ȡ2��3��ȡ3��4��ȡ3����n��ȡn-1,n��ȡn,1��ȡn�����ǿ��ɵ㣬����һ��Բ
//��ô ����k��������������൱������2n������ȡk�������������ڵĵ�
//�������ѡȡһ���㣬Ȼ�����Բ���ѡ����ʱ��ʣ2n-3����ѡk-1������ʱԲ�ѶϿ�������ת����һ������ѡ�����ڵĵ�
//n��������ѡȡk�����������ڵĵ������n-k+1Ck(��n-k+1������ѡȡk����Ȼ��������һ����ÿһ����ѡ�ĵ㡰�����³�һ���㡱�õ�ѡ���˵ĳ�Ϊn�����У�����������һһӳ�䣩
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
