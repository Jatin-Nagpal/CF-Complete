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
int n,m,k;
set <pair <int,int> > se;
vector <pair <int,int> > gp[200005];
priority_queue <array <int,3> ,vector <array <int,3> >, greater <array <int,3> > > pq;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	f(i,0,m)
	{
		int x,y,w;
		cin>>x>>y>>w;
		pq.push({w,x,y});
	}
	int ans=0;
	f(i,0,k)
	{
		auto j=pq.top();
		ans=j[0];
		if(se.count({ min(j[1],j[2]) , max(j[1],j[2]) })==0)
		{
			se.insert({ min(j[1],j[2]),max(j[1],j[2]) });
			pq.pop();
			for(auto k: gp[j[1]])
			{
				if(se.count({   min(k.ff,j[2]),max(k.ff,j[2])   })==0)
				{
					pq.push({k.ss+j[0],k.ff,j[2]});
				}
			}
			for(auto k: gp[j[2]])
			{
				if(se.count({   min(k.ff,j[1]),max(k.ff,j[1])   })==0)
				{
					pq.push({k.ss+j[0],k.ff,j[1]});
				}
			}
			gp[j[1]].push_back({j[2],j[0]});
			gp[j[2]].push_back({j[1],j[0]});
		}
		else
		{
			i--;
			pq.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}