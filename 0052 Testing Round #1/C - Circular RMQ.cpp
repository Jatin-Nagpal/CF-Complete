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
int b[1000005];
int c[1000005];
int add(int i,int j,int rngx,int rngy,int point,int value)
{
	if(rngx==rngy)
	{
		if(rngx>=i&&rngx<=j)
			b[point]+=value;
		return c[point]=b[point];
	}
	else if(i<=rngx&&j>=rngy)
	{
		b[point]+=value;
		return c[point]=c[point]+value;
	}
	else if(i>rngy||j<rngx)
	{
		return c[point];
	}
	else
	{
		int mi=(rngx+rngy)/2;
		// b[point]+=value;
		b[2*point]+=b[point];
		b[2*point+1]+=b[point];
		c[2*point]+=b[point];
		c[2*point+1]+=b[point];
		c[point]=min({add(i,j,rngx,mi,2*point,value),add(i,j,mi+1,rngy,2*point+1,value)});
		b[point]=0;
		return c[point];
	}
}
int query(int i,int j,int rngx,int rngy,int point)
{
	if(rngx==rngy)
	{
		if(rngx>=i&&rngx<=j)
			return c[point];
		return mod;
	}
	else if(i<=rngx&&j>=rngy)
		return c[point];
	else if(i>rngy||j<rngx)
	{
		return mod;
	}
	else
	{
		int mi=(rngx+rngy)/2;
		b[2*point]+=b[point];
		b[2*point+1]+=b[point];
		c[2*point]+=b[point];
		c[2*point+1]+=b[point];
		b[point]=0;
		return min(query(i,j,rngx,mi,2*point),query(i,j,mi+1,rngy,2*point+1));
		// cout<<val<<" "<<i<<" "<<j<<" "<<rngx<<" "<<rngy<<endl;
		// return c[point];
	}
}
int32_t main()
{
	scanf("%lld",&n);
	f(i,0,n)
	{
		scanf("%lld",&a[i]);
		add(i,i,0,n-1,1,a[i]);
	}
	int m;
	scanf("%lld",&m);
	while(m--)
	{
		char check;
		int st,en,v;
		scanf("%lld%lld",&st,&en);
		// cout<<st<<" "<<en<<endl;
		scanf("%c",&check);
		// cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
		// cout<<(int)(check)<<endl;
		// cout<<(int)(' ')<<endl;
		if(check==10)
		{
			if(st>en)
			{
				cout<<min(query(st,n-1,0,n-1,1), query(0,en,0,n-1,1) )<<'\n';
			}
			else
			{
				cout<<query(st,en,0,n-1,1)<<'\n';
			}
		}
		else
		{
			scanf("%lld",&v);
			if(st>en)
			{
				add(st,n-1,0,n-1,1,v);
				add(0,en,0,n-1,1,v);
			}
			else
			{
				add(st,en,0,n-1,1,v);
			}
		}
	}
	return 0;
}