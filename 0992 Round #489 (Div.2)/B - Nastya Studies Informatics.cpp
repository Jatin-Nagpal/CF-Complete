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
	int l,r,x,y;
	cin>>l>>r>>x>>y;
	if(y%x!=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	l=(l+x-1)/x;
	r=r/x;
	y=y/x;
	int ans=0;
	for(int i=1;i*i<=y;i++)
	{
		if(i*i==y)
		{
			if(i==1&&i>=l&&i<=r)
				ans++;
		}
		else if(y%i==0&&__gcd(i,y/i)==1)
		{
			if(i>=l&& (y/i)<=r )
				ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
