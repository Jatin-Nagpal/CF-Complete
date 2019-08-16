#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define MP make_pair
#define PB push_back
// #define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
#define mod 1000000007
int a[51][51];
string s[51];
int n,ans;
int dp[51][51][51][51];
int dp2[51][51];
inline int sum(int stx,int sty,int enx,int eny)
{
	return dp2[enx][eny] -dp2[stx-1][eny] -dp2[enx][sty-1] +dp2[stx-1][sty-1];
}
int dfs(int stx,int sty,int enx,int eny)
{
	// cout<<stx<<" "<<sty<<" "<<enx<<" "<<eny<<'\n';
	int &an=dp[stx][sty][enx][eny];
	if(an!=-1)
		return an;
	if(  dp2[enx][eny] -dp2[stx-1][eny] -dp2[enx][sty-1] +dp2[stx-1][sty-1] ==0)
		return an=0;
	if(stx>enx||sty>eny)
		return an=0;
	if(stx==enx&&sty==eny)
		return an=a[stx][sty];
	if(sum(stx,sty,stx,eny)==0)
		return an=dfs(stx+1,sty,enx,eny);
	if(sum(stx,sty,enx,sty)==0)
		return an=dfs(stx,sty+1,enx,eny);
	if(sum(enx,sty,enx,eny)==0)
		return an=dfs(stx,sty,enx-1,eny);
	if(sum(stx,eny,enx,eny)==0)
		return an=dfs(stx,sty,enx,eny-1);
	int ret=min( max(enx-stx+1,eny-sty+1),sum(stx,sty,enx,eny));
	int tmp=0;
	f(i,stx,enx)
	{
		ret=min(ret,dfs(stx,sty,i,eny) +dfs(i+1,sty,enx,eny)  );
	}
	f(i,sty,eny)
	{
		ret=min(ret,dfs(stx,sty,enx,i) +dfs(stx,i+1,enx,eny)  );
	}
	return an=ret;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	ans=n;
	f(i,0,51)
		f(j,0,51)
			f(k,0,51)
				f(l,0,51)
					dp[i][j][k][l]=-1;
	f(i,0,n)
		cin>>s[i];
	f(i,1,n+1)
	{
		f(j,1,n+1)
		{
			if(s[i-1][j-1]=='#')
				a[i][j]=1;
		}
	}
	f(i,1,n+1)
	{
		f(j,1,n+1)
		{
			dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
			if(a[i][j]==1)
				dp2[i][j]++;
		}
 
	}
	cout<<dfs(1,1,n,n)<<endl;
	return 0;
}