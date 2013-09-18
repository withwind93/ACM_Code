#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[30];
char tmp[7] = "babbaa";
char tmp2[4] = "abc";
int main()
{
    int n,m,T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",k);
        if(m>=3)
        {
            for(int i = 0;i < n;i++)
                printf("%c",tmp2[i%3]);

            printf("\n");
        }
        else if(m==1)
        {
            for(int i=1;i<=n;i++)
                printf("%c",'a');

            printf("\n");
        }
        else
        {
            if(n == 1)    printf("a\n");
            if(n == 2)    printf("ab\n");
            if(n == 3)    printf("aab\n");
            if(n == 4)    printf("aabb\n");
            if(n == 5)    printf("aaaba\n");
            if(n == 6)    printf("aaabab\n");
            if(n == 7)    printf("aaababb\n");
            if(n == 8)    printf("aaababbb\n");
            if(n >= 9)
            {
                printf("aaaa");
                n = n - 4;
                if(n % 6 == 1)
                {
                    for(int i = 0;i <n-1;i++)
                    {
                        printf("%c",tmp[i%6]);
                    }
                    printf("a");
                }
                else if(n%6 == 2)
                {
                    for(int i = 0;i <n-2;i++)
                    {
                        printf("%c",tmp[i%6]);
                    }
                    printf("aa");
                }
                else
                {
                    for(int i = 0;i <n;i++)
                    {
                        printf("%c",tmp[i%6]);
                    }
                }

                printf("\n");
            }
        }

    }
    return 0;
}