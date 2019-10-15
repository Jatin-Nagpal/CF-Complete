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
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=((a+c-1)/c),y=((b+d-1)/d);
		if(x+y>k)
			cout<<"-1\n";
		else
			cout<<x<<" "<<y<<"\n";
	}
	
	return 0;
}