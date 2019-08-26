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
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<(a[0]+a[1]+a[2])/2<<endl;
	}
	return 0;
}