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
int a[1000006];
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int arr[4]={0,0,0,0};
	cin>>n;
	f(i,0,n)
	{
		cin>>a[i];
		arr[a[i]]++;
	}
	cout<<n-max({arr[1],arr[2],arr[3]})<<endl;
	return 0;
}