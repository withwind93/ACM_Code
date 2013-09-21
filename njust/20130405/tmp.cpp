#include<iostream>
#include <string.h>
using namespace std;

struct L
{
	int v;	L *next;
};

class HEAD
{
public:
	int id;	L *next;
	HEAD(){	id=0;	next=NULL;}
};


HEAD head[1000];  int dfn[1000],low[1000],t;     bool lock[1000],C[1000];


void find(int father,int v)
{
    int count=0;			/*统计v的孩子数*/
	dfn[v]=low[v]=++t;     /*将访问时间赋给dfn[v]和low[v]*/
	lock[v]=false;      /*标记v点已经访问过,不能再被访问*/
	for(L *p=head[v].next;p!=NULL;p=p->next)
	{
		if(lock[p->v])  /*如果v的直接后继节点没有访问过，则对其遍历*/
		{
			find(v,p->v);  /*对v的直接后继遍历*/
			count++;        /* 孩子数+1 */
			if(low[v]>low[p->v])  /*如果v的孩子能追溯到更早的祖先,则v也能追溯到*/
				low[v]=low[p->v];
		}
		else if(p->v!=father&&low[p->v]<low[v])  /*如果v的直接孩子节点已经被访问过*/
			low[v]=low[p->v];

		if(!father&&count>1)		/*如果当前节点是DFS遍历到的第一个节点,则判断其是否有多个孩子*/
			C[v]=true;
		else if(father&&dfn[v]<=low[p->v])   /*否则判断其后继能否追溯到v的祖先*/
			C[v]=true;
	}
}


int main()
{
	int n,i,a,b;
	while(cin>>n)
{
	while(cin>>a>>b)		/*建立邻接表,输入无向图边每条a b,以0 0结束*/
	{
		if(a == -1 && b == -1)	break;
		L *p=new L;
		p->next=head[b].next;
		head[b].next=p;
		p->v=a;
		p=new L;
		p->next=head[a].next;
		head[a].next=p;
		p->v=b;
		head[b].id++;
		head[a].id++;
	}
	memset(lock,true,sizeof(lock));
	memset(dfn,0,sizeof(int)*1000);
	memset(C,0,sizeof(C));  /*C数组用来标记那些点是割点,刚开始全部置为false*/
	t=0;   /*访问时间*/
	find(0,1);/*开始对1号点DFS,第一个遍历的前驱节点设为0*/
	int count = 0;
	for(i=1;i<=n;i++)		/*输入割点*/
		if(C[i])
			count++;
	cout<<count<<endl;
}
return 0;		
}

