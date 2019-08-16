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
 
int a[400005];
vector <pair <int,int> > ve;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,l;
	cin>>n>>l;
	l*=8;
	f(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	f(i,0,n)
	{
		if(ve.size()>0&&ve[ve.size()-1].ff==a[i])
		{
			ve[ve.size()-1].ss++;
		}
		else
		{
			ve.push_back({a[i],1});
		}
	}
	int kl=l/n;
	if(kl>=32)
	{
		cout<<"0"<<endl;
		return 0;
	}
	// cout<<(1ll<<15)<<endl;
	kl=1ll<<kl;
	// cout<<kl<<endl;
	if(kl>=ve.size())
	{
		cout<<"0"<<endl;
		return 0;
	}
	int su=0;
	int ans=n;
	f(i,0,kl)
	{
		su+=ve[i].ss;
	}
	ans=min(ans,n-su);
	// cout<<ans<<endl;
	f(i,kl,ve.size())
	{
		su+=ve[i].ss;
		su-=ve[i-kl].ss;
		ans=min(ans,n-su);
	}
	cout<<ans<<endl;
	return 0;
}