#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
	int id,val;
}num[205];

int n,ind[205],h1[105],h2[105];
vector <int> f[105];
int main()
{
	scanf("%d",&n);
	for(int i=10;i<100;i++)
	  f[i].clear();

	for(int i=0;i<2*n;i++)
	  scanf("%d",&num[i].val),num[i].id=i,f[num[i].val].push_back(i);
	
	int cnt=1;
	for(int i=10;i<100;i++)
	  if(f[i].size()==1)
	  {
         ind[f[i][0]]=1+(cnt%2==0);
		 cnt++;
	  }
	  else if(f[i].size()>=2)
	  {
		 ind[f[i][0]]=1+(cnt%2==0);
		 cnt++;
		 ind[f[i][1]]=1+(cnt%2==0);
		 cnt++;
	  }
	cnt--;
	printf("%d\n",(cnt/2)*(cnt-cnt/2));
	cnt++;

	for(int i=10;i<100;i++)
	  if(f[i].size()>=3)
	  {
		 for(int j=2;j<f[i].size();j++)
		 {
			ind[f[i][j]]=1+(cnt%2==0);
			cnt++;
		 }
	  }
	
	for(int i=0;i<2*n;i++)
	  printf("%d ",ind[i]);
	return 0;
}


