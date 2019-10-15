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
#define mod 1000000000000000000
vector <int> gp[100005];
int c[3][100005];
vector <int> one;
vector <int> arr;
int anss[100005];
int dfs(int i,int par)
{
	arr.push_back(i);
	for(int j: gp[i])
	{
		if(j!=par)
			dfs(j,i);
	}
	return 0;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	f(i,0,3)
		f(j,1,n+1)
			cin>>c[i][j];
	f(i,0,n-1)
	{
		int u,v;
		cin>>u>>v;
		gp[u].push_back(v);
		gp[v].push_back(u);
	}
	f(i,1,n+1)
	{
		if(gp[i].size()>2)
		{
			cout<<"-1\n";
			return 0;
		}
		else if(gp[i].size()==1)
			one.push_back(i);
	}
	dfs(one[0],0);
	int ans=mod;
	array <int,3> comb={0,0,0};
	f(i,0,3)
	{
		f(j,0,3)
		{
			f(k,0,3)
			{
				if(i!=j&&j!=k&&i!=k)
				{
					int temp=0;
					f(l,0,n)
					{
						if(l%3==0)
							temp+=c[i][arr[l]];
						else if(l%3==1)
							temp+=c[j][arr[l]];
						else
							temp+=c[k][arr[l]];
					}
					if(temp<ans)
					{
						ans=temp;
						comb={i,j,k};
					}
				}
			}
		}
	}
	f(l,0,n)
	{
		anss[arr[l]]=comb[l%3];
	}
	cout<<ans<<'\n';
	f(i,1,n+1)
	{
		cout<<anss[i]+1<<" ";
	}
	cout<<'\n';
	return 0;
}