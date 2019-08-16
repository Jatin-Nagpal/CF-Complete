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
int n;
int a[200005];
int b[200005];
int c[200005][3];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	f(i,1,n+1)
	{
		b[i]=-1;
		cin>>a[i];
	}
	int q;
	cin>>q;
	f(tc,0,q)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			c[tc][0]=1;
			int p,x;
			cin>>p>>x;
			c[tc][1]=p;
			c[tc][2]=x;
		}
		else
		{
			int x;
			cin>>x;
			c[tc][0]=2;
			c[tc][1]=x;
		}
	}
	int mi=0;
	for(int i=q-1;i>=0;i--)
	{
		if(c[i][0]==1)
		{
			if(b[c[i][1]]==-1)
			{
				// cout<<c[i][1]<<endl;
				b[c[i][1]]=max(c[i][2],mi);
			}
		}
		else
		{
			mi=max(mi,c[i][1]);
		}
	}
	f(i,1,n+1)
	{
		if(b[i]==-1)
		{
			b[i]=max(mi,a[i]);
		}
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}
