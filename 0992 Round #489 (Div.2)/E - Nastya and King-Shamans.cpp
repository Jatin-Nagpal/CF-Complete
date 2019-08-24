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
int n,q;
int a[200005];
int bit[(1<<19)];
void update(int i,int delta)
{
	while(i<=n)
	{
		bit[i]+=delta;
		i+=i&-i;
	}
}
int susu(int i)
{
	int ret=0;
	while(i>0)
	{
		ret+=bit[i];
		i-=i&-i;
	}
	return ret;
}
int sum(int kit)
{
	// cout<<kit<<endl;
	int ret=n+1;
	int st=0,en=1ll<<18;
	// cout<<en<<endl;
	while(st+1<en)
	{
		int mid=(st+en)/2;
		// cout<<mid<<endl;
		if(mid>n)
		{
			en=mid;
		}
		else if(bit[mid]>=kit)
		{
			ret=min(mid,ret);
			en=mid;
		}
		else
		{
			kit-=bit[mid];
			st=mid;
		}
	}
	return ret;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	f(i,1,n+1)
	{
		cin>>a[i];
		update(i,a[i]);
	}
	update(n+1,1000000000000000000);
	a[n+1]=1000000000000000000;
	while(q--)
	{
		int p,x;
		cin>>p>>x;
		update(p,x-a[p]);
		a[p]=x;
		int ans=-1;
		if(a[1]==0)
		{
			cout<<"1\n";
			continue;
		}
		int val=a[1];
		// cout<<val<<endl;
		int valp=1;
		// f(i,1,4)
		// cout<<bit[i]<<" ";
		while(valp<=n&&ans==-1)
		{
			// cout<<val<<" "<<valp<<endl;
			int temp=sum(val*2);
			// cout<<temp<<endl;
			if(2*susu(temp-1)==susu(temp))
			{
				// cout<<"Yahan"<<endl;
				ans=temp;
			}
			valp=temp;
			val=susu(valp);
		}
		cout<<ans<<endl;
	}
	return 0;
}