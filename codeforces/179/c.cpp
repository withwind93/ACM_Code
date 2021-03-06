#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <iostream>
using namespace std;
#define llg long long
struct line
{
	llg left,right,m;//左端点，右端点
	long long add;
	long long sum;
}node[400010];
llg a[100100];
llg aa[100100];
llg sum[100100];
llg x[100100],y[100100],z[100100];
//long long build(int l,int r,int root)//第root个结点
llg build(llg l,llg r,llg root)
{
	node[root].left=l;
	node[root].right=r;
	node[root].m=(l+r)/2;
	if(l==r)
	{
		node[root].sum=a[l];//递归出口.另外。数字（a数组）不是固定的，但是结点位置是固定的
		return node[root].sum;
	}
	long long leftsum=build(l,(l+r)/2,root*2);
	long long rightsum=build((l+r)/2+1,r,root*2+1);
	node[root].sum=leftsum+rightsum;
	return node[root].sum;
}

//int insert(int l,int r,long long add,int root)
int insert(llg l,llg r,llg add,llg root)
{
	if(l<=node[root].left && r>=node[root].right)//递归出口。所加线段大于当前段
	{
		node[root].add+=add;
		node[root].sum+=add*(node[root].right-node[root].left+1);
		return 0;
	}
	if(node[root].add)//向下更新
	{
		node[2*root].sum+=node[root].add*(node[root*2].right-node[root*2].left+1);
		node[2*root].add+=node[root].add;
		node[2*root+1].sum+=node[root].add*(node[root*2+1].right-node[root*2+1].left+1);
		node[2*root+1].add+=node[root].add;
		node[root].add=0;
	}
	if(l<=node[root].m)//为了满足所加线段大于当前段。所以要递归使得当前段减小
	  insert(l,r,add,root*2);
	if(r>node[root].m)//加一问题使得只能是>
	  insert(l,r,add,root*2+1);
	node[root].sum=node[root*2].sum+node[root*2+1].sum;//回溯
	return 0;
}

//long long search(int l,int r,int root)
llg search(llg l,llg r,llg root)
{
	if(l<=node[root].left && r>=node[root].right)//递归出口.所求段大于当前段。（并不是两段只能刚刚好才...）
	  return node[root].sum;
//防止没有往下更新过。所以。。。
	if(node[root].add)//向下更新
	{
		node[2*root].sum+=node[root].add*(node[root*2].right-node[root*2].left+1);
		node[2*root].add+=node[root].add;
		node[2*root+1].sum+=node[root].add*(node[root*2+1].right-node[root*2+1].left+1);
		node[2*root+1].add+=node[root].add;
		node[root].add=0;
	}

	long long leftsum=0;
	long long rightsum=0;
	if(l<=node[root].m)
	  leftsum=search(l,r,2*root);
	if(r>node[root].m)
	  rightsum=search(l,r,2*root+1);
	return leftsum+rightsum;
}



int main()
{
	int n,m;
//	int x,y,z;
	int first = 1;
	int temp;
	char ch;
	int i,j,k;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		a[i] = 0;
//		scanf("%d",&aa[i]);
		cin>>aa[i];
	}
	build(1,m,1);

	for(i=1;i<=m;i++)
	{
//		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		cin>>x[i]>>y[i]>>z[i];
	}

	for(i=1;i<=k;i++)
	{
		//int xx,yy,zz;
		llg xx,yy,zz;
//		scanf("%d%d",&xx,&yy);
		cin>>xx>>yy;
		zz = 1;
			if(xx>yy)
				{temp=xx;xx=yy;yy=temp;}
			insert(xx,yy,zz,1);
	}
	for(i=1;i<=m;i++)
	{
		sum[i] = search(i,i,1);
//		a[i] = aa[i];
	}
	for(i=1;i<=n;i++)
	{
		a[i] = aa[i]; 
	}
	memset(node,0,sizeof(node));
	build(1,n,1);
	for(i=1;i<=m;i++)
	{
		if(z[i]==0 || sum[i]==0)	continue;
		insert(x[i],y[i],z[i]*sum[i],1);
	}
	for(i=1;i<=n;i++)
	{
		if(first == 0)	cout<<" ";
		first = 0;
		cout<<search(i,i,1);
	}
	/*		}
		else
		{
			scanf("%d %d",&x,&y);
			if(x>y)
				{temp=x;x=y;y=temp;}
		}*/
	return 0;
}


