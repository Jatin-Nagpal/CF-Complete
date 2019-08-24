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
int n,k,bn;
int a[200005];
vector <int> b;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bn=0;
	cin>>n>>k;
	f(i,0,n)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			b.push_back(a[i]);
			bn++;
		}
		else
		{
			if(b.size()>0&&b[bn-1]<0)
			{
				b[bn-1]--;
			}
			else
			{
				b.push_back(-1);
				bn++;
			}
 
		}
	}
	int ans=0;
	f(i,0,bn)
	{
		int pro=1,sum=0;
		f(j,i,bn)
		{
			if(b[j]<0)
			{
				sum+=-b[j];
				if( (pro>(sum+b[j])*k) && (pro<=sum*k) && pro%k==0 )
				{
					ans++;
				}
			}
			else
			{
				pro*=b[j];
				sum+=b[j];
				if(pro==sum*k)
					ans++;
				else if(pro>sum*k+k*200000)
					break;
			}
		}
		if(b[i]<0)
		{
			b[i]++;
			if(b[i]<0)
				i--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
