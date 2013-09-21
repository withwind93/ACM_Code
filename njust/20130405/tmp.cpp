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
    int count=0;			/*ͳ��v�ĺ�����*/
	dfn[v]=low[v]=++t;     /*������ʱ�丳��dfn[v]��low[v]*/
	lock[v]=false;      /*���v���Ѿ����ʹ�,�����ٱ�����*/
	for(L *p=head[v].next;p!=NULL;p=p->next)
	{
		if(lock[p->v])  /*���v��ֱ�Ӻ�̽ڵ�û�з��ʹ�����������*/
		{
			find(v,p->v);  /*��v��ֱ�Ӻ�̱���*/
			count++;        /* ������+1 */
			if(low[v]>low[p->v])  /*���v�ĺ�����׷�ݵ����������,��vҲ��׷�ݵ�*/
				low[v]=low[p->v];
		}
		else if(p->v!=father&&low[p->v]<low[v])  /*���v��ֱ�Ӻ��ӽڵ��Ѿ������ʹ�*/
			low[v]=low[p->v];

		if(!father&&count>1)		/*�����ǰ�ڵ���DFS�������ĵ�һ���ڵ�,���ж����Ƿ��ж������*/
			C[v]=true;
		else if(father&&dfn[v]<=low[p->v])   /*�����ж������ܷ�׷�ݵ�v������*/
			C[v]=true;
	}
}


int main()
{
	int n,i,a,b;
	while(cin>>n)
{
	while(cin>>a>>b)		/*�����ڽӱ�,��������ͼ��ÿ��a b,��0 0����*/
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
	memset(C,0,sizeof(C));  /*C�������������Щ���Ǹ��,�տ�ʼȫ����Ϊfalse*/
	t=0;   /*����ʱ��*/
	find(0,1);/*��ʼ��1�ŵ�DFS,��һ��������ǰ���ڵ���Ϊ0*/
	int count = 0;
	for(i=1;i<=n;i++)		/*������*/
		if(C[i])
			count++;
	cout<<count<<endl;
}
return 0;		
}

