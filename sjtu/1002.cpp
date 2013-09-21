/*************************************************************************
    > File Name: 1002.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/3/10 20:06:53
 ************************************************************************/


/*
void change1(int x,int y)
{//x<y
	for(int i=x;i<=y;i++)
	  {
		 a[x][i] = 1-a[x][i];
	  }
	for(int i=x;i<=y;i++)
	  {
		 a[i][y] = 1-a[i][y];
	  }
	a[x][y] = 1 - a[x][y];
	c++;
}
void change2(int x,int y)
{//x>=y
	for(int i=y;i<=x;i++)
	  {
		 a[x][i] = 1-a[x][i];
	  }
	for(int i=y;i<=x;i++)
	  {
		 a[i][y] = 1-a[i][y];
	  }
	a[x][y] = 1 - a[x][y];
	c++;
}
void print()
{
	int i,j;
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				printf("%d  ",a[i][j]);
			}
			printf("\n");
		}
}*/

int main()
{
	int i,j,k;
	int tmpx=1,tmpy=n-i+1;
	char s[1500];
	int row[1025][2],lie[1025][2];
	while(scanf("%d",&n)!=EOF)
	{
		c = 0;
		for(i = 1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(j = 1;j<=n;j++)
			{
				a[i][j] = (s[j]-'0');
			}
			row[i][0] = lie[i][0] = 0;
			row[i][1] = lie[i][1] = 0;
		}
		for(i = 1;i<n;i++)
		{
			tmpx=1,tmpy=n-i+1;
			for(j = 1;j<=i;j++)
			{
				if((a[tmpx][tmpy]+row[tmpx][0]+lie[tmpy][0])%2 == 0)
				{
					row[tmpx][0]=1-row[tmpx][0];
					lie[tmpy][0]=1-lie[tmpy][0];
					c++;
				}
				tmpx++;
				tmpy++;
			}
		}
		for(i = 1;i<n;i++)
		{
			tmpx=n-i+1,tmpy=1;
			for(j = 1;j<=i;j++)
			{
				if((a[tmpx][tmpy]+row[tmpx][1]+lie[tmpy][1])%2 == 0)
				{
					row[tmpx][1]=1-row[tmpx][1];
					lie[tmpy][1]=1-lie[tmpy][1];
					c++;
				}
				tmpx++;
				tmpy++;
			}
		}
		for(i = 1;i<=n;i++)
		{
			if((a[i][i]+row[i][0]+row[i][1]+lie[i][0]+lie[i][1])%2 == 0)
				c++;
		}
		printf("%d\n",c);

	}
	return 0;
}
