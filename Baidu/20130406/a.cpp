/*************************************************************************
    > File Name: a.cpp
    > Author: withwind
    > Mail: withwind93@gmail.com 
    > Created Time: 2013/4/6 13:36:15
 ************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int i,j,k;
	int t,n,m;
	scanf("%d",&t);
	for(int casen = 1;casen<=t;casen++)
	{
		cout<<"Case #"<<casen<<": ";
		map<string,string> mmap;
		mmap.clear();
		int first = 1;
		cin>>n>>m;
		string a,b;
		while(m--)
		{
			cin>>a>>b;
			mmap[a] = b;
		}
	
		getchar();
		getline(cin,b);
		int kk = 0;
		for(k=0;k<b.size();k++)
		{
			
			while(b[k]!=' ')
			{
				if(b[k]=='\0')	break;
				k++;
			}
			a = b.substr(kk,k-kk);
		//	cout<<"a = "<<a<<endl;
			for(i=1;i<=n-1;i++)
			{
				if(!mmap[a].empty())	a = mmap[a];
			}
			if(!first)	cout<<' ';
			first = 0;
			cout<<a;
			kk = k+1;
		}
		
		cout<<endl;
	}
	return 0;
}
