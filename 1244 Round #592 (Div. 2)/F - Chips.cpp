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
 
int n,k;
string s;
int col[400005];
int ar1[400005],ar2[400005];
int arc1[400005],arc2[400005];
int dang[400005];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>s;
	f(i,0,n)
	{
		if(s[i]=='B')
		{
			col[i]=1;
			col[i+n]=1;
		}
	}
	int in=col[0];
	int flag=0;
	f(i,1,n)
	{
		if(in!=(col[i]^(i&1)))
			flag=1;
	}
	if(flag==0&&n%2==0)
	{
		f(i,0,n)
		{
			if(k%2==1)
				col[i]^=1;
			if(col[i]==1)
				cout<<"B";
			else
				cout<<"W";
		}
		cout<<'\n';
	}
	else
	{
		// cout<<"Yaha\n";
		f(i,1,2*n-1)
		{
			if(col[i]==col[i+1]||col[i]==col[i-1])
				dang[i]=1;
		}
		f(i,1,2*n)
		{
			if(dang[i]==1)
			{
				ar1[i]=0;
				arc1[i]=col[i];
			}
			else
			{
				ar1[i]=ar1[i-1]+1;
				arc1[i]=arc1[i-1];
			}
		}
		for(int i=2*n-2;i>=0;i--)
		{
			if(dang[i]==1)
			{
				ar2[i]=0;
				arc2[i]=col[i];
			}
			else
			{
				ar2[i]=ar2[i+1]+1;
				arc2[i]=arc2[i+1];
			}
		}
		f(i,0,n)
		{
			if(dang[i]!=1)
			{
				// cout<<i<<endl;
				if(ar2[i]<ar1[i+n])
				{
					if(k>=ar2[i])
						col[i]=arc2[i];
					else if(k%2==1)
						col[i]^=1;
				}
				else
				{
					if(k>=ar1[i+n])
						col[i]=arc1[i+n];
					else if(k%2==1)
						col[i]^=1;
				}
			}
			if(col[i]==1)
				cout<<"B";
			else
				cout<<"W";
		}
	}
	return 0;
}
