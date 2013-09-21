#include <cstdio>
#include <cstring>
int N,ANS;
int num[11];
char stack[11];
void ps()
{
	for (int i=1;i<=N;i++)
		printf("%d%c",num[i],stack[i]);
	printf("\n");
}

int DFS(int sum,int head,int value,int deep)
{
	if (deep==N)
	{
		if (value <0)return 0;
		if (sum+head*10+num[deep]==value)
		{
			ANS++;
			//ps();
		}
		return 1;
	}
	//+
	stack[deep]='+';
	DFS(sum+head*10+num[deep],0,value,deep+1);
	//~
	stack[deep]='~';
	DFS(sum,head*10+num[deep],value,deep+1);
	//=
	if (value<0 || value==sum+head*10+num[deep])
	{
		stack[deep]='=';
		DFS(0,0,sum+head*10+num[deep],deep+1);
	}
}
int main()
{
	while (scanf("%d",&N),N)
	{
		for (int i=1;i<=N;i++)
			scanf("%d",&num[i]);
		ANS=0;
		DFS(0,0,-1,1);
		printf("%d\n",ANS);
	}
}
