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
int n,x,y;
int a[100005];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>x>>y;
	f(i,1,n+1)
		cin>>a[i];
	f(i,1,n+1)
	{
		int ch=0;
		f(j,1,x+1)
		{
			if(i-j<=0||a[i-j]>a[i])
			{
				ch++;
			}
		}
		f(j,1,y+1)
		{
			if(i+j>n||a[i+j]>a[i])
				ch++;
		}
		if(ch==x+y)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}