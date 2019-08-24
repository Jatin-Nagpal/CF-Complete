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
 
int power(int x,int y,int m) 
{
	if(y == 0) 
		return 1; 
	int p = power(x, y/2, m) % m; 
	p = (p * p) % m; 
	return (y%2 == 0)? p : (x * p) % m; 
}
int modinv(int a, int m) 
{ 
	return power(a, m-2, m);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,k;
	cin>>x>>k;
	if(x==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	x=x%mod;
	x=x*2;
	int po=power(2,k%(mod-1),mod);
	x=(po*x-(po-1)+mod)%mod;
	cout<<x<<endl;
	return 0;
}