#include<iostream>
#include<string>
using namespace std;
int num[10][60000],ans[60000];
int main()
{
    int T,n,i,k,j,s,l1,l2,anss,t;
	string s1,s2;
	cin>>T;
	t=1;
	while (T>=t)
	{
		++t;
		cin>>s1;cin>>s2;
		l1=s1.length(); l2=s2.length();
		for (i=0;i<10;++i) num[i][0]=0;
		for (i=0;i<l1;++i)
		{
			k=s1[i]-'0';
			++num[k][0];
			num[k][num[k][0]]=i;
			ans[i]=0;
		}
		for (i=0;i<l2;++i)
		{
			k=s2[i]-'0';
			for (j=1;j<=num[k][0];++j)
			{
				if (num[k][j]-i>=0)
				ans[num[k][j]-i]++;
			}
		}
		anss=0;
		for (i=0;i<l1-l2+1;++i)
			if (ans[i]>anss) anss=ans[i];
		anss=l2-anss;
		cout<<"Case #"<<t-1<<": "<<anss<<endl;
	}
	return 0;
}

