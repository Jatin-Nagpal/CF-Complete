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
int n,k;
int ans[1000005];
int vis[2000005];
int vis1[1000005],vis2[1000005];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	ans[0]=n*(n+1)/2;
	if(ans[0]>k)
	{
		cout<<"-1\n";
		return 0;
	}
	int ma=ans[0];
	for(int i=1;i<=n/2;i++)
	{
		ans[i]=ans[i-1]+(n-2*i+1);
		if(ans[i]>=k)
		{
			int j=i-(ans[i-1]-k);
			f(k,1,i)
			{
				vis[(2*(n-k+1))]=1;
				// cout<<n-k-1<<endl;
			}
			if(vis[2*j]==1)
				vis[2*j-1]=1;
			else
				vis[2*j]=1;
			for(int k=i+1;k<=n;k++)
			{
				if(vis[2*k]==1)
					vis[2*k-1]=1;
				else
					vis[2*k]=1;
			}
			cout<<k<<'\n';
			vector <int> ans1,ans2;
			f(i,1,2*n+1)
			{
				if(vis[i]==1)
					ans1.push_back((i+1)/2);
				else
					ans2.push_back((i+1)/2);
			}
			set <int> se1,se2;
			f(i,0,n)
			{
				if(i>0&&(vis1[ans1[i]]==1||vis2[ans2[i]]))
				{
					ans1[i]=ans2[i]^ans1[i];
					ans2[i]=ans2[i]^ans1[i];
					ans1[i]=ans2[i]^ans1[i];
				}
				vis1[ans1[i]]=1;
				vis2[ans2[i]]=1;
			}
			for(int i: ans1)
				cout<<i<<" ";
			cout<<'\n';
			for(int i: ans2)
				cout<<i<<" ";
			cout<<'\n';
			return 0;
		}
		ma=max(ma,ans[i]);
	}
	
	cout<<ma<<'\n';
	vector <pair <int,int> > ans;
	f(i,1,n+1)
		ans.push_back({i,n-i+1});
	for(auto i: ans)
		cout<<i.ff<<" ";
	cout<<'\n';
	for(auto i: ans)
		cout<<i.ss<<" ";
	cout<<'\n';
	return 0;
}