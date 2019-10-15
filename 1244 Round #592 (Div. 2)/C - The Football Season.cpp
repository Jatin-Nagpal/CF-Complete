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
	int n,p,w,d;
	cin>>n>>p>>w>>d;
	f(i,0,100005)
	{
		if((p-i*d)%w==0)
		{
			int y=i,x=(p-i*d)/w;
			int z=(n-x-y);
			if(z>=0&&y>=0&&x>=0)
			{
				cout<<x<<" "<<y<<" "<<z<<'\n';
				return 0;
			}
			else
			{
				cout<<"-1\n";
				return 0;
			}
		}
	}
	cout<<"-1\n";
	
	return 0;
}
