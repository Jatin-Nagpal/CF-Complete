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
#define mod 100000
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int mxx=100000,mxy=100000,mix=-100000,miy=-100000;
		f(i,0,n)
		{
			int x,y,a[4];
			cin>>x>>y>>a[0]>>a[1]>>a[2]>>a[3];
			if(a[0]==0)
				mix=max(mix,x);
			if(a[1]==0)
				mxy=min(mxy,y);
			if(a[2]==0)
				mxx=min(mxx,x);
			if(a[3]==0)
				miy=max(miy,y);
		}
		if(mxx>=mix&&mxy>=miy)
		{
			cout<<"1"<<" "<<mix<<" "<<miy<<'\n';
		}
		else
		{
			cout<<"0\n";
		}
	}
	
	return 0;
}