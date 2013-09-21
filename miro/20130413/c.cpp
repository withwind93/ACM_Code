#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
double dp[128][1<<4][1<<4][1<<4][1<<4];
double mat[16][128][128];
int mm[5],tt[5],ss[5],rr[5];
int ones[5];
    int Nm,Nt,Ns,Nr;
double speed[1<<4][1<<4];

int one(int l)
{
    int ret = 0;
    for(int i=0;i<4;i++)
        if(l&(1<<i)) ret++;
    return ret;
}
bool testok(int l,int k)
{
    bool flag = 0;
    for(int i=1;i<=Nr;i++)
        if(rr[i]==k) flag = 1;
    if(!flag) return true;

    for(int i=0;i<4;i++)
        if(((1<<i) &l)&&rr[i+1]==k) return true;
    return false;

}
int main()
{
    int n,T,out = 1, M,start;
    scanf("%d",&T);
    bool ok[128];
    ones[0]=0;
    for(int i=1;i<5;i++)
        ones[i]=ones[i-1]|(1<<(i-1));

    for(int i=0;i<(1<<4);i++)
        for(int j=0;j<(1<<4);j++)
            {
                speed[i][j]=30+(one(i)+one(j))*5;
            }
    while(T--)
    {
        for(int i=0;i<128;i++)
            for(int j=0;j<16;j++)
                for(int k=0;k<16;k++)
                    for(int jj=0;jj<16;jj++)
                        for(int kk=0;kk<16;kk++)
                            dp[i][j][k][jj][kk] = 1000000000;
        for(int l=0;l<16;l++)
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                if(i==j) mat[l][i][j] = 0;
                else mat[l][i][j] = 1000000000;
        memset(ok,0,sizeof(ok));
        for(int l=0;l<16;l++)
            for(int i=0;i<=100;i++)
                mat[l][i][i]=0;
        scanf("%d %d",&n,&M);
        while(M--)
        {
            int a,b,len;
            scanf("%d %d %d",&a,&b,&len);
            for(int l=0;l<16;l++)
            mat[l][a][b] = mat[l][b][a] = len;
        }

        scanf("%d",&Nm);
        for(int i=1;i<=Nm;i++)
            scanf("%d",&mm[i]),ok[mm[i]]=true;

        scanf("%d",&Nt);
        for(int i=1;i<=Nt;i++)
            scanf("%d",&tt[i]),ok[tt[i]]=true;

        scanf("%d",&Ns);
        for(int i=1;i<=Ns;i++)
            scanf("%d",&ss[i]),ok[ss[i]]=true;

        scanf("%d",&Nr);
        for(int i=1;i<=Nr;i++)
            scanf("%d",&rr[i]),ok[rr[i]]=true;

    for(int l=0;l<(1<<Nr);l++)
        for(int k=1;k<=n;k++)
            if(testok(l,k))
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(mat[l][i][k]+mat[l][k][j]<mat[l][i][j])
                        mat[l][i][j]=mat[l][i][k]+mat[l][k][j];


        scanf("%d",&start);
        ok[start]=1;

        dp[start][0][0][0][0] = 0;

        for(int m=0;m<(1<<Nm);m++)
            if(m!=ones[Nm])
            for(int t=0;t<(1<<Nt);t++)
                for(int s=0;s<(1<<Ns);s++)
                    for(int r=0;r<(1<<Nr);r++)
                    {
                        for(int i=1;i<=n;i++)
                        if(ok[i])
                        {
                            for(int j=1;j<=Nm;j++)
                            {
                                if(!((m|1<<(j-1)) == ones[Nm] &&(t != ones[Nt])))
                                dp[mm[j]][m|(1<<(j-1))][t][s][r]=min(dp[i][m][t][s][r]+mat[r][i][mm[j]]/speed[s][r],dp[mm[j]][m|(1<<(j-1))][t][s][r]);
                            }
                            for(int j=1;j<=Nt;j++)
                            {
                                dp[tt[j]][m][t|(1<<(j-1))][s][r]=min(dp[i][m][t][s][r]+mat[r][i][tt[j]]/speed[s][r],dp[tt[j]][m][t|(1<<(j-1))][s][r]);
                            }
                            for(int j=1;j<=Ns;j++)
                            {
                                dp[ss[j]][m][t][s|(1<<(j-1))][r]=min(dp[i][m][t][s][r]+mat[r][i][ss[j]]/speed[s][r],dp[ss[j]][m][t][s|(1<<(j-1))][r]);
                            }
                            for(int j=1;j<=Nr;j++)
                            {
                                //if((r|(1<<(j-1))) !=r)
                                //dp[rr[j]][m][t][s][r|(1<<(j-1))] = dp[i][m][t][s][r]+mat[r|(1<<(j-1))][i][rr[j]]/speed[s][r]+3;
                               // else
                                dp[rr[j]][m][t][s][r|(1<<(j-1))]=min(dp[i][m][t][s][r]+mat[r|(1<<(j-1))][i][rr[j]]/speed[s][r]+3,dp[rr[j]][m][t][s][r|(1<<(j-1))]);
                            }
                        }

                    }
        double ans = 1000000000;
        for(int t=0;t<(1<<Nt);t++)
            for(int s=0;s<(1<<Ns);s++)
                for(int r=0;r<(1<<Nr);r++)
                    for(int j=1;j<=Nm;j++)
                        {
                            if(dp[mm[j]][ones[Nm]][t][s][r]<ans)
                                ans = dp[mm[j]][ones[Nm]][t][s][r];
                        }
        printf("Case #%d: %.5f\n",out++,ans+1e-7);
    }
    return 0;
}

