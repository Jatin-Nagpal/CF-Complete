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
 
int n,m,ans;
string s[1005];
int sx[1005],sy[1005];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	f(i,0,n)
		cin>>s[i];
	f(i,0,n)
		f(j,0,m)
			if(s[i][j]=='*')
			{
				sx[i]++;
				sy[j]++;
			}
	f(i,0,n)
		f(j,0,m)
			if(s[i][j]=='*')
			{
				ans+=(sx[i]-1)*(sy[j]-1);
			}
	cout<<ans<<endl;
	return 0;
}