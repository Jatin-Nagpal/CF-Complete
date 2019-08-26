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
 
int a[200005];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		vector <int> ans;
		int n,k;
		cin>>n>>k;
		f(i,1,n+1)
		{
			cin>>a[i];
		}
		int su=0;
		f(i,1,n+1)
		{
			su=su^(a[i]&1);
			if((su^(ans.size()%2))==1&&ans.size()!=k-1)
			{
				ans.push_back(i);
			}
		}
		ans.push_back(n);
			// for(int i: ans)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<'\n';
		if(ans.size()!=k)
			cout<<"NO\n";
		else if(k>1&&ans[k-2]==ans[k-1])
			cout<<"NO\n";
		else if((su^(k&1))==0)
		{
			cout<<"YES\n";
			for(int i: ans)
			{
				cout<<i<<" ";
			}
			cout<<'\n';
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return 0;
}