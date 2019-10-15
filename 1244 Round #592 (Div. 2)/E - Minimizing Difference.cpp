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
int a[100005];
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	f(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	int ma=a[n-1],mi=a[0];
	for(int i=1;i<=n/2;i++)
	{
		if(k>=(a[i]-mi)*i)
		{
			k-=(a[i]-mi)*i;
			mi=a[i];
		}
		else
		{
			mi+=k/(i);
			break;
		}
		if(k>=((ma-a[n-i-1])*i))
		{
			k-=(ma-a[n-i-1])*i;
			ma=a[n-i-1];
		}
		else
		{
			ma-=k/i;
			break;
		}
	}
	cout<<max(ma-mi,0ll)<<'\n';
	return 0;
}
