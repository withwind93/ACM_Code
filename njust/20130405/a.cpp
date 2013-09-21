#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define N 110
int out[N];
int res[N];
int stack[N],top=0;
bool instack[N];
int dfn[N];
int low[N];
int number = 0;/*ComponentNumberǿ��ͨ����*/
int index = 0;
vector <int> edge[N];
vector <int> component[N];/*ǿ��ͨ�Ľ��*/
int incomponent[N];
int componentDegree[N];/*ǿ��ͨ�����Ķ�*/
void tarjan(int now)
{
//	printf("now = %d\n",now);
	int i,j,k;
	int next;
	dfn[now] = low[now] = ++index;/*ʱ���*/
	instack[now] = true;
	stack[++top] = now;
	for(int e = 0;e<edge[now].size();e++)
	{
		next = edge[now][e];
		if(dfn[next] == 0)/*û�б�����*/
		{
			tarjan(next);
			low[now] = min(low[now],low[next]);/*nextΪnow��һ����Ů*/
		}
		else if(instack[next])
		  low[now] = min(low[now],dfn[next]);/*���ڻرߣ��õ���С��ʱ���*/
	}
	if(dfn[now] == low[now])
	{
		number++;
		component[number].clear();
		do
		{
			next = stack[top--];
			instack[next] = false;
			component[number].push_back(next);
			incomponent[next] = number;
		//	printf("in [ %d ] = %d\n ",next,number);
		}while(next!=now);
	}
/*	if(low[now] >= dfn[now])
	{
		printf("\n");
		do
		{
			next = stack[top--];
			printf("%d  ",next);
		}while(next != now);
	}*/
}
void solve(int n)/*NΪͼ�е�ĸ���*/
{
	memset(stack,0,sizeof(stack));
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	number = 0;
	top = 0;
	index = 0;
	for(int i=1;i<=n;i++)
	{
		if(dfn[i] == 0)
		  tarjan(i);
	}
}


int main()
{
	int i,j,k;
	int n,m;
	int x,y;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		for(i=1;i<=n;i++)
		{
			edge[i].clear();
			out[i]=0;
			res[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			int flag=0;
			for(j=0;j<edge[x].size();j++)
			  if(edge[x][j]==y)
			  {
				flag=1;
				break;
			  }
			if(flag)	continue;
			edge[x].push_back(y);
		}
		solve(n);
		int p;
		scanf("%d",&p);
		for(i=1;i<=p;i++)
		{
			scanf("%d %d",&x,&y);
			if(incomponent[x] ==incomponent[y])
			  printf("YES\n");
			else
			  printf("NO\n");
		}
		printf("\n");
	}
	return 0;
}





