#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
#define mod 1000000007
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int b,w;
		cin>>b>>w;
		int mi=min(b,w);
		int ma=max(b,w);
		if(3*mi+1<ma)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		if(w<=b)
		{
			for(int i=1;i<=w;i++)
			{
				cout<<"2 "<<2*i<<'\n';
				cout<<"2 "<<2*i+1<<'\n';
			}
			b-=w;
			if(b!=0)
			{
				cout<<"2 1\n";
				b--;
			}
			int i=1;
			while(b!=0)
			{
				cout<<"1 "<<2*i<<'\n';
				b--;
				if(b==0)
					break;
				cout<<"3 "<<2*i<<'\n';
				b--;
				i++;
			}
		}
		else
		{
			b=w^b;
			w=w^b;
			b=w^b;
			for(int i=1;i<=w;i++)
			{
				cout<<"3 "<<2*i<<'\n';
				cout<<"3 "<<2*i+1<<'\n';
			}
			b-=w;
			if(b!=0)
			{
				cout<<"3 1\n";
				b--;
			}
			int i=1;
			while(b!=0)
			{
				cout<<"2 "<<2*i<<'\n';
				b--;
				if(b==0)
					break;
				cout<<"4 "<<2*i<<'\n';
				b--;
				i++;
			}
		}
	}
	
	return 0;
}
