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
int n;
string s;
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		vector <int> zero;
		cin>>n>>s;
		f(i,0,n)
		{
			if(s[i]=='1')
				zero.push_back(i);
		}
		if(zero.size()==0)
		{
			cout<<n<<'\n';
		}
		else
		{
			cout<<2*(n-min(n-1-zero[zero.size()-1],zero[0]))<<'\n';
		}
	}
	
	return 0;
}