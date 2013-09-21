#include<iostream>
using namespace std;
int main()
{
    int t,T,a,b,n,s;
	cin>>T;
	for (t=1;t<=T;++t)
	{
		cin>>n>>a>>b;
		cout<<"Case #"<<t<<": ";
		if (n/2<a)
			if (n%2==1) 
			{
				s=a/(n/2+1);
				if (b>=(s+1)*(n/2+1)) cout << -1 << endl;
				else  cout << 1 << endl;
			}
			else 
			{
				s=a/(n/2+1);
				if (b<(s+1)*(n/2)) 
				{
					cout << 1 << endl;
					continue;
				}
				s=a/(n/2);
				if (b>=(s+1)*(n/2+1)) 
				{
					cout << -1 << endl;
					continue;
				}
				cout << 0 << endl;
				continue;
			}

		if (n/2==a) 
		{
			if(n%2==0) 
			{
				if(b<a) cout << 1 << endl;
				else if (b>=2*(n/2+1)) cout << -1 << endl;
				else cout << 0 << endl;
			}
			else if(n%2==1) 
			{
				if(b>a) cout<<-1<< endl;
				else if(b==a) cout << 0 << endl;
				else cout << 1 << endl;
			}
		}
		if (n/2>a) 
		{
			s=1;
			if(b>a) cout << -1 << endl;
			else if (b==a) cout<<0<<endl;
		    else cout<<1<< endl;
		}
	}
	return 0;
}

