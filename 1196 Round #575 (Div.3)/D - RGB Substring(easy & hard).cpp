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
int dp[200005][4];
int n,k;
string s;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string b="RGB";
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>k>>s;
		int ans=n;
		f(i,0,n)
		{
			f(j,0,3)
			{
				dp[i+1][j]=dp[i][j];
				if(s[i]!=b[(i+j)%3])
				{
					dp[i+1][j]++;
				}
			}
		}
		f(i,k,n+1)
		{
			f(j,0,3)
			{
				// cout<<" "<<ans<<endl;
				ans=min(dp[i][j]-dp[i-k][j],ans);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
