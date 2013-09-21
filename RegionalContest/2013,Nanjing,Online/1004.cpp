#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
bool edge[110][110];
bool vis[110];
vector<int> lleft,rright;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        memset(edge,false,sizeof(edge));
        memset(vis,false,sizeof(vis));
        for(int i = 1;i <= n;i++)
        {
            int t;
            while(scanf("%d",&t) != EOF)
            {
                if(t == 0)  break;
                edge[i][t] = true;
            }
        }
        int flag1 = -1,flag2 = -1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
				if(i == j)	continue;
                if(edge[i][j] == false)
                {
                    flag1 = i;
                    flag2 = j;
                }
                if(edge[i][j] == true && edge[j][i] == true)
                    continue;
                edge[i][j] = edge[j][i] = false;
            }
        }
        lleft.clear();
        rright.clear();
        if(flag1 == -1 && flag2 == -1)  {printf("YES\n");continue;}
        vis[flag1] = true;vis[flag2] = true;
        int cnt = 2;
        lleft.push_back(flag1);rright.push_back(flag2);
        int noflag = 0,oneflag = 1;
		int cnt1 = 0,cnt2 = 0;
        while(1)
        {
            if(cnt == n)    break;
            if(noflag)  break;
			if(oneflag == 0)	
			{
				for(int i = 1;i <= n;i++)
					if(vis[i] == false)
					{
						vis[i] = true;
                    	cnt++;
                   		rright.push_back(i);
						break;					
					}
			}
			oneflag = 0;
            for(int i = 1;i <= n;i++)
            {
                int lleftflag = -1,rrightflag = -1;
                int tmp;
                if(vis[i])  continue;
                for(int k = 0;k < lleft.size();k++)
                {
                    tmp = lleft[k];
                    if(edge[tmp][i] == false){
                        lleftflag = 1;
                        break;
                    }
                }
                for(int k = 0;k < rright.size();k++)
                {
                    tmp = rright[k];
                    if(edge[tmp][i] == false){
                        rrightflag = 1;
                        break;
                    }
                }
                if(lleftflag == -1 && rrightflag == -1)   continue;//liang bian 
				
				oneflag = 1;
                if(lleftflag == -1 && rrightflag == 1)
                {//rright
                    vis[i] = true;
                    cnt++;
                    lleft.push_back(i);
                }
                else if(rrightflag == -1 && lleftflag == 1)
                {
                    vis[i] = true;
                    cnt++;
                    rright.push_back(i);
                }else
                {
                    noflag = 1;
                    break;
                }
            } 
        }
        
        if(noflag)  printf("NO\n");
        else        printf("YES\n");
    }
    return 0;
}

