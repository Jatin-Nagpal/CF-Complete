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
int n,m;
vector <int> gp[300005];
map <pair <int,int> , int> mp;
set <pair <int,int> > se;
pair <int,int> edg[500005];
set <int> mt;
int vis[300005];
set <int > ans;
set <int> temp;
int dfs(int i)
{
	vis[i]=1;
	int ch=0;
	for(int j: gp[i])
	{
		if(vis[j]==1&&mt.count(j)==1)
		{
			ch++;
		}
	}
	if(ch==0)
	{
		mt.insert(i);
	}
	// for(int j: gp[i])
	// {
	// 	if(vis[j]==0)
	// 	{
	// 		dfs(j);
	// 	}
	// }
	return 0;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		mp.clear();
		mt.clear();
		se.clear();
		f(i,1,3*n+1)
		{
			gp[i].clear();
			vis[i]=0;
		}
		f(i,1,m+1)
		{
			int u,v;
			cin>>u>>v;
			edg[i]={u,v};
			if(u>v)
			{
				u=u^v;
				v=u^v;
				u=u^v;
			}
			gp[u].push_back(v);
			gp[v].push_back(u);
			mp[{u,v}]=i;
			se.insert({u,v});
		}
 
		set <pair <int,int> > srt;
		f(i,1,3*n+1)
		{
			srt.insert({gp[i].size(),i});
		}
		for(auto i: srt)
		{
			if(vis[i.ss]==0)
				dfs(i.ss);
		}
		if(mt.size()>=n)
		{
			int j=0;
			cout<<"IndSet\n";
			for(auto i: mt)
			{
				if(j==n)
					break;
				j++;
				cout<<i<<" ";
			}
			cout<<endl;
			continue;
		}
		else
		{
			ans.clear();
			temp.clear();
			f(i,1,m+1)
			{
				if(temp.count(edg[i].ff)==0&&temp.count(edg[i].ss)==0)
				{
					ans.insert(i);
					temp.insert(edg[i].ff);
					temp.insert(edg[i].ss);
				}
			}
			if(ans.size()>=n)
			{
				cout<<"Matching\n";
				int j=0;
				for(auto i: ans)
				{
					if(j==n)
						break;
					cout<<i<<" ";
					j++;
				}
				cout<<endl;
			}
			else
			{
				cout<<"Impossible\n";
			}
		}
	}
	
	return 0;
}
